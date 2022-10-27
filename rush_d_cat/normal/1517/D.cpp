#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500 + 10;
int n, m, p;
int a[N][N], b[N][N], f[N][N][11];
const int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i ++) for (int j = 1; j < m; j ++) cin >> b[i][j];
	for (int i = 1; i < n; i ++) for (int j = 1; j <= m; j ++) cin >> a[i][j];
	
	
	for (int i = 0; i < N; i ++) for (int j = 0; j < N; j ++) for (int k = 1; k < 11; k ++) f[i][j][k] = inf;
	auto upd = [](int &x, int y) {
		x = min(x, y);
	};
	for (int k = 0; k < p / 2; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				if (i < n) upd(f[i+1][j][k+1], f[i][j][k] + a[i][j]);
				if (i > 1) upd(f[i-1][j][k+1], f[i][j][k] + a[i-1][j]);
				if (j < m) upd(f[i][j+1][k+1], f[i][j][k] + b[i][j]);
				if (j > 1) upd(f[i][j-1][k+1], f[i][j][k] + b[i][j-1]);
			}
		}
	}
	if (p & 1) {
		for (int i = 1; i <= n; i ++) {
			for (int j =1; j<=m;j++) cout << -1 << " \n"[j==m];
		}
	} else {
		for (int i = 1; i <= n; i ++) {
			for (int j =1; j<=m;j++) cout << (2*f[i][j][p/2]) << " \n"[j==m];
		}
	}
}