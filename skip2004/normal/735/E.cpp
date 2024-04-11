#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200;
typedef long long ll;
const int mod = 1e9 + 7;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int n, k;
struct T {
	int to, nxt;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}
int M;
int dp[maxn][maxn][maxn];
int dep[maxn];
int max[maxn];
// dp ijk : in subtree i, nearest black j, deepest bad node k
inline void dfs0(int x,int fa = 0) {
	max[x] = dep[x] = dep[fa] + 1;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		dfs0(way[i].to, x);
		max[x] = std::max(max[x], max[way[i].to]);
	}
	dp[x][M][dep[x]] = dp[x][dep[x]][0] = 1;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		int to = way[i].to;
		static int a[maxn][maxn];
		for(int i0 = dep[x];i0 <= M;i0 = i0 == max[x] ? M : i0 + 1) 
			for(int i1 = 0;i1 <= dep[x] + k;i1 = i1 ? i1 + 1 : dep[x]) 
				a[i0][i1] = 0;
		for(int i0 = dep[x];i0 <= M;i0 = i0 == max[x] ? M : i0 + 1) {
			for(int i1 = 0;i1 <= dep[x] + k;i1 = i1 ? i1 + 1 : dep[x]) {
				for(int i2 = dep[x];i2 <= M;i2 = i2 == max[x] ? M : i2 + 1) {
					for(int i3 = 0;i3 <= dep[x] + k;i3 = i3 ? i3 + 1 : dep[x]) {
						const int min = std::min(i0, i2);
						int max = 0;
						if(i3 && i0 + i3 > k + dep[x] + dep[x] && i3 > max) max = i3;
						if(i1 && i2 + i1 > k + dep[x] + dep[x] && i1 > max) max = i1;
						a[min][max] = (a[min][max] + (ll) dp[x][i0][i1] * dp[to][i2][i3]) % mod;
					}
				}
			}
		}
		for(int i0 = dep[x];i0 <= M;i0 = i0 == max[x] ? M : i0 + 1) 
			for(int i1 = 0;i1 <= dep[x] + k;i1 = i1 ? i1 + 1 : dep[x]) 
				dp[x][i0][i1] = a[i0][i1];
	}
}
int main() {
	using std::cin; using std::cout;
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k, M = n + k + 1;
	for(int i = 1;i < n;++i) {
		int x, y;
		cin >> x >> y;
		link(x, y);
	}
	dfs0(1);
	int ans = 0;
	for(int j = 0;j <= n;++j) ans = (ans + dp[1][j][0]) % mod;
	cout << ans << '\n';
}