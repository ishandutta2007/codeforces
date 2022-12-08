#include <bits/stdc++.h>

using namespace std;
#define tii tuple<int, int, int, int, int>
#define maxn 100001
int n, m;
vector<vector<int>> child;
int par[maxn][19];
int depth[maxn];
int spot[maxn];

struct node {
	int count;
	node *left, *right;

	node(int count, node *left, node *right) :
		count(count), left(left), right(right) {}
	node *insert(int l, int r, int val);
};

node *null = new node(0, NULL, NULL);
node *roots[maxn];

node * node::insert(int l, int r, int val) {
	if (l <= val && val <= r) {
		if (l == r) {
			return new node(this->count + 1, null, null);
		}
		int mid = (l+r)/2;
		return new node(this->count+1,
			this->left->insert(l, mid, val),
			this->right->insert(mid+1, r, val));
	}
	return this;
}

void dfs(int u, int p) {
	depth[u] = depth[p]+1;
	if (spot[u]==-1) {
		roots[u] = roots[p];
	}
	else {
		roots[u] = roots[p]->insert(1, m, spot[u]);
	}
	for (int i = 0; i < child[u].size(); i++) {
		dfs(child[u][i], u);
	}
}

int query(node *a, int ss, int se, int qs, int qe) {
	if (qs > qe || ss > se || qe < ss || qs > se) {
		return 0;
	}
	if (qs <= ss && se <= qe) {
		return a->count;
	}
	int mid = (ss+se)/2;
	return query(a->left, ss, mid, qs, qe) +
		query(a->right, mid+1, se, qs, qe);
}

int lca(int u, int v) {
	if (depth[u] < depth[v]) {
		return lca(v, u);
	}
	int diff = depth[u]-depth[v];
	// cout << "d: " << diff << endl;
	// cout << "u:  " << u << " " << v << endl;
	for (int i = 0;  i < 19; i++) {
		if (diff & (1 << i)) {
			u = par[u][i];
		}
	}
	// cout << "u: " << u << " " << v << endl;
	if (u == v) return u;
	for (int i = 18; i >= 0; i--) {
		if (par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	}
	// cout << "u: " << u << " "  << v << endl;
	u = par[u][0];
	return u;
}

int main() {
	null->left = null;
	null->right = null;
	depth[0] = -1;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		vector<int> b;
		child.push_back(b);
	}
	int sr = -1;
	for (int i = 1; i < 19; i++) {
		for (int j = 0; j <= n; j++) {
			par[j][i] = 0;
		}
	}
	par[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> par[i][0];
		if (par[i][0] != 0) child[par[i][0]].push_back(i);
		if (par[i][0] == 0) {
			sr = i;
			// par[i][0] = -1;
		}
	}
	for (int i = 1; i < 19; i++) {
		for (int j = 1; j <= n; j++) {
			if (par[j][i-1] != 0) {
				par[j][i] = par[par[j][i-1]][i-1];
			}
		}
	}
	cin >>  m;
	int type;
	int c, a, b, k, y;
	for (int i = 0; i <= n; i++){
		spot[i] = -1;
	}
	vector<tii> queries;
	for (int i = 1; i <= m; i++) {
		cin >>  type;
		if (type == 1) {
			cin >>  c;
			spot[c] = i;
		}
		else {
			cin >> a >> b >> k >> y;
			queries.push_back(tii(i, a, b, k, y));
		}
	}
	roots[0] = null;
	depth[sr] = 1;
	// cout << "sr: " << sr << endl;
	dfs(sr, 0);
	// cout << "here" << endl;
	for (int q = 0; q < queries.size(); q++) {
		int tend = get<0>(queries[q]);
		a = get<1>(queries[q]);
		b = get<2>(queries[q]);
		k = get<3>(queries[q]);
		y = get<4>(queries[q]);
		int lc = lca(a,b);
		// cout << "lc " << lc << endl;
		int numok = 0;
		int inb = b;
		int ina = a;
		int num = query(roots[par[a][0]],
			1, m, y+1, tend);
		int qtot = num;
		int qlc = 0;
		if (par[lc][0] != 0) {
			qlc =  query(roots[par[lc][0]],
				1, m, y+1, tend);
			num -= qlc;
			// cout << "qlc:  " << qlc << endl;
		}
		numok = depth[a]-depth[lc]-num;
		if (b== lc) {
			if (spot[lc] <= y || spot[lc] > tend) numok--;
		}	 
		
		// cout << "num:  " << numok << " " << k << endl;
		if (numok >= k) {
			for (int i = 18; i >= 0; i--) {
				if (par[a][i] == -1) {
					continue;
				}
				if (depth[par[a][i]] <= depth[lc]) {
					continue;
				}
				if (depth[ina]-depth[par[a][i]]-(qtot-query(roots[par[par[a][i]][0]],
					1, m, y+1, tend)) < k) {
					a = par[a][i];
				}
			}
			a = par[a][0];
			k = -1;
			if (a == b) cout << -1 << '\n';
			else cout << a << '\n';
		}
		else {
			// cout << "-->  ";
			qlc =  query(roots[lc],
				1, m, y+1, tend);
			k-=numok;
			qtot = query(roots[par[b][0]], 
				1, m, y+1, tend);
			int ct = depth[b]-depth[lc]-1-(qtot-qlc); //numgood
			// cout << "ct: " << ct << endl;
			if (ct < k) {
				cout << -1 << '\n';
			}
			else {
				for (int i = 18; i >= 0; i--) {
					if (ct-(depth[inb]-depth[par[b][i]]-1-(qtot-query(roots[par[par[b][i]][0]],
						1, m, y+1, tend))) > k) {
						b = par[b][i];
					}
				}
				b = par[b][0];
				if (b == inb) cout << -1 << '\n';
				else cout << b << '\n';
			}
		}	
	}
	// cin >> n;
	
}