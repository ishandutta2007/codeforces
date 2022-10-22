#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
typedef std::set<int> set;
typedef std::map<int, std::vector<int>> map;
set s0[maxn], s1[maxn];
int fa[maxn];
int n, m, c, q;
inline int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
map G[maxn];
inline void merge(int x, int y) {
	x = find(x), y = find(y);
	if(x != y) {
		if(s0[x].size() < s0[y].size())
			std::swap(x, y);
		s0[x].insert(s0[y].begin(), s0[y].end()), s0[y].clear();
		s1[x].insert(s1[y].begin(), s1[y].end()), s1[y].clear();
		fa[y] = x;
	}
}
inline void add(int x, int y, int z) {
	map & mp = G[z];
	if(mp.count(x)) merge(mp[x].back(), y);
	if(mp.count(y)) merge(mp[y].back(), x);
	mp[x].push_back(y);
	mp[y].push_back(x);
	s1[find(x)].insert(y);
	s1[find(y)].insert(x);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> c >> q;
	rep(i, 1, n) {
		fa[i] = i;
		s0[i] = s1[i] = {i};
	}
	rep(i, 1, m) {
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	rep(i, 1, q) {
		char opt; int x, y, z;
		cin >> opt;
		if(opt == '+') {
			cin >> x >> y >> z;
			add(x, y, z);
		} else {
			cin >> x >> y;
			cout << (s1[find(x)].count(y) ? "Yes" : "No") << '\n';
		}
	}
}