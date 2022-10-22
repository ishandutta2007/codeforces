#include<bits/stdc++.h>
const int maxn = 100100;
int n;
struct T {
	int to, nxt;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}
int ans[maxn];
int dp[maxn], sum, len;
int head[maxn], next[maxn];
inline void dfs(int x, int fa = 0) {
	if(fa) next[x] = head[fa], head[fa] = x;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		dfs(way[i].to, x);
	}
}

inline void dfs0(int x) {
	int max = 0, nmax = 0;
	for(int i = head[x];i;i = next[i]) {
		dfs0(i);
		if(dp[i] > max) {
			nmax = max;
			max = dp[i];
		} else {
			if(dp[i] > nmax) {
				nmax = dp[i];
			}
		}
	}
	if(++max + nmax >= len) {
		++ sum;
		dp[x] = 0;
	} else {
		dp[x] = max;
	}
}
inline int cal(int x) {
	sum = 0;
	len = x;
	dfs0(1);
	return sum;
}
inline int calc(int x) {
	return ~ans[x] ? ans[x] : ans[x] = cal(x);
}
inline void solve(int l, int r) {
	int left = calc(l), right = calc(r);
	if(left == right) {
		std::fill(ans + l, ans + r + 1, left);
		return ;
	}
	int mid = l + r >> 1;
	solve(l, mid);
	solve(mid + 1, r);
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for(int i = 1, x, y;i < n;++i) {
		std::cin >> x >> y;
		link(x, y);
	}
	memset(ans, -1, sizeof ans);
	dfs(1);
	solve(1, n);
	for(int i = 1;i <= n;++i) {
		std::cout << ans[i] << '\n';
	}
}