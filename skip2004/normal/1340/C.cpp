#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
int n, m;
int g, R;
int d[maxn];
int dp[10010][1010];
int vis[10010][1010];
typedef std::pair<int, int> pr;
const int N = 10010000;
pr q[N + N];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rep(i, 1, m) cin >> d[i];
	d[++m] = 0;
	std::sort(d + 1, d + m + 1);
	m = std::unique(d + 1, d + m + 1) - d - 1;
	cin >> g >> R;
	const int inf = 1e9;
	rep(i, 1, m) rep(j, 0, g - 1) dp[i][j] = inf;
	dp[1][0] = 0;
	int l = N, r = N;
	q[l] = pr(1, 0);
	const auto upt = [&](int x, int y, int d) {
		if(y > g) return ;
		bool flag = y == g;
		d += flag;
		if(flag) y = 0;
		if(dp[x][y] > d) {
			dp[x][y] = d;
			if(flag)
				q[++r] = pr(x, y);
			else
				q[--l] = pr(x, y);
		}
	};
	for(;l <= r;) {
		pr x = q[l++];
		int a = x.first, b = x.second;
		if(vis[a][b]) continue;
		vis[a][b] = 1;
		if(a != 1) upt(a - 1, b + d[a] - d[a - 1], dp[a][b]);
		if(a != m) upt(a + 1, b + d[a + 1] - d[a], dp[a][b]);
	}
	ll ans = 1e18;
	rep(i, 1, m) if(d[i] + g >= n) {
		if(dp[i][0] <= 1e8) ans = std::min(ans, (ll) dp[i][0] * (g + R) + n - d[i]);
	}
	cout << (ans > 1e17 ? -1 : ans) << '\n';
}