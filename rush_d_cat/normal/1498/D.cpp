#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const int inf = 1e9;
int f[N], g[N], pre[N];
int las[N], ans[N];
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i ++) f[i] = 0;
	f[0] = 1;

	for (int i = 1; i <= m; i ++) ans[i] = 1e9;

	for (int i = 1; i <= n; i ++) {
		int t, y; LL x;
		cin >> t >> x >> y;
		if (t == 1) {
			memset(pre, -1, sizeof(pre));
			memset(las, -1, sizeof(las));
			for (int j = 0; j <= m; j ++) {
				LL nex = j + (1LL * x + 100000 - 1) / 100000;
				if (nex <= m) pre[nex] = j;
			}
			las[0] = 0;
			for (int j = 1; j <= m; j ++) {
				if (f[j]) {
					las[j] = 0; continue; 
				}
				if (pre[j] >= 0) {
					if (las[pre[j]] != -1) {
						las[j] = las[pre[j]] + 1;
						if (las[j] <= y) f[j] = 1;
					}
				}
			}
		} else {
			memset(pre, -1, sizeof(pre));
			memset(las, -1, sizeof(las));
			for (int j = 1; j <= m; j ++) {
				LL nex = (1LL * j * x + 100000 - 1) / 100000;
				if (nex <= m) pre[nex] = j;
			}
			for (int j = 1; j <= m; j ++) {
				if (f[j]) {
					las[j] = 0; continue; 
				}
				if (pre[j] >= 0) {
					if (las[pre[j]] != -1) {
						las[j] = las[pre[j]] + 1;
						if (las[j] <= y) f[j] = 1;
					}
				}
			}
		}
		for (int j = 1; j <= m; j ++) if (f[j]) ans[j] = min(ans[j], i);
	} 
	for (int i = 1; i <= m; i ++) {
		cout << (ans[i]==1e9?-1:ans[i]) << " ";
	} 
}