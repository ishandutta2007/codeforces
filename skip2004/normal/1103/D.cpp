#include<bits/stdc++.h>

typedef long long ll;

using std::cin;
using std::cout;

const int maxn = 1001000;
int n, m;
ll k;
ll a[maxn];
ll cost[maxn];

inline std::vector<ll> fct(ll gcd) {
	std::vector<ll> vec;
	for(ll i = 2;i * i <= gcd;++i)
		for(;gcd % i == 0;gcd /= i)
			vec.push_back(i);
	if(gcd > 1) vec.push_back(gcd);
	return vec;
}
inline bool down(ll & x, ll y) {
	return x > y ? x = y, true : false;
}
ll dp[14][1 << 13];
int can[1 << 13];
inline void fill(int x) {
	if(can[x]) return ;
	can[x] = 1;
	for(int i = 0;i < m;++i) if((x >> i & 1) == 0)
		fill(x ^ 1 << i);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	ll gcd = 0;
	for(int i = 0;i < n;++i) {
		cin >> a[i];
		gcd = std::__gcd(gcd, a[i]);
	}
	for(int i = 0;i < n;++i) {
		cin >> cost[i];
	}
	std::vector<ll> vec = fct(gcd);;
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	m = vec.size();
	std::unordered_map<ll, std::vector<ll>> map;
	map.reserve(2e6 + 7);
	map.rehash(2e6 + 7);
	for(int i = 0;i < n;++i) {
		ll val = a[i], mul = 1;
		for(auto i : vec) for(;val % i == 0;) val /= i, mul *= i;
		map[mul].push_back(cost[i]);
	}
	for(int i = 0;i <= m;++i) {
		for(int j = 0;j < 1 << m;++j) {
			dp[i][j] = 1e17;
		}
	}
	dp[0][(1 << m) - 1] = 0;
	for(auto x : map) {
		auto & num = x.second;
		sort(num.begin(), num.end());
		if((int) num.size() > m) num.resize(m);
		static std::vector<int> use;
		use.clear();
		for(int j = 0;j < 1 << m;++j) {
			can[j] = 0;
		}
		for(int j = 0;j < 1 << m;++j) {
			ll v = x.first;
			for(int k = 0;k < m;++k) if((j >> k & 1) == 0) {
				for(;v % vec[k] == 0;)
					v /= vec[k];
			}
			if(x.first / v <= k) use.push_back(j);
		}
		for(ll cost : num) {
			int succ = 0;
			for(int i = m - 1;i >= 0;--i) {
				for(int k : use) {
					for(int j = k;;j = j - 1 & k) {
						int s = ~j & (1 << m) - 1;
						succ = down(dp[i + 1][s & k], dp[i][s] + cost) || succ;
						if(!j) break;
					}
				}
			}
			if(!succ) break;
		}
	}
	ll ans = 1e18;
	for(int i = 0;i <= m;++i)
		if(dp[i][0] < 1e17)
			down(ans, dp[i][0] * i);
	cout << (ans < 1e17 ? ans : -1) << '\n';
}