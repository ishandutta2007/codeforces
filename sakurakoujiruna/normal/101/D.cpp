#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back

const int N = (int)1e5 + 11;

int sz[N], sum[N];
vector <pair <int, int>> e[N];

double dfs(int x, int p = -1) {
	sz[x] = 1; sum[x] = 0; double ret = 0;
	vector <pair <double, int>> v;
	
	bool leaf = true;
	for(auto i : e[x]) if(i.fi != p) {
		ret += (dfs(i.fi, x) + i.se) * sz[i.fi];
		v.pb({sum[i.fi] + i.se, sz[i.fi]});
		sz[x] += sz[i.fi];
		sum[x] += sum[i.fi] + i.se;
		leaf = false;
	}
	if(leaf) return 0;
	sort(v.begin(), v.end(), [](auto p, auto q){
		return p.fi / p.se < q.fi / q.se; });

	int suf = sz[x] - 1;
	for(auto p : v) {
		suf -= p.se;
		ret += p.fi * 2 * suf;
	}
	return ret / sz[x];
}

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i < n; i ++) {
		int u, v, w; cin >> u >> v >> w;
		e[u].pb({v, w});
		e[v].pb({u, w});
	}
	cout << fixed << setprecision(9) << dfs(1) / (sz[1] - 1) * sz[1] << '\n';
	return 0;
}