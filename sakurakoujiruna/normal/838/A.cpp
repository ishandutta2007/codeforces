#include <bits/stdc++.h>
using namespace std;

const int N = 2511;
char c[N][N];
int sum[N][N];

int n, m;
int f(int i, int j) {
	i = min(i, n);
	j = min(j, m);
	return sum[i][j];
}

int main() {
	//ios :: sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		scanf("%s", c[i] + 1);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++) {
			sum[i][j] = (c[i][j] == '1');
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	int ans = 1e9L;
	for(int k = 2; k <= min(n, m); k ++) {
		int s = 0;
		for(int i = k; i <= n + k; i += k)
			for(int j = k; j <= m + k; j += k) {
				int t = f(i, j) - f(i, j - k) - f(i - k, j) + f(i - k, j - k);
				s += min(t, k * k - t);
			}
		//cout << k << ' ' << s << '\n';
		ans = min(ans, s);
	}
	cout << ans << '\n';
}