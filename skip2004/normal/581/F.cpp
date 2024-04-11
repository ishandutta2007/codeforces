#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
const int N = 5050;
int n;
struct edge {
	int to, nxt;
} e[N << 1];
int h[N], num;
inline void link(int x, int y) {
	e[++num] = {y, h[x]}, h[x] = num;
	e[++num] = {x, h[y]}, h[y] = num;
}

int dp[2][N][N];
int size[N];

inline void down(int & x, int y) {
	if(x > y) x = y;
}
inline void dfs0(int x, int fa = 0) {
	if(e[h[x]].nxt) {
		dp[0][x][0] = 0;
		dp[1][x][0] = 0;
		for(int i = h[x];i;i = e[i].nxt) if(e[i].to != fa) {
			dfs0(e[i].to, x);
			static int res[2][N];
			rep(u, 0, size[x] + size[e[i].to]) res[0][u] = res[1][u] = n;

			rep(c0, 0, 1) rep(c1, 0, 1) 
				rep(i0, 0, size[x]) 
					rep(i1, 0, size[e[i].to]) 
						down(res[c0][i0 + i1], dp[c0][x][i0] + dp[c1][e[i].to][i1] + (c0 != c1));

			rep(u, 0, size[x] + size[e[i].to]) {
				dp[0][x][u] = res[0][u];
				dp[1][x][u] = res[1][u];
			}

			size[x] += size[e[i].to];
		}
	} else {
		size[x] = 1;
		dp[0][x][0] = 0;
		dp[1][x][1] = 0;
	}
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1, x, y;i < n;++i) {
		cin >> x >> y;
		link(x, y);
	}
	if(n == 2) return puts("1"), 0;
	int root = 0, cnt = 0;;
	rep(i, 1, n) {
		if(e[h[i]].nxt) root = i;
		else ++ cnt;
	}
	rep(i, 1, n) rep(j, 0, n) dp[0][i][j] = dp[1][i][j] = n + 1;
	dfs0(root);

	cout << std::min(dp[0][root][cnt >> 1], dp[1][root][cnt >> 1]) << '\n';
}