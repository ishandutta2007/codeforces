#include <bits/stdc++.h>

using namespace std;
#define maxn 500010
#define pii pair<int, int>
#define prev ONE_OCCURRENCE

int last[maxn]; //stores the last index i have seen
int prev[maxn];
int nums[maxn];
int n, q;
const int inf = 1234567890;

struct node {
	node *left, *right;
	pii val;

	node(node *ll, node *rr, pii vp) :
		left(ll),  right(rr), val(vp) {}

	node *update(int ss, int se, int spot, int bef);

};

node *null = new node(NULL, NULL, pii(inf, inf));

node * node::update(int ss, int se, int spot, int bef) {
	if (spot < ss || spot > se) return this;
	if (ss == se) {
		return new node(null, null, pii(bef, nums[spot]));
	}
	int mid = (ss+se)/2;
	node *lc = this->left;
	node *rc = this->right;
	if (spot <= mid) {
		lc = this->left->update(ss, mid, spot, bef);
	}
	else {
		rc = this->right->update(mid+1, se, spot, bef);
	}
	return new node(lc, rc,
		 min(lc->val, rc->val));
	
}

node *roots[maxn];

pii query(node *cur, int qs, int qe, int ss, int se) {
	if (qs > qe || ss > se || qs > se || qe < ss) 
		return null->val;
	if (qs <= ss && se <= qe) return cur->val;
	int mid = (ss+se)/2;
	return min(query(cur->left, qs, qe, ss, mid),
		query(cur->right, qs, qe, mid+1, se));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	null->left = null; //just sets up the null node for p-seg
	null->right = null;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		prev[i] = last[nums[i]];
		last[nums[i]] = i;
	}
	// cout << "made it down to here" << endl;

	roots[0] = null;
	//do all of the segtree creations here
	for (int i = 1; i <= n; i++) {
		roots[i] = roots[i-1];
		if (prev[i] != 0) {
			//have to change something
			roots[i]= 
				roots[i]->update(1, n, prev[i], inf);
		}
		roots[i] = 
			roots[i]->update(1, n, i, prev[i]);
	}

	// cout << "past all of the updates" << endl;

	cin >> q;
	int l, r;
	while (q--) {
		cin >> l >> r;
		pii cur= query(roots[r], l, r, 1, n);
		if (cur.first >= l) { //the thing before this is bad
			cout << 0 << '\n';
		}
		else {
			cout << cur.second << '\n';
		}
	}
	cout.flush();
}