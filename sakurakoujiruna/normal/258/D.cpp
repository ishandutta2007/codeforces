#include <bits/stdc++.h>
using namespace std;

const int N = int(1e3) + 11;

int p[N];
double f[N][N], old[N][N];

int main() {
	ios :: sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> p[i];
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			f[i][j] = (p[i] > p[j]);

	while(m --) {
		int x, y;
		cin >> x >> y;
		for(int i = 1; i <= n; i ++) {
			old[i][x] = f[i][x];
			old[i][y] = f[i][y];
			old[x][i] = f[x][i];
			old[y][i] = f[y][i];
		}
		for(int i = 1; i <= n; i ++) {
			f[i][x] = f[i][y] = (old[i][x] + old[i][y]) / 2;
			f[x][i] = f[y][i] = (old[x][i] + old[y][i]) / 2;
		}
		f[x][y] = f[y][x] = 0.5;
	}

	double ans = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = i + 1; j <= n; j ++)
			ans += f[i][j];
	cout << fixed << setprecision(9) << ans << '\n';
	return 0;
}