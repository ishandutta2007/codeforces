#include<bits/stdc++.h>
const int maxn = 1001000;
using std::cin;
using std::cout;
int n, k;
int head[maxn], next[maxn];
inline void add(int fa, int x) {
	next[x] = head[fa], head[fa] = x;
}
int f[maxn], g[maxn], len[maxn];
inline void dfs0(int x) {
	if(!head[x]) {
		f[x] = g[x] = 1;
	} else {
		len[x] = 1e9;
	}
	int max = 0;
	for(int i = head[x];i;i = next[i]) {
		dfs0(i);
		len[x] = std::min(len[x], len[i] + 1);
		if(len[i] >= k) g[i] = 0;
		g[x] += g[i];
		max = std::max(max, f[i] - g[i]);
	}
	f[x] = max + g[x];
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	for(int i = 2, x;i <= n;++i) {
		cin >> x, add(x, i);
	}
	dfs0(1);
	cout << f[1] << '\n';
}