#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 500200;
typedef long long ll;
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
int size[maxn];
int root;
ll ans;
inline void dfs0(int x, int fa = 0) {
	size[x] = 1;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		dfs0(way[i].to, x);
		size[x] += size[way[i].to];
	}
}
inline ll sqr(int x){ return (ll) x * (x - 1) >> 1; }
inline bool down(ll & x, ll y){ return x > y ? x = y, 1 : 0; }
inline void dfs1(int x, ll sum, int fa = 0) {
	if(fa && down(ans, sum + sqr(size[x]))) root = x;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		dfs1(way[i].to, sum + sqr(size[x] - size[way[i].to]), x);
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
	ans = 1e18;
	dfs1(1, 0);
	dfs0(root);
	dfs1(root, 0);
	cout << sqr(n) * 2 - ans << '\n';
}