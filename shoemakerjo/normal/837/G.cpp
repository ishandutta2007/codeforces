#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int upbd = 300000;

struct node {
	node *left;
	node *right;
	ll sum;

	node(node *le, node *ri, ll su) :
		left(le), right(ri), sum(su) {}

	node * insert(int spot, ll val, int ss, int se);
};

node *null = new node(NULL, NULL, 0);

node * node::insert(int spot, ll val, int ss, int se) {
	if (spot == ss && spot == se) {
		return new node(null, null, this->sum+val);
	}
	int mid = (ss+se)/2;
	if (spot <= mid) {
		return new node(this->left->insert(spot, val, ss, mid),
			this->right, this->sum + val);
	}
	else {
		return new node(this->left, 
			this->right->insert(spot, val, mid+1, se),
			this->sum + val);
	}
}

ll query(int qs, int qe, int ss, int se, node *cur) {
	if (qs <= ss && se <= qe) {
		return cur->sum;
	}
	if (qs > qe || ss > se || qs > se || qe < ss) {
		return 0LL;
	}
	int mid = (ss+se)/2;
	return query(qs, qe, ss, mid, cur->left) +
		query(qs, qe, mid+1, se, cur->right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	null->left = null;
	null->right = null;

	int n;
	cin >> n;

	node *rb[n+1];
	rb[0] = null;
	node *ra[n+1];
	ra[0] = null;

	int x1, x2, y1, a, b, y2;

	for (int i = 1; i <= n; i++) {
		cin >> x1 >> x2 >> y1 >> a >> b >> y2;
		rb[i] = rb[i-1];
		ra[i] = ra[i-1];
		ra[i] = ra[i]->insert(x1+1, a, 0, upbd);
		ra[i] = ra[i]->insert(x2+1, -a, 0, upbd);

		rb[i] = rb[i]->insert(0, y1, 0, upbd);
		rb[i] = rb[i]->insert(x1+1, b-y1, 0, upbd);
		rb[i] = rb[i]->insert(x2+1, y2-b, 0, upbd);
		// cout << "i   " << i << "  " << rb[i]->sum << endl;
		// cout << "         " << query(0, 2, 0, upbd, rb[i]) << endl;
	}

	int m;
	cin >> m;
	int l, r, x;
	ll last = 0LL;
	for (int i = 0; i < m; i++) {
		cin >> l >> r >> x;
		x = (x+last)%1000000000;
		ll as = query(0, min(x, upbd), 0, upbd, ra[r]);
		// cout << "here   " << as << endl;
		as -= query(0, min(x, upbd), 0, upbd, ra[l-1]);
		ll bs = query(0, min(x, upbd), 0, upbd, rb[r]);
		bs -= query(0, min(x, upbd), 0, upbd, rb[l-1]);
		last = x*as + bs;
		cout << last << endl;
	}
	cin >> m;

}