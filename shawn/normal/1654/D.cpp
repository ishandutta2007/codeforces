#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll P = 998244353;
const int N = 2e5 + 10;

struct Edge {
	int v, x, y;
};
vector <Edge> e[N];
vector <pair<int, int> >pri[N];
int cnt[N], mx[N];

ll qpow(ll a, ll b, ll mod = P) {
	ll ret = 1;
	for (; b; b >>= 1, a = a * a % mod) 
		if (b & 1) ret = ret * a % mod;
	return ret;
}

ll inv(ll x) {
	return qpow(x, P - 2);
}

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);

	int maxn = 2e5;
	for (int i = 2; i <= maxn; i ++) {
		int x = i;
		for (int j = 2; j * j <= x; j ++) {
			if (x % j == 0) {
				int y = 0;
				while (x % j == 0) y ++, x /= j;
				pri[i].push_back({j, y});
			}
			
		}
		if (x > 1) pri[i].push_back({x, 1});
	}

	int _, n;
	cin >> _;
	while (_ --) {
		cin >> n;

		for (int i = 1; i <= n; i ++) e[i].clear();
		for (int i = 1; i <= n; i ++) cnt[i] = 0, mx[i] = 0;

		for (int i = 1; i < n; i ++) {
			int u, v, x, y;
			cin >> u >> v >> x >> y;
			e[u].push_back({v, x, y});
			e[v].push_back({u, y, x});
		}

		function<void(int, int)> dfs = [&](int u, int fa){
			// cerr << u << "\n";
			for (auto& [v, x, y]: e[u]) {
				if (v == fa) continue;
				for (auto& [p, i] : pri[y]) cnt[p] -= i;
				for (auto& [p, i] : pri[x]) {
					cnt[p] += i;
					mx[p] = max(mx[p], cnt[p]);
				}
				dfs(v, u);
				for (auto& [p, i] : pri[y]) cnt[p] += i;
				for (auto& [p, i] : pri[x]) cnt[p] -= i;
			}
		};

		dfs(1, 0);
		ll lcm = 1;
		for (int i = 2; i <= n; i ++) {
			lcm = lcm * qpow(i, mx[i]) % P;
		}
		ll ans = 0;
		function<void(int, int, ll)> sum = [&](int u, int fa, ll val){
			ans = (ans + val) % P;
			for (auto& [v, x, y] : e[u]) {
				if (v == fa) continue;
				sum(v, u, val * y % P * inv(x) % P);
			}
		};
		sum(1, 0, lcm);

		cout << ans << "\n";
	}
	return 0;	
}