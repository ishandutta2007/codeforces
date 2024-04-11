#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 600 + 10;
LL d[N][N] = {0}, a[N][N] = {0}, b[N][N] = {0}, res[N][N] = {0};
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			d[i][j] = b[i][j] = res[i][j] = (i==j?0:1e18);
		}
	}
	vector< pair<pair<int,int>,int> > e(m);
	for (int i = 1; i <= m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		d[u][v] = d[v][u] = min((LL)w, d[u][v]);
		e[i-1] = make_pair(make_pair(u,v),w);
	}	
	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int q;
	cin >> q;
	while (q --) {
		int u, v, l;
		cin >> u >> v >> l;
		a[u][v] = a[v][u] = min(-(LL)l, a[u][v]);
	}

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			for (int k = 1; k <= n; k ++) {
				b[i][k] = min(b[i][k], a[i][j] + d[j][k]);
				b[i][k] = min(b[i][k], d[i][j] + a[j][k]);
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			for (int k = 1; k <= n; k ++) {
				res[i][j] = min(res[i][j], b[i][k] + d[k][j]); 
				res[i][j] = min(res[i][j], d[i][k] + b[k][j]); 
			}
		}
	}
	int ans = 0;
	for (auto edge: e) {
		int u = edge.first.first;
		int v = edge.first.second;
		int w = edge.second;
		//printf("u=%d,v=%d,r=%d/%d\n", u,v,res[u][v],b[u][v]);
		if (res[u][v] + w <= 0) ans ++;
	}
	cout << ans << endl;
}