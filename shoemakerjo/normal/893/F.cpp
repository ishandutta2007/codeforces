#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
#define endl '\n'

int n, r;
vector<vector<int>> adj;
int costs[maxn];
int x, y, k;
vector<int> nlist;
int bil;
vector<vector<int>> atd;
int starti[maxn];
int endi[maxn];
int depths[maxn];

struct node {

	node *left;
	node *right;
	int val;
	node(node *le, node *ri, int va) :
		left(le), right(ri), val(va) {}

	node * insert(int l, int r, int num, int spot);

};

node *null = new node(NULL, NULL, 0);
node *roots[maxn];

node * node::insert(int l, int r, int num, int spot) {
	// cout << "-->  " << l << "  " << r << endl;
	if (spot >= l && spot <= r) {
		if (l == r) {
			return new node(null, null, min(this->val, num));
		}
		int mid = (l+r)/2;
		return new node(this->left->insert(l, mid, num, spot),
			this->right->insert(mid+1, r, num, spot),
			min(this->val, num));
	}
	return this;

}

void euler(int u, int depth, int par) {
	depths[u] = depth;
	atd[depth].push_back(u);
	nlist.push_back(u);
	starti[u] = nlist.size()-1;

	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != par) {
			euler(v, depth+1, u);
		}
	}
	endi[u] = nlist.size()-1;


}

int qu(node *cur, int qs, int qe, int ss, int se) {
	if (qs <= ss && se <= qe) {
		return cur->val;
	}
	if (qs > qe || ss > se || qs > se || qe < ss) {
		return bil;
	}
	int mid = (ss+se)/2;
	return min(qu(cur->left, qs, qe, ss, mid),
		qu(cur->right, qs, qe, mid+1, se));
}

int query(int maxd, int low, int high) {
	maxd = min(maxd, n);
	return qu(roots[maxd], low, high, 0, n-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bil = 2000000000;
	null->right = null;
	null->left = null;
	null->val = bil;

	cin >> n >> r;
	for (int i = 0; i <= n; i++) {
		vector<int> bl;
		vector<int> b2;
		adj.push_back(bl);
		atd.push_back(b2);
	}
	for (int i = 1; i <= n; i++) {
		cin >> costs[i];
	}
	for (int i = 0; i < n-1; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	euler(r, 1, -1);
	roots[0] = null;
	for (int i = 1; i <= n; i++) {
		// cout << "i " << i << endl;
		roots[i] = roots[i-1];
		for (int j = 0; j < atd[i].size(); j++) {
			int cur = atd[i][j];
			// cout << "   " << cur << endl;
			roots[i] = roots[i]->insert(0, n-1, costs[cur], starti[cur]);
		}
	}

	int m;
	cin >> m;
	int p, q;
	int last = 0;
	for (int i = 0; i < m; i++) {
		cin >> p >> q;
		x = ((p+last)%n)  + 1;
		k = (q+last)%n;
		// cout << "query values  " << x << "  " << k << endl;
		int ans = query(depths[x] + k, starti[x], endi[x]);
		cout << ans << endl;
		last = ans;
	}
	// fflush(stdout);
	cin >> m;

}