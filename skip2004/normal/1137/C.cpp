#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int N = 100100;
const int D = 60;
const int M = N * D;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int n, m, d;
int x[N], y[N];
char s[N][D];
struct T {
	int to, nxt;
} way[M];
int h[M], num;
inline void link(int x,int y) {
	way[++num] = {y, h[x]}, h[x] = num;
}
inline int node(int week, int node) {
	return (week - 1) * n + node;
}
int dfn[M], low[M], st[M], in[M], bl[M], top, idx, cnt, tot;
int is[M], dp[M];
inline void dfs(int x) {
	dfn[x] = low[x] = ++ tot, st[++top] = x, in[x] = 1;
	for(int i = h[x];i;i = way[i].nxt) {
		if(!dfn[way[i].to]) {
			dfs(way[i].to);
			low[x] = std::min(low[x], low[way[i].to]);
		} else {
			if(in[way[i].to]) {
				low[x] = std::min(low[x], dfn[way[i].to]);
			}
		}
	}
	if(low[x] == dfn[x]) {
		++ cnt;
		do {
			bl[st[top]] = cnt;
			in[st[top]] = 0;
		} while(st[top--] != x); 
	}
}
inline void dfs1(int x) {
	in[x] = 1; int max = 0;
	for(int i = h[x];i;i = way[i].nxt) {
		if(!in[way[i].to]) dfs1(way[i].to);
		if(dp[way[i].to] > max) max = dp[way[i].to];
	}
	dp[x] += max;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> d;
	rep(i, 1, m) {
		cin >> x[i] >> y[i];
	}
	rep(i, 1, n) cin >> s[i] + 1;
	rep(i, 1, d) rep(j, 1, m) {
		link(node(i, x[j]), node(i % d + 1, y[j]));
	}
	rep(i, 1, n * d) if(!dfn[i]) {
		dfs(i);
	}
	rep(i, 1, n * d) h[i] = 0;
	num = 0;
	rep(i, 1, d) rep(j, 1, m) {
		int a = node(i, x[j]), b = node(i % d + 1, y[j]);
		if(bl[a] != bl[b]) {
			link(bl[a], bl[b]);
		}
	}
	rep(i, 1, n) {
		rep(j, 1, d) if(s[i][j] == '1') {
			int & x = is[bl[node(j, i)]];
			if(x != i) dp[bl[node(j, i)]] += 1, x = i;
		}
	}
	int ans = 0;
	dfs1(bl[1]);
	if(dp[bl[1]] > ans) ans = dp[bl[1]];
	cout << ans << '\n';
}