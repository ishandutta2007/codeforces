#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 100010

int n, q;
int par[18][maxn];
ll orig[maxn];
ll seg[maxn*4];
ll lazy[maxn*4];
vector<int> flat;
int st[maxn];
int en[maxn];
int dep[maxn];
vector<vector<int>> adj(maxn);
int r;
#define endl '\n'

void dfs(int u, int p) {
	dep[u] = p == -1 ? 1 : dep[p]+1;
	par[0][u] = p;
	st[u] = flat.size();
	flat.push_back(u);
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u);

	}
	en[u] = flat.size()-1;
}

int walk(int u, int k) {
	for (int i = 17; i >= 0; i--) {
		if (k & (1 << i)) {
			u = par[i][u];
		}
	}
	return u;
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) {
		return lca(v, u);
	}
	int diff = dep[u]-dep[v];
	u = walk(u, diff);
	if (u == v) return u;
	for (int i = 17; i >= 0; i--) {
		if (par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
	}
	return par[0][u];
}

bool isanc(int u, int v) {
	//returns if v is an ancestor of u
	if (dep[u] < dep[v]) return false;
	u = walk(u, dep[u]-dep[v]);
	return u == v;
}

//segtree stuff
void buildtree(int ss, int se, int si) {
	lazy[si] = 0LL;
	if (ss == se) {
		seg[si] = orig[flat[ss]];
		return;
	}
	int mid = (ss+se)/2;
	buildtree(ss, mid, si*2+1);
	buildtree(mid+1, se, si*2+2);
	seg[si] = seg[si*2+1] + seg[si*2+2];
}

void up(int us, int ue, int ss, int se, int si, ll x) {
	if (lazy[si] != 0) {
		seg[si] += (se-ss+1LL)*lazy[si];
		if (ss != se) {
			lazy[si*2+1]+=lazy[si];
			lazy[si*2+2]+=lazy[si];
		}
		lazy[si] = 0LL;
	}
	if (us > ue || ss > se || us > se || ue < ss) return;
	if (us <= ss && se <= ue) {
		seg[si] += (se-ss+1LL)*x;
		if (ss != se) {
			lazy[si*2+1] += x;
			lazy[si*2+2] += x;
		}
		return;
	}
	int mid = (ss+se)/2;
	up(us, ue, ss, mid, si*2+1, x);
	up(us, ue, mid+1, se, si*2+2, x);
	seg[si] = seg[si*2+1] + seg[si*2+2];

}

void update(int us, int ue, ll x) {
	up(us, ue, 0, n-1, 0, x);
}

ll qu(int qs, int qe, int ss, int se, int si) {
	if (lazy[si] != 0) {
		seg[si] += (se-ss+1LL)*lazy[si];
		if (ss != se) {
			lazy[si*2+1]+=lazy[si];
			lazy[si*2+2]+=lazy[si];
		}
		lazy[si] = 0LL;
	}
	if (qs > qe || ss > se || qs > se || qe < ss) return 0LL;
	if (qs <= ss && se <= qe) return seg[si];
	int mid = (ss+se)/2;
	return qu(qs, qe, ss, mid, si*2+1) +
		qu(qs, qe, mid+1, se, si*2+2);
}

ll query(int qs, int qe) {
	// cout << "requested sum from  " << qs << "  to  " << qe << endl;
	return qu(qs, qe, 0, n-1, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> orig[i];
	}
	int u, v;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	r = 1;
	dfs(1, -1);
	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= n; j++) {
			if (par[i-1][j] != -1) {
				par[i][j] = par[i-1][par[i-1][j]];
			}
			else par[i][j] = -1;
		}
	}
	buildtree(0, n-1, 0);

	int tp;
	ll x;
	// cout << "got to queries" << endl;
	for (int i = 0; i < q; i++) {
		cin >> tp;
		if (tp == 1) {
			cin >> v;
			r = v;
		}
		if (tp == 2) {
			cin >> u >> v >> x;
			if (isanc(u, r) && isanc(v, r)) {
				int lc = lca(u, v);
				if (lc == r) update(0, n-1, x);
				else update(st[lc], en[lc], x);
			}
			else if (!isanc(u, r) && !(isanc(v, r))) {

				int lc = lca(u, v);
				int tl = lca(u, r);
				if (dep[tl] > dep[lc]) lc = tl;
				tl = lca(v, r);
				if (dep[tl] > dep[lc]) lc = tl;

				if (isanc(r, lc)) {
					update(0, n-1, x);
					int sub = walk(r, dep[r]-dep[lc]-1);
					update(st[sub], en[sub], 0LL-x);
				}
				else {
					update(st[lc], en[lc], x);
				}
			}
			else {
				update(0, n-1, x);
			}
		}
		if (tp == 3) {
			cin >> v;
			// cout << " ---------->  " << v << endl;
			if (isanc(v, r)) {
				if (r == v) cout << query(0, n-1) << endl;
				else cout << query(st[v], en[v]) << endl;
			}
			else {
				if (isanc(r, v)) {
					if (r == v) {
						cout << query(0, n-1) << endl;
					}
					else {
						int sub = walk(r, dep[r]-dep[v]-1);
						cout << query(0, n-1) - query(st[sub], en[sub]) << endl;
					}
					
				}
				else {
					cout << query(st[v], en[v]) << endl;
				}
			}
		}
	}
	cin >> n;

}