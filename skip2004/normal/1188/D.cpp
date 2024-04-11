#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 100100;
const int M = 70;
typedef long long ll;
const int mod = 998244353;
int rk[maxn][M];
int kth[M][maxn];
char s[maxn][M];
int val[maxn][M];
int cnt[maxn][M];
bool good[maxn][M];
int dp[M][maxn];
int c[2], * c_val = c, n;
 
inline bool up(int & x, int y) {
	return x < y ? x = y, 1 : 0;
}
ll a[maxn];
 
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	const int N = 62;
	static int last[maxn];
	ll max = 0;
	for(int i = 0;i < n;++i) {
		cin >> a[i];
		max = std::max(max, a[i]);
	}
	for(int i = 0;i < n;++i) {
		ll x = max - a[i];
		for(int j = 0;j < 62;++j) {
			s[i][j] = char('0' + (x >> j & 1));
		}
	}
	c[0] = 0, c[1] = -1;
	for(int i = 0;i < n;++i) {
		for(int j = 0;j < N;++j) {
			val[i][j] = c[s[i][j] & 15];
			good[i][j] = 1;
		}
		kth[0][i] = i;
	}
	for(int i = 0;i <= N;++i) {
		int * b = kth[i + 1];
		for(int j = 0;j < n;++j) b[j] = j;
		std::sort(b, b + n, [&](int a, int b) {
			int sa = s[a][i] & 15, sb = s[b][i] & 15;
			return sa != sb ? sa > sb : last[a] < last[b];
		});
		for(int j = 0, now = -1;j < n;++j) {
			rk[b[j]][i] = now += !j || s[b[j]][i] != s[b[j - 1]][i] || last[b[j]] != last[b[j - 1]];
			cnt[b[j]][i] = j;
		}
		for(int j = 0;j < n;++j) {
			last[j] = rk[j][i];
		}
	}
	for(int i = 0;i <= N;++i) for(int j = i == N;j <= n;++j) dp[i][j] = -1e9;
	for(int i = N - 1;i >= 0;--i) {
		for(const char c : "01") {
			const int v = c & 15;
			int og = -1, sum = 0;
			for(int j = 0;j < n;++j) {
				const int k = kth[i][j];
				if(v || good[k][i]) sum += c_val[((s[k][i] & 15) + v) % 2];
				if((s[k][i] & 15) + v >= 2) up(og, cnt[k][i]);
			}
			for(int j = 0;j <= n;++j) {
				const int k = kth[i][j];
				if(up(dp[i][j], dp[i + 1][og + 1] + sum)) ;
				if(v || good[k][i]) {
					sum -= c_val[((s[k][i] & 15) + v) % 2];
					sum += c_val[((s[k][i] & 15) + v + 1) % 2];
				} else {
					sum += c_val[1];
				}
				if((s[k][i] & 15) + v >= 1) up(og, cnt[k][i]);
			}
		}
	}
	cout << -dp[0][0] << '\n';
}