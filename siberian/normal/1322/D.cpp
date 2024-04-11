#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 2010;
int n, m;
int l[MAXN], s[MAXN], c[MAXN * 2];

void read() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
		l[i]--;
	}
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n + m; i++)
		cin >> c[i];
}

const int INF = -1e9 - 10;
int dp[MAXN][MAXN * 2];
int ans;

void build() {
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n + m; j++)
			dp[i][j] = INF;
	for (int i = 0; i <= n + m; i++)
		dp[0][i] = 0;
}

void make_ans() {
	ans = 0;
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= n + m; j++) {
			chkmax(ans, dp[i][j]);
		}
	}
}

void run() {
	build();
	for (int i = n - 1; i >= 0; i--) {
		for (int k = n - 1 - i + 1; k >= 0; k--) {
			int now = l[i];
			int cnt = k;
			if (cnt > 0 && dp[cnt - 1][now] != INF)
			chkmax(dp[cnt][now], dp[cnt - 1][now] - s[i] + c[now]);
			while (cnt) {
				if (dp[cnt][now] != INF)
				chkmax(dp[cnt / 2][now + 1], dp[cnt][now] + (cnt / 2) * c[now + 1]);
				cnt /= 2;
				now++;
			}
		}
		for (int i = 1; i <= n + m; i++) {
			chkmax(dp[0][i], dp[0][i - 1]);
			chkmax(dp[0][i], dp[1][i - 1]);
		}
	}
	make_ans();
}

void write() {
	cout << ans << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}