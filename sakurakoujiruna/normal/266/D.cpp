#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int N = 211, M = N * N / 2;

int u[M], v[M], w[M];

int f[N][N];

bool check(int n, int m, int lim) {
	for(int i = 1; i <= m; i ++) {
		vector <pair <int, int>> v;
		bool t = 1;
		for(int j = 1; j <= n; j ++) {
			int l = f[j][u[i]], r = f[j][::v[i]];
			if(lim >= l && lim >= r) {
				if(2 * lim - l - r >= w[i]) {
					v.pb({0, 1});
					v.pb({w[i] + 1, -1});
				} else {
					v.pb({0, 1});
					v.pb({min(w[i], lim - l) + 1, -1});
					v.pb({w[i] - min(w[i], lim - r), 1});
					v.pb({w[i] + 1, -1});
				}
			} else if(lim >= l) {
				v.pb({0, 1});
				v.pb({min(w[i], lim - l) + 1, -1});
			} else if(lim >= r) {
				v.pb({w[i] - min(w[i], lim - r), 1});
				v.pb({w[i] + 1, -1});
			} else {
				t = 0;
				break;
			}
		}
		if(!t) continue;
		sort(v.begin(), v.end());
		int cnt = 0;
		for(auto e : v) {
			cnt += e.second;
			if(cnt == n) return 1;
		}
	}
	return 0;
}

int main() {
	ios :: sync_with_stdio(0);
	int n, m; cin >> n >> m;
	memset(f, 0x3f, sizeof f);
	for(int i = 1; i <= n; i ++)
		f[i][i] = 0;
	for(int i = 1; i <= m; i ++) {
		cin >> u[i] >> v[i] >> w[i]; w[i] *= 2;
		f[u[i]][v[i]] = f[v[i]][u[i]] = w[i];
	}
	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

	int l = 0, r = 1e8L;
	while(l + 1 < r) {
		int im = (l + r) / 2;
		if(check(n, m, im - 1))
			r = im;
		else
			l = im;
	}
	cout << fixed << setprecision(1);
	cout << l / 2.0 << '\n';
}