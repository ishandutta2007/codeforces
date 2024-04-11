#include<bits/stdc++.h>
using std::cin;
using std::cout;
using ll = long long;
int t, n, k;
const int N = 200005;
int head[N], next[N];
inline void link(int fa, int x) {
	next[x] = head[fa], head[fa] = x;
}
int size[N], s[N];
ll dp[N][2];
inline void dfs0(int x, int k) {
	size[x] = 1;
	int deg = 0;
	for(int i = head[x];i;i = next[i]) {
		++ deg;
	}
	if(deg == 0) {
		dp[x][0] = (ll) k * s[x];
		dp[x][1] = (ll) (k + 1) * s[x];
	} else {
		std::vector<ll> val;
		for(int i = head[x];i;i = next[i]) {
			dfs0(i, k / deg);
			dp[x][0] += dp[i][0];
			val.push_back(dp[i][1] - dp[i][0]);
		}
		sort(val.rbegin(), val.rend());
		dp[x][1] = dp[x][0];
		for(int i = 0;i < k % deg;++i) {
			dp[x][0] += val[i];
		}
		for(int i = 0;i < k % deg + 1;++i) {
			dp[x][1] += val[i];
		}
		dp[x][0] += (ll) k * s[x];
		dp[x][1] += (ll) (k + 1) * s[x];
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	for(int i = 0;i < t;++i) {
		cin >> n >> k;
		for(int i = 2, p;i <= n;++i) {
			cin >> p, link(p, i);
		}
		for(int i = 1;i <= n;++i) {
			cin >> s[i];
		}
		dfs0(1, k);
		cout << dp[1][0] << '\n';
		for(int i = 1;i <= n;++i) {
			head[i] = next[i] = 0;
			dp[i][0] = dp[i][1] = 0;
		}
	}
}