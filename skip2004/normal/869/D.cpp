#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 100100;
const int mod = 1e9 + 7;
typedef long long ll;
int n, m;
struct T {
	int to, nxt;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}
int x[maxn], y[maxn];
int val[maxn];
std::map<int, int> map;
int idx;
inline void test(int x) {
	if(1 <= x && x <= n && !map.count(x)) map[x] = ++ idx;
}
inline void upt(int x) {
	for(;x && !map.count(x);x >>= 1) {
		test(x), test(x + x), test(x + x + 1);
	}
	test(x + x), test(x + x + 1);
}
inline int chk(int x, int n) {
	for(;n > x;) n >>= 1;
	return n == x;
}
inline int insub(int x, int n) {
	if(x > n) return 0;
	if(!chk(x, n)) return insub(x + x, n) * 2 + 1;
	return insub(x + x, n) + insub(x + x + 1, n) + 1;
}
inline void dfs(int x) {
	if(x > n) return ;
	if(!map.count(x)) {
		exit(1);
	}
	if(!map.count(x << 1) && !map.count(x << 1 | 1)) {
		val[map[x]] = insub(x, n);
		return ;
	}
	dfs(x << 1);
	dfs(x << 1 | 1);
	if(map.count(x << 1))
		link(map[x], map[x << 1]);
	if(map.count(x << 1 | 1))
		link(map[x], map[x << 1 | 1]);
	val[map[x]] = 1;
}
int vis[maxn];
ll ans = 0;
inline void dfs0(int x, int start) {
	ans = (ans + (ll) start * val[x]) % mod;
	vis[x] = 1;
	for(int i = h[x];i;i = way[i].nxt) if(!vis[way[i].to]) {
		dfs0(way[i].to, start);
	}
	vis[x] = 0;
}
int main() {
	cin >> n >> m;
	upt(1);
	for(int i = 1;i <= m;++i) {
		cin >> x[i] >> y[i];
		upt(x[i]);
		upt(y[i]);
	}
	dfs(1);
	for(int i = 1;i <= m;++i) {
		link(map[x[i]], map[y[i]]);
	}
	for(int i = 1;i <= idx;++i) {
		dfs0(i, val[i]);
	}
	cout << ans << '\n';
}