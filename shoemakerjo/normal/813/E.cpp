#include <bits/stdc++.h>

using namespace std;

int n, k;

vector<vector<int>> sz;


struct node {
	int count;
	node *left;
	node *right;
	node(int cc, node *ll, node *rr) :
		count(cc), left(ll), right(rr) {}

	node *insert(int l, int r, int spot);

};

node *null = new node(0, NULL, NULL);

node * node::insert(int l, int r, int spot) {
	// cout << "l  " << l << "  " << r << endl;
	if (l <= spot && spot <= r) {
		if (l == r) {
			return new node(this->count+1, null, null);
		}
		int mid = (l+r)/2;
		return new node(this->count+1, this->left->insert(l, mid, spot),
			this->right->insert(mid+1, r, spot));
	}
	return this;
}

int query(node *cur, int qs, int qe, int ss, int se) {
	if (qs > qe || ss > se || qs > se || qe < ss) return 0;
	if (qs <= ss && se <= qe) {
		return cur->count;
	}
	int mid = (ss+se)/2;
	return query(cur->left, qs, qe, ss, mid) + 
		query(cur->right, qs, qe, mid+1, se);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	null->left = null;
	null->right = null;
	cin >> n >> k;
	for (int i = 0; i <= 100000; i++) {
		vector<int> b;
		sz.push_back(b);
	}
	int il[n+1];
	for (int i = 0; i <= n; i++) {
		il[i] = -1;
	}
	int cur;
	for (int i = 1; i <= n; i++) {
		cin >> cur;
		sz[cur].push_back(i);
	}
	// cout << "HERE" << endl;
	for (int i = 0; i <= 100000; i++) {
		for (int j = 0; j+k < sz[i].size(); j++) {
			il[sz[i][j+k]] = sz[i][j];
		}
	}

	node *roots[n+1];
	roots[0] = null;
	for (int i = 1; i <= n; i++) {
		roots[i] = roots[i-1];
		if (il[i] != -1) {
			roots[i] = roots[i]->insert(1, n, il[i]);
		}
	}
	int q;
	cin >> q;
	int x, y;
	int l, r;
	int last = 0;
	for (int i = 0; i < q; i++) {
		cin >> x >> y;
		l = ((x+last)%n)+1;
		r = ((y+last)%n)+1;
		if (l > r) {
			int t = l;
			l = r;
			r = t;
		}
		int ans = r-l+1;
		ans -= query(roots[r], l, n, 1, n);
		cout << ans << '\n';
		last = ans;
	}
	cin >> last;
}