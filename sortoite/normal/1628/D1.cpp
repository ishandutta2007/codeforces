#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2020, inv2 = (mod + 1) / 2;
const double eps = 1e-6;
double d[N][N];
int p[N][N];
int solve() {
	int n, m, k; cin >> n >> m >> k;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j <= m && j <= i; j ++) {
			if(j == 0) {
				d[i][j] = p[i][j] = 0;
			}
			else if(j == i) {
				d[i][j] = (double) k * i;
				p[i][j] = 1ll * k * i % mod;
			}
			else if(d[i - 1][j] - k > d[i - 1][j - 1] + k + eps) {
				d[i][j] = d[i - 1][j - 1] + k;
				p[i][j] = (p[i - 1][j - 1] + k) % mod;
			}
			else if(d[i - 1][j] + eps < d[i - 1][j - 1]) {
				d[i][j] = d[i - 1][j];
				p[i][j] = p[i - 1][j];
			}
			else {
				d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) / 2;
				p[i][j] = 1ll * (p[i - 1][j] + p[i - 1][j - 1]) * inv2 % mod;
			}
		}
	}
	return p[n][m];
}
int main() {
#ifdef TRUE
	freopen("in.in", "r", stdin);
#endif
	int T; cin >> T;
	while(T --) {
		cout << solve() << endl;
	}
	return 0;
}