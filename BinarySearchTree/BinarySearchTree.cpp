#include "BinarySearchTree.h"
#include <iostream> 
using namespace std;

BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

BstNode* InsertNode(BstNode *root, int data) {
	if (root == NULL) {
		root = GetNewNode(data);
	}
	else if (data <= root->data) {
		root->left = InsertNode(root->left, data);
	}
	else if (data > root->data) {
		root->right = InsertNode(root->right, data);
	}
	

	return root;
}

void DisplayPrefix(BstNode* root) {
	if (root == NULL)
		return;
	cout << root->data << " ";
	DisplayPrefix(root->left);	
	DisplayPrefix(root->right);
}

void DisplayInfix(BstNode* root) {
	if (root == NULL)
		return;
	DisplayInfix(root->left);
	cout << root->data<<" ";
	DisplayInfix(root->right);
}

void DisplayPostfix(BstNode* root) {
	if (root == NULL)
		return;
	DisplayPostfix(root->left);
	DisplayPostfix(root->right);
	cout << root->data << " ";
}

bool Search(BstNode *root, int num) {
	if (root == NULL) {
		return false;
	}
	else if (root->data == num) {
		return true;
	}
	else if (num < root->data) {
		 Search(root->left, num);
	}
	else {
		 Search(root->right, num);
	}
}
int main() {
	BstNode* root = NULL;
	int num;
	root = InsertNode(root, 15);
	root = InsertNode(root, 10);
	root = InsertNode(root, 20);
	root = InsertNode(root, 25);
	root = InsertNode(root, 8);
	root = InsertNode(root, 12);

	DisplayPrefix(root);
	cout << endl;
	DisplayInfix(root);
	cout << endl;
	DisplayPostfix(root);
	cout << "\nEnter number to search in the tree: ";
	cin>>num;
	
	if (Search(root, num) == true) {
		cout << endl << num << " is in the tree";
	}
	else {
		cout << endl << num << " is not the tree";
	}



	_getch();
	return 0;
}