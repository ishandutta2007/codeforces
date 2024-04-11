#include<bits/stdc++.h>
const int maxn = 510;
typedef long long ll;
using std::cin;
using std::cout;
using std::vector;
int n, k;
std::vector<std::pair<int, int>> dp[maxn][11];
int ch[maxn][10], cnt[maxn], root, tot;

inline void down(int & x, int y) {
	if(x > y) x = y;
}

inline void ins(const std::string & s, int ad) {
	int x = root;
	for(const char & i : s) {
		int & c = ch[x][i - '0'];
		if(!c) c = ++ tot;
		x = c;
	}
	cnt[x] += ad;
}

inline void dfs(int x) {
	std::unordered_map<int, int> map[11];
	dp[x][0].emplace_back(0, 0);
	for(int i = 0;i < 10;++i) if(ch[x][i]) {
		dfs(ch[x][i]);
		auto&to = dp[ch[x][i]];
		for(int i0 = 0;i0 <= k;++i0) for(const auto&v0 : dp[x][i0]) {
			for(int i1 = 0;i0 + i1 <= k;++i1) for(const auto&v1 : to[i1]) {
				if(!map[i0 + i1].count(v0.first + v1.first)) {
					map[i0 + i1][v0.first + v1.first] = v0.second + v1.second;
				} else {
					down(map[i0 + i1][v0.first + v1.first], v0.second + v1.second);
				}
			}
		}
		for(int i0 = 0;i0 <= k;++i0) {
			dp[x][i0].clear();
			for(const auto & v : map[i0]) {
				dp[x][i0].push_back(v);
			}
			map[i0].clear();
		}
	}
	std::vector<std::pair<int, int>> vec[11];
	for(int i0 = 0;i0 <= k;++i0) {
		int min = 1e9;
		for(const auto & i : dp[x][i0]) {
			int c = i.first + cnt[x], v = i.second + i.first;
			down(min, v);
			vec[i0].emplace_back(c, v);
		}
		if(i0 != k) {
			vec[i0 + 1].emplace_back(0, min);
		}
		sort(vec[i0].begin(), vec[i0].end());
		dp[x][i0].clear();
		min = 1e9;
		for(const auto & i : vec[i0]) {
			if(i.second < min) {
				min = i.second;
				dp[x][i0].push_back(i);
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	root = tot = 1;
	cin >> n >> k;
	for(int i = 0;i < n;++i) {
		std::string s; int cnt;
		cin >> s >> cnt;
		ins(s, cnt);
	}
	dfs(1);
	int ans = 1e9;
	for(int i = 0;i <= k;++i) {
		for(auto j : dp[1][i]) {
			down(ans, j.second);
		}
	}
	cout << ans << '\n';
}