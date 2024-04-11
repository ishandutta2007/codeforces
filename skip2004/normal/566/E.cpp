#include<bits/stdc++.h>
const int maxn = 1001;
const int mod = 998244353;
typedef long long ll;
inline ll pow(ll a,int b,ll ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1) ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
inline void reduce(int & x){ x += x >> 31 & mod; }
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
typedef std::bitset<maxn> set;
set s[maxn], all;
set near[maxn];
set sons[maxn];
int n, ok[maxn];
std::set<int> nodes;
set nodes_set;
std::set<std::pair<int,int>> edge;
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	if(n <= 2) return puts("1 2"), 0;
	for(int i = 1;i <= n;++i) all.set(i);
	for(int i = 1, x, y;i <= n;++i) for(std::cin >> x;x--;)
		std::cin >> y,s[i].set(y);
	for(int i = 1;i <= n;++i) for(int j = i + 1;j <= n;++j) {
		static set t; (t = s[i]) &= s[j];
		if(t.count() == 2) {
			int x = t._Find_first(); t.reset(x);
			int y = t._Find_first();
			edge.emplace(x, y);
			nodes.emplace(x);
			nodes.emplace(y);
			nodes_set.set(x);
			nodes_set.set(y);
		}
	}
	if(edge.size() == 0) {
		for(int i = 2;i <= n;++i) std::cout << 1 << ' ' << i << '\n';
		return 0;
	}
	if(edge.size() == 1) {
		int x = edge.begin() -> first;
		int y = edge.begin() -> second;
		for(int i = 1;i <= n;++i) if(s[i] != all) {
			for(int j = 1;j <= n;++j) if(j != x && j != y)
				edge.emplace(s[i].test(j) ? x : y, j);
			break;
		}
		for(auto i : edge) std::cout << i.first << ' ' << i.second << '\n';
		return 0;
	}
	for(auto i : edge) {
		near[i.first].set(i.second);
		near[i.second].set(i.first);
	}
	for(int j : nodes) near[j].set(j);
	for(int j : nodes) if(near[j].count() != 2) {
		sons[j] = all;
		for(int i = 1;i <= n;++i) if((s[i] & near[j]) == near[j]) sons[j] &= s[i];
		sons[j] ^= near[j];
		for(int i = sons[j]._Find_first();i < maxn;i=sons[j]._Find_next(i))
			edge.emplace(std::min(i, j), std::max(i, j));
	}
	for(int i = 1;i <= n;++i) if((s[i] & nodes_set).count() == 2) {
		set o = s[i] & nodes_set; s[i] ^= o;
		std::vector<int> vector;
		for(int j = s[i]._Find_first();j < maxn;j = s[i]._Find_next(j)) 
			vector.push_back(j);
		for(int i = o._Find_first();i < maxn;i = o._Find_next(i)) if(near[i].count() == 2) 
			for(int j : vector) edge.emplace(std::min(i, j), std::max(i, j));
	}
	for(auto i : edge) std::cout << i.first << ' ' << i.second << '\n';
}