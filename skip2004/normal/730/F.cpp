#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
const int N = 5010;
const int M = 10100;
using std::cin;
using std::cout;
int dp[N][M], used[N][M];
int a[N], n, s, b;
int out[N];
inline void down(int & x,int y) {
	if(x > y) x = y;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> b;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
		s += a[i] / 10;
	}
	for(int i = 0;i <= n;++i) {
		for(int j = 0;j <= s;++j) {
			dp[i][j] = 1e9;
		}
	}
	dp[0][0] = 0;
	int now = 0, cost = 0;
	for(int i = 0;i < n;++i) {
		const int max = a[i + 1] / 10;
		for(int j = 0;j <= now;++j) if(dp[i][j] <= 1e5) {
			const int rem = b + j - (cost - dp[i][j]);
			for(int k = 0;k + k <= a[i + 1] && k <= rem;++k) {
				const int price = a[i + 1] - k;
				int & to = dp[i + 1][j + price / 10];
				if(to > dp[i][j] + price) {
					to = dp[i][j] + price;
					used[i + 1][j + price / 10] = price;
				}
			}
		}
		now += max;
		cost += a[i + 1];
	}
	int ans = 0;
	for(int j = 0;j <= s;++j) {
		if(dp[n][j] < dp[n][ans]) {
			ans = j;
		}
	}
	cout << dp[n][ans] << '\n';
	for(int i = n;i >= 1;--i) {
		out[i] = used[i][ans];
		ans -= used[i][ans] / 10;
	}
	for(int i = 1;i <= n;++i) {
		cout << a[i] - out[i] << " \n"[i == n];
	}
}