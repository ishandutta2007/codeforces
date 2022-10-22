#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct TNode {
	int L, R;
	TNode *left, *right;
	int sum;
};

TNode *new_node(int L, int R) {
	return new TNode({L, R, nullptr, nullptr, 0});
}

int safe_sum(TNode *root) {
	return (root ? root->sum : 0);
}

void relax(TNode *root) {
	if (!root) return;
	root->sum = safe_sum(root->left) + safe_sum(root->right);
}

void add(TNode *root, int pos) {
	if (root->L > pos || root->R <= pos) {
		return;
	}
	if (root->R - root->L == 1) {
		root->sum = 1;
		return;
	}
	int M = (root->L + root->R) / 2;
	if (!root->left) {
		root->left = new_node(root->L, M);
	}
	if (!root->right) {
		root->right = new_node(M, root->R);
	}
	add(root->left, pos);
	add(root->right, pos);
	relax(root);
}

int calc(TNode *root, int L, int R) {
	if (!root || L >= root->R || root->L >= R) {
		return 0;
	}
	if (L <= root->L && root->R <= R) {
		return root->sum;
	}
	return calc(root->left, L, R) + calc(root->right, L, R);
}


int main() {
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	TNode *root = new_node(0, 1e9 + 7);
	int n;
	cin >> n;
	vector <pair <int, int> > a(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = {y, x};
	}
	ll res = 0;
	sort(a.rbegin(), a.rend());
	vector <ll> at;
	for (int i = 0; i < n; i++) {
		int y = a[i].first, x = a[i].second;
		at.push_back(x);
		if (i < n - 1 && a[i + 1].first == y) {
			continue;
		}
		sort(at.begin(), at.end());
		for (ll i = 0; i < at.size() - 1; i++) {
			ll sz = calc(root, at[i] + 1, at[i + 1]);
			res -= sz * (sz + 1) / 2;
		}
		ll sz = calc(root, 0, at[0]);
		res -= sz * (sz + 1) / 2;
		sz = calc(root, at.back() + 1, 1e9 + 7);
		res -= sz * (sz + 1) / 2;
		for (int i = 0; i < at.size(); i++) {
			add(root, at[i]);
		}
		sz = calc(root, 0, 1e9 + 7);
		res += sz * (sz + 1) / 2;
		//cout << res << "\n";
		at.clear();
	}
	cout << res << "\n";
}