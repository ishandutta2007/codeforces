#include <bits/stdc++.h>
using namespace std;

const int N = 33;
const int Inf = 0x3f3f3f3f;

int a[N][N];
int f[N][N];

int main() {
	ios :: sync_with_stdio(false);
	int n, base = 0; cin >> n;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++) {
			cin >> a[i][j];
			base += a[i][j];
			a[i][j] *= -2;
		}

	int m = (n + 1) / 2;
	int ans = -Inf;
	for(int k = 0; k <= (1 << m); k ++) {
		int now = 0;
		for(int i = 0; i < m; i ++) {
			f[i][m - 1] = (k >> i) & 1;
			now += f[i][m - 1] * a[i][m - 1];
		}
		for(int i = m; i < n; i ++) {
			f[i][m - 1] = f[m - 1][m - 1] ^ f[i - m][m - 1];
			now += f[i][m - 1] * a[i][m - 1];
		}

		for(int j = 0; j < m - 1; j ++) {
			int tmp = -Inf;
			for(f[m - 1][j] = 0; f[m - 1][j] < 2; f[m - 1][j] ++) {
				f[m - 1][j + m] = f[m - 1][j] ^ f[m - 1][m - 1];
				int b = f[m - 1][j] * a[m - 1][j] + f[m - 1][j + m] * a[m - 1][j + m];
				int t = 0;
				for(int i = 0; i < m - 1; i ++) {
					int s = -Inf;

					for(f[i][j] = 0; f[i][j] < 2; f[i][j] ++) {
						f[i][j + m] = f[i][j] ^ f[i][m - 1];
						f[i + m][j] = f[i][j] ^ f[m - 1][j];
						f[i + m][j + m] = f[i][j + m] ^ f[m - 1][j + m];
					
						s = max(s, f[i][j] * a[i][j] + f[i + m][j] * a[i + m][j] +
							f[i][j + m] * a[i][j + m] + f[i + m][j + m] * a[i + m][j + m]);
					}
					t += s;
				}
				tmp = max(tmp, t + b);
			}
			now += tmp;
		}
		ans = max(ans, now);
	}

	cout << base + ans << '\n';
	return 0;
}