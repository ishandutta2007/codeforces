#include <bits/stdc++.h>
typedef long long ll;
const ll mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(0);

	int n, m, k;
	std::cin >> n >> m >> k;

	std::vector<std::vector<int> > a(n, std::vector<int>(0));
	std::set<int> ban;
	std::vector<std::vector<int> > vec;

	for (int i = 0; i < n; i ++) {
		int c, x;
		std::cin >> c;
		while (c --) {
			std::cin >> x;
			x --;
			a[i].emplace_back(x);
		}
		std::map<int, int> mp;
		for (auto x: a[i]) mp[x] ++;
		bool flag = true;
		for (auto p: mp) if (p.second >= 2) {
			ban.insert(p.first);
			flag = false;
		}
		if (not flag) {
			for (auto x: a[i]) ban.insert(x);
		}
	}

	std::vector<std::set<int> > g(k), rg(k);
	for (auto v: a) {
		for (int i = 0; i + 1 < v.size(); i ++) {
			g[v[i]].insert(v[i+1]);
			rg[v[i+1]].insert(v[i]);
		}
	}
	std::vector<int> in(k, 0), out(k, 0);
	for (int i = 0; i < k; i ++) {
		out[i] = g[i].size();
		in[i] = rg[i].size();
	}
	for (int i = 0; i < k; i ++) {
		if (in[i] >= 2 || out[i] >= 2)
			ban.insert(i);
	}
	std::function<int(int)> dfs = [&](int x){
		if (ban.count(x)) return -(int)1e9;
		if (out[x] == 0) return 1;
		if (out[x] == 1 && in[*g[x].begin()] == 1) {
			return 1 + dfs(*g[x].begin());
		} 
		return -(int)1e9;
	};

	std::vector<int> F(k + 1, 0);
 	for (int i = 0; i < k; i ++) if (!ban.count(i)) {
		if (in[i] == 0) {
			int len = dfs(i);
			if (len > 0) F[len] ++;
		}
	}
	std::vector<std::pair<int,int> > key;
	for (int i = 0; i <= k; i ++) if (F[i] > 0) {
		key.emplace_back(i, F[i]);
	}
	std::vector<int> dp(m + 1, 0); 
	dp[0] = 1;
	for (int i = 1; i <= m; i ++) {
		for (auto [len, w]: key) {
			assert(len >= 1 && len <= k);
			if (len <= i) {
				dp[i] = (dp[i] + 1ll * w * dp[i - len] % mod) % mod;
			}
		}
	}
	std::cout << dp[m] << "\n";
}