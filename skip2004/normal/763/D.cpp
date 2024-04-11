#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef unsigned long long ll;
const int mod = 998244353;
int n;
struct T {
	int to, nxt;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}
struct Map {
	std::unordered_map<ll, int> mp;
	int cnt;
	inline Map() { mp.rehash(2e7 + 7); }
	inline void add(ll x) { cnt += ++mp[x] == 1; }
	inline void dec(ll x) { cnt -= --mp[x] == 0; }
} map;
ll hsh[maxn];
const ll V = 1145141919810;
inline ll T(ll x) {
	x ^= V;
	x ^= x << 17;
	x ^= x >> 42;
	x ^= x >> 8;
	return x;
}
inline void dfs0(int x, int fa = 0) {
	hsh[x] = 123128120398403;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		dfs0(way[i].to, x);
		hsh[x] += T(hsh[way[i].to]);
	}
	map.add(hsh[x]);
}
int ans, root;
inline void dfs1(int x, int fa = 0) {
	if(map.cnt > ans) {
		ans = map.cnt;
		root = x;
	}
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		map.dec(hsh[x]), map.dec(hsh[way[i].to]);
		hsh[x] -= T(hsh[way[i].to]);
		hsh[way[i].to] += T(hsh[x]);
		map.add(hsh[x]), map.add(hsh[way[i].to]);
		dfs1(way[i].to, x);
		map.dec(hsh[x]), map.dec(hsh[way[i].to]);
		hsh[way[i].to] -= T(hsh[x]);
		hsh[x] += T(hsh[way[i].to]);
		map.add(hsh[x]), map.add(hsh[way[i].to]);
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1, x, y;i < n;++i) {
		cin >> x >> y;
		link(x, y);
	}
	dfs0(1);
	dfs1(1);
	cout << root << '\n';
}