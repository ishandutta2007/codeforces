#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

struct Node {
	Node* a[26];
	Node() {
		for (int i = 0; i < 26; ++i) {
			a[i] = NULL;
		}
	}
};

void add_string(Node* root, string s) {
	Node* current = root;
	for (int i = 0; i < s.size(); ++i) {
		if (current->a[s[i] - 'a'] == NULL) {
			current->a[s[i] - 'a'] = new Node();
		}
		current = current->a[s[i] - 'a'];
	}
}

int solve(Node* root) {
	for (int i = 0; i < 26; ++i) {
		if (root->a[i] != NULL && solve(root->a[i]) == 2) {
			return 1;
		}
	}
	return 2;
}

int canLose(Node* root) {
	bool not_empty = false;
	for (int i = 0; i < 26; ++i) {
		if (root->a[i] != NULL) {
			not_empty = true;
		}
		if (root->a[i] != NULL && canLose(root->a[i]) == 1) {
			return 2;
		}
	}
	return (not_empty ? 1 : 2);
}

int n, k;
Node* root;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> k;
	root = new Node();
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		add_string(root, s);
	}

	int winner = solve(root);
	int cl = canLose(root);

	if (winner == 2) {
		cout << "Second" << endl;
		return 0;
	}
	
	if (cl == 2) {
		cout << "First" << endl;
		return 0;
	}

	if (k % 2 == 1) {
		cout << "First" << endl;
		return 0;
	}
	cout << "Second" << endl;

	return 0;
}