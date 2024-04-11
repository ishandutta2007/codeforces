#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;

const int N = 30030;
const int K = 220;
int n, k;
ll a[N];

ll dp[N][K][2], s[N];

ll pre0[N][K][2];
ll pre1[N][K][2];

ll max[N], min[N];
// now is i, chos j, type is k
const ll inf = 1e18;
inline void up(ll & x, ll y) { if(x < y) x = y; }
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	rep(i, 1, n) cin >> a[i], s[i] = s[i - 1] + a[i];
	rep(i, 0, n) rep(j, 1, k) rep(k, 0, 1) {
		dp[i][j][k] = -inf;
		pre0[i][j][k] = -inf;
		pre1[i][j][k] = -inf;
	}
	for(int i = 1;i <= n;++i) {
		max[i] = std::max<ll>(max[i - 1], 0) + a[i];
		min[i] = std::min<ll>(min[i - 1], 0) + a[i];
	}
	rep(i, 1, n) {
		dp[i][1][0] = - min[i];
		dp[i][1][1] = max[i];
	}
	rep(i, 1, n) {
		pre1[i][1][0] = std::max(pre1[i - 1][1][0], dp[i][1][0] - s[i] * 2);
		pre1[i][1][1] = std::max(pre1[i - 1][1][1], dp[i][1][1] + s[i] * 2);
		pre0[i][1][0] = std::max(pre0[i - 1][1][0], dp[i][1][0]);
		pre0[i][1][1] = std::max(pre0[i - 1][1][1], dp[i][1][1]);
		rep(l, 2, k - 1) {
			up(dp[i][l][0], dp[i - 1][l][0]);
			up(dp[i][l][1], dp[i - 1][l][1]);
			up(dp[i][l][0], pre0[i - 1][l - 1][0]);
			up(dp[i][l][1], pre0[i - 1][l - 1][1]);

			up(dp[i][l][0], pre1[i - 1][l - 1][1] - s[i] * 2);
			up(dp[i][l][1], pre1[i - 1][l - 1][0] + s[i] * 2);

			pre0[i][l][0] = std::max(pre0[i - 1][l][0], dp[i][l][0]);
			pre0[i][l][1] = std::max(pre0[i - 1][l][1], dp[i][l][1]);
			up(pre1[i][l][0], std::max(pre1[i - 1][l][0], dp[i][l][0] - s[i] * 2));
			up(pre1[i][l][1], std::max(pre1[i - 1][l][1], dp[i][l][1] + s[i] * 2));
		}
	}
	ll res = 0;
	std::reverse(a + 1, a + n + 1);
	rep(i, 1, n) {
		max[i] = std::max<ll>(max[i - 1], 0) + a[i];
		min[i] = std::min<ll>(min[i - 1], 0) + a[i];
	}
	std::reverse(a + 1, a + n + 1);
	std::reverse(max + 1, max + n + 1);
	std::reverse(min + 1, min + n + 1);
	rep(i, 1, n) {
		up(res, dp[i - 1][k - 1][0] + max[i]);
		up(res, dp[i - 1][k - 1][1] - min[i]);
	}
	cout << res << '\n';
}