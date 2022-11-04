#include <bits/stdc++.h>
#define MX 400010

using namespace std;

int n, k, sz[MX], rlt, vis[MX];
vector <int> con[MX], vv ,tmp;

int main () {
	int t;
	cin >> t;
	int u, v;
	
	while (t--) {
		cin >> n >> k;
		rlt = 0;
		memset (vis, 0, sizeof vis);
		memset (sz, 0, sizeof vis);
		for (int i = 0; i <= n; i++) con[i].clear();
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v;
			u--, v--;
			sz[u]++, sz[v]++;
			con[u].push_back(v);
			con[v].push_back(u);
		}
		vv.clear(), tmp.clear();
		for (int i = 0; i < n; i++) if (sz[i] == 1 || sz[i] == 0) vv.push_back(i), vis[i] = 1; 
		while (k--) {
			if (rlt == n) break;
			for (auto t: vv) {
				rlt++;
				for (auto tt: con[t]) {
					if (vis[tt]) continue;
					sz[tt]--;
					if (sz[tt] == 1 || sz[tt] == 0) vis[tt] = 1, tmp.push_back(tt);
				}
			}
			vv.clear();
			vv = tmp;
			tmp.clear();
		}
		cout << n - rlt << endl;
	}
	
}