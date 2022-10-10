#include <bits/stdc++.h>
using namespace std;

struct node {
	int l, r, val;
	node *left, *right;

	node(int l, int r, vector<int> &v) : l(l), r(r) {
		if(l == r)
			val = v[l];
		else {
			int m = (l + r)/2;
			left = new node(l, m, v);
			right = new node(m + 1, r, v);
			val = __gcd(left->val, right->val);
		}
	}

	void upd(int p, int v) {
		if(r < p || p < l)
			return;
		if(l == r) { val = v; return; }
		left->upd(p, v);
		right->upd(p, v);
		val = __gcd(left->val, right->val);
	}

	int cnt(int rl, int rr, int x) {
		if(rr < l || r < rl) return 0;
		if(rl <= l && r <= rr) {
			if(val % x == 0)
				return 0;
			if(l == r)
				return 1;
			int gl = left->val % x, gr = right->val % x;
			if(gl && gr)
				return 2;
			if(gl)
				return left->cnt(rl, rr, x);
			return right->cnt(rl, rr, x);
		}
		return left->cnt(rl, rr, x) + right->cnt(rl, rr, x);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	node tree(1, n, v);
	int q;
	cin >> q;
	while(q--) {
		int t;
		cin >> t;
		if(t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			cout << (tree.cnt(l, r, x) <= 1 ? "YES\n" : "NO\n");
		}
		else {
			int p, v;
			cin >> p >> v;
			tree.upd(p, v);
		}
	}
}