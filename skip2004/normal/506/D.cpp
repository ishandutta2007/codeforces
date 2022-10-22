#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
typedef std::pair<int, int> pr;

const int N = 100100;
using set = std::bitset<N>;

int n, m, q;
int u[N], v[N];
int fa[N];
std::vector<pr> vec[N];

std::vector<int> in[N];

pr edge[N]; 
int ans[N];

int cnt[N];
std::vector<const std::vector<int>*> which[N];
std::vector<int> ask[N];

inline int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	rep(i, 1, m) {
		int x, y, c;
		cin >> x >> y >> c;
		vec[c].emplace_back(x, y);
	}
	cin >> q;
	rep(i, 1, q) cin >> u[i] >> v[i], ask[u[i]].push_back(i);
	std::vector<std::vector<int>> set;
	rep(i, 1, m) {
		std::vector<int> node;
		for(auto x : vec[i]) {
			node.push_back(x.first);
			node.push_back(x.second);
		}
		sort(node.begin(), node.end());
		node.erase(unique(node.begin(), node.end()), node.end());
		for(int x : node) fa[x] = x, in[x].clear();
		for(auto x : vec[i]) fa[find(x.first)] = find(x.second);
		for(int x : node) in[find(x)].push_back(x);
		for(int x : node) if(fa[x] == x) {
			set.push_back(in[x]);
		}
	}
	const int lim = 500;
	for(const auto&x : set) {
		if(x.size() >= lim) {
			static bool yes[N];
			memset(yes + 1, 0, n);
			for(int u : x) yes[u] = 1;
			rep(i, 1, n) ans[i] += yes[u[i]] && yes[v[i]];
		} else {
			for(int u : x) which[u].push_back(&x);
		}
	}
	rep(i, 1, n) {
		for(const auto & x : which[i]) for(int u : *x) ++ cnt[u];
		for(const auto & x : ask[i]) ans[x] += cnt[v[x]];
		for(const auto & x : which[i]) for(int u : *x) -- cnt[u];
	}
	rep(i, 1, q) {
		cout << ans[i] << '\n';
	}
}