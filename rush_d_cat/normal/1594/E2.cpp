#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll mpow(ll a, ll x) {
	if (x == 0) return 1;
	ll t = mpow(a, x>>1);
	if (x%2==0)
		return t*t%mod;
	return t*t%mod*a%mod;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int k, n;
	cin >> k >> n;
	map<string,int> mp;
	mp["white"] = 0, mp["yellow"] = 1;
	mp["green"] = 2, mp["blue"] = 3;
	mp["red"] = 4, mp["orange"] = 5;
	
	map<ll, int> m, vis;
	for (int i = 0; i < n; i ++) {
		ll x; string str;
		cin >> x >> str;
		m[x] = mp[str];
		ll y = x;
		while (y) {
			vis[y] = 1; y >>= 1; 
		}
	}	

	auto cal = [&](int k) {
		return mpow(4ll, (1LL<<k) - 2) % mod;
	};
	
	vector<ll> dp(61, 0);
	for (int i = 1; i < 61; i ++)
		dp[i] = cal(i);
	
	map<pair<ll,int>,ll > res;
	function<ll(ll,int,int)> dfs = [&](ll x, int dep, int c) {
		if (res.find({x,c}) != res.end())
			return res[{x,c}];

		if (m.find(x) != m.end() && m[x] != c)
			return res[{x,c}] = 0ll;
		
		if (vis[x] && dep == k)
			return res[{x,c}] = 1ll;

		if (not vis[x])
			return res[{x,c}] = dp[k - dep + 1];
		
		// printf("x=%lld,dep=%d,c=%d\n", x,dep,c);
		ll lw = 0, rw = 0;
		for (int i = 0; i < 6; i ++)
			if (i/2 != c/2) {
				(lw += dfs(x<<1, dep+1, i)) %= mod;
				(rw += dfs(x<<1|1, dep+1, i)) %= mod;
			}

		return res[{x,c}] = (lw * rw) % mod;	
	};

	ll ans = 0;
	for (int i = 0; i < 6; i ++) ans = (ans + dfs(1, 1, i)) % mod;
	cout << ans << "\n";

}
/*
f[u][i] = f[v1][j] * f[v2][k]
*/