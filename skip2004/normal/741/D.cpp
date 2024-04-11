#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 500200;
std::mt19937 rd(time(0));
inline void up(int & x,int y) {
	if(x < y) x = y;
}
typedef unsigned long long u64;
int n;
struct set {
	std::unordered_map<int, int> s;
	int tag, add;
	inline void pb(int x, int len) { up(s[x ^ tag], len - add); }
	inline void put(int x){ tag ^= x; }
	inline int test(int v) { return s.count(v ^= tag) ? s[v] + add : -1e9; }
} s[maxn];
int h[maxn], nxt[maxn], c[maxn];
inline void link(int f,int x, int v) {
	nxt[x] = h[f], h[f] = x, c[x] = v;
}
int ans[maxn], size[maxn], son[maxn];
int mp[256];
inline void dfs1(int x) {
	size[x] = 1;
	for(int i = h[x];i;i = nxt[i]) {
		dfs1(i);
		size[x] += size[i];
		if(size[i] > size[son[x]]) son[x] = i;
	}
}
inline void dfs0(int x) {
	int & ans = ::ans[x];
	s[x].add = -n; s[x].pb(0, 0);
	if(int i = son[x]) {
		dfs0(i), s[i].put(mp[c[i]]), ++s[i].add;
		std::swap(s[x], s[i]);
	}
	if(s[x].s.size() * 1.5 < size[x]) s[x].s.rehash(size[x] << 1);
	for(int i = h[x];i;i = nxt[i]) {
		if(i != son[x]) dfs0(i), s[i].put(mp[c[i]]), ++s[i].add;
		for(auto j : s[i].s) {
			up(ans, s[x].test(j.first ^ s[i].tag) + j.second + s[i].add);
			rep(k, 'a', 'z') up(ans, s[x].test(j.first ^ s[i].tag ^ mp[k]) + j.second + s[i].add);
		}
		for(auto j : s[i].s) {
			s[x].pb(j.first ^ s[i].tag, j.second + s[i].add);
		}
		up(ans, ::ans[i]);
		s[i].s.clear();
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 'a', 'z') mp[i] = rd();
	rep(i, 2, n) {
		int fa; char c;
		cin >> fa >> c;
		link(fa, i, c);
	}
	dfs1(1);
	dfs0(1);
	rep(i, 1, n) {
		cout << ans[i] << ' ';
	}
}