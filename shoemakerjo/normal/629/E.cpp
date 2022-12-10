#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
#define ll long long
ll dep[maxn];
int par[18][maxn];
int st[maxn];
int en[maxn];
ll subsize[maxn];
vector<vector<int>> adj(maxn);
vector<int> et;
ll seg[maxn*4];
ll distall[maxn];
int n, m;


void buildtree(int ss, int se, int si) {
	if (ss == se) {
		seg[si] = dep[et[ss]];
		return;
	}
	int mid = (ss+se)/2;
	buildtree(ss, mid, si*2+1);
	buildtree(mid+1, se, si*2+2);
	seg[si] = seg[si*2+1] + seg[si*2+2];
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

void euler(int u, int p) {
	subsize[u] = 1;
	st[u] = et.size();
	et.push_back(u);
	par[0][u] = p;
	dep[u] = p == -1 ? 1 : dep[p]+1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		euler(v, u);
		subsize[u] += subsize[v];
	}
	en[u] = et.size()-1;
}

void gd(int u, int p) {
	if (p == -1) {
		distall[u] = seg[0]-n*1LL;
	}
	else {
		distall[u] = distall[p];
		distall[u] += n - subsize[u];
		distall[u] -= subsize[u];
	}
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		gd(v, u);
	}

}

ll qu(int qs, int qe, int ss, int se, int si) {
	if (qs > qe || ss > se || qs > se || qe < ss) return 0LL;
	if (qs <= ss && se <= qe) {
		return seg[si];
	}
	int mid = (ss+se)/2;
	return qu(qs, qe, ss, mid, si*2+1) + 
		qu(qs, qe, mid+1, se, si*2+2);
}

ll subsum(int u) {
	return qu(st[u], en[u], 0, n-1, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(10);
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	euler(1, -1);
	// cout << "did euler:   " <<  et.size() << endl;
	buildtree(0, n-1, 0);
	// cout << "built seg tree" << endl;
	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= n; j++) {
			if (par[i-1][j] == -1) {
				par[i][j] = -1;
			}
			else {
				par[i][j] = par[i-1][par[i-1][j]];
			}
		}
	}
	// cout << "done with lca table" << endl;
	gd(1, -1);
	// cout << "distance to all done" << endl;
	int u, v;

	// for (int i = 1; i <= n; i++) {
	// 	cout << i << ":   " << distall[i] << endl;
	// }
	// cout << endl << endl;

	while (m-- > 0) {
		cin >> u >> v;
		int lc = lca(u, v);
		if (lc ==  v) {
			int temp  = u;
			u = v;
			v = temp;
		}
		if (lc == u) {
			int bel = walk(v, dep[v]-dep[u]-1);
			int uc = n - subsize[bel];
			int vc = subsize[v];
			ll usum = distall[u] - (subsum(bel)-subsize[bel]*dep[u]);;
			ll vsum = subsum(v);
			ll dist = dep[v]-dep[u];
			double tot = uc*1.0*vc;
			double tsum = (usum-0.0)*vc;
			// cout << "first tsum   " << tsum << endl;
			tsum += (vsum-vc*1.0*dep[v])*uc;
			double ans = tsum/tot;
			// cout << "here   " << tot << "   " << dist << endl;
			ans += dist + 1.0;
			cout << ans << endl;
		}
		else {
			double tot = 0.0;
			int uc = subsize[u];
			int vc = subsize[v];
			ll usum = subsum(u);
			ll vsum = subsum(v);
			ll dist = dep[u]-dep[lc] + dep[v]-dep[lc];
			tot = uc*1.0*vc;
			double tsum = (usum-uc*1.0*dep[u])*vc;
			tsum += (vsum-vc*1.0*dep[v])*uc;
			double ans = tsum/tot;
			ans += dist + 1.0;
			cout << ans << endl;
		}

	}
	cin >> n;
}