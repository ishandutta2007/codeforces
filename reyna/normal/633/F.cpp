//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define int long long

const int N = 1e5 + 5;

int read() { int x; cin >> x; return x; }
int dw[N], up[N], a[N], ondw[N], onup[N];
vector<int> adj[N];

void dfs_down(int v, int p = -1) {
	ondw[v] = a[v];
	dw[v] = a[v];
	int max0 = 0, max1 = 0;
	for (int u : adj[v]) if (u != p) {
		dfs_down(u, v);
		smax(dw[v], dw[u]);
		smax(ondw[v], ondw[u] + a[v]);
		smax(dw[v], ondw[v]);
		int x = ondw[u];
		if (max0 <= x)
			max1 = max0, max0 = x;
		else if (max1 <= x)
			max1 = x;
	}
	smax(dw[v], max1 + max0 + a[v]);
}

void dfs_up(int v, int val = 0, int onu = 0, int p = -1) {
	if (p != -1) {
		smax(up[v], val);
		smax(onup[v], onu);
		smax(up[v], onup[v]);
	}
	vector<int> lmax0(adj[v].size() + 3, 0), rmax0(adj[v].size() + 3, 0), lmax1(adj[v].size() + 3, 0), rmax1(adj[v].size() + 3, 0), lmx(adj[v].size() + 3, 0), rmx(adj[v].size() + 3, 0);
	int cur = 1;
	int max0 = 0, max1 = 0;
	for (int u : adj[v]) if (u != p) {
		int x = ondw[u];
		if (max0 <= x)
			max1 = max0, max0 = x;
		else if (max1 <= x)
			max1 = x;
		smax(lmx[cur], max(lmx[cur - 1], dw[u]));
		lmax0[cur] = max0;
		lmax1[cur] = max1;
		cur++;
	}
	max0 = 0, max1 = 0;
	cur--;
	for (int i = adj[v].size() - 1; i >= 0; --i) if (adj[v][i] != p) {
		int u = adj[v][i];
		int x = ondw[u];
		if (max0 <= x)
			max1 = max0, max0 = x;
		else if (max1 <= x)
			max1 = x;
		smax(rmx[cur], max(rmx[cur + 1], dw[u]));
		rmax0[cur] = max0;
		rmax1[cur] = max1;
		cur--;
	}
	cur = 1;
	for (int u : adj[v]) if (u != p) {
		int z[5];
		z[0] = lmax0[cur - 1], z[1] = lmax1[cur - 1];
		z[2] = rmax0[cur + 1], z[3] = rmax1[cur + 1];
		z[4] = onu;
		sort(z, z + 5);
		int maxonu = max(onu + a[v], z[4] + a[v]);
		int go = z[3] + z[4] + a[v];
		dfs_up(u, max(val, max(go, max(lmx[cur - 1], rmx[cur + 1]))), maxonu, v);
		cur++;
	}
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read();
	rep(i, n)
		cin >> a[i];
	rep(i, n - 1) {
		int u = read() - 1, v = read() - 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs_down(0);
	dfs_up(0);
	int res = 0;
	rep(i, n) {
		smax(res, dw[i] + up[i]);
//		cout << i << ' ' << dw[i] << ' ' << up[i] << endl;
	}
	cout << res;
}