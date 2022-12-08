#include <bits/stdc++.h>

using namespace std;
#define maxn 100002
int n;

struct node {
	int count;
	node *left, *right;
	node(int count, node *left, node *right) :
		count(count), left(left), right(right) {}
	node *insert(int l, int r, int val);
	node *delnode(int l, int r, int val);
};
node *null = new node(0, NULL, NULL);
node *roots[maxn];
node * node::insert(int l, int r, int val) {
	if (l <= val && val <= r) {
		if (l == r) {
			return new node(this->count+1, null, null);
		}
		int mid = (l+r)/2;
		return new node(this->count+1, this->left->insert(l, mid, val),
			this->right->insert(mid+1, r, val));
	}
	return this;
}
node * node::delnode(int l, int r, int val) {
	if (l <= val && val <= r) {
		if (l == r) {
			return new node(this->count-1, null, null);
		}
		int mid = (l+r)/2;
		return new node(this->count-1, this->left->delnode(l, mid, val),
			this->right->delnode(mid+1, r, val));
	}
	return this;
}

int query(node *a, int l, int r, int num) {
	if (l == r) {
		// if (a->count == num) return l;
		// else return n+2;
		return l;
	}
	int mid = (l+r)/2;
	if (a->left->count >= num) {
		return query(a->left, l, mid, num);
	}
	return query(a->right, mid+1, r, num-a->left->count);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	null->right = null;
	null->left = null;
	cin >> n;
	roots[n+1] = null;
	map<int, int> prev;
	int nums[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	for (int i = n; i >= 1; i--) {
		node *root = roots[i+1];
		if (prev.count(nums[i])) {
			root = root->delnode(1, n+2, prev[nums[i]]);
		}
		prev[nums[i]] = i;
		root = root->insert(1, n+2, prev[nums[i]]);
		roots[i] = root;
	}
	for (int qu = 1; qu <= n; qu++) {
		int ans = 0;
		int cstart = 1;
		int cend;
		while (cstart <= n) {
			// cout << "cs " << cstart << endl;
			ans++;
			cend = query(roots[cstart], 1, n+2, qu+1);
			cend--;
			cstart = cend+1;
		}
		if (qu > 1) cout << " ";
		cout << ans;
	}
	cout << endl;
	// cin >> n;
}