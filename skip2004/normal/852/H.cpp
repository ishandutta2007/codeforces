#include<bits/stdc++.h>
const int maxn = 210;
using std::cin;
using std::cout;
bool can[maxn][maxn][maxn];
std::bitset<maxn> set[maxn][maxn];
int a[maxn],b[maxn];
int n, k;
typedef long long ll;
inline ll cross(int x, int y, int z) {
	return ll(a[y] - a[x]) * (b[z] - b[x]) - ll(a[z] - a[x]) * (b[y] - b[x]);
}
struct seg { int x, y; };
inline double val(const seg & x) { return std::atan2(b[x.y] - b[x.x], a[x.y] - a[x.x]); }
inline bool cmp0(const seg & x, const seg & y) { return val(x) < val(y); }
inline ll calc(int x, int y, int z) {
	return cross(x, y, z);
}
ll dp[maxn][maxn][60];

inline void up(ll & x, ll y) {
	if(x < y) {
		x = y;
	}
}

int main() { 
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;++i) {
		cin >> a[i] >> b[i];
	}
	for(int i = 1;i <= n;++i) {
		for(int j = 1;j <= n;++j) {
			for(int k = 1;k <= n;++k) if(k != i && k != j && cross(i, j, k) > 0) {
				set[i][j].set(k);
			}
		}
	}
	for(int i = 1;i <= n;++i) {
		for(int j = 1;j <= n;++j) {
			for(int k = 1;k <= n;++k) {
				can[i][j][k] = (set[i][j] & set[j][k] & set[k][i]).none();
			}
		}
	}
	std::vector<seg> vec;
	for(int i = 1;i <= n;++i) {
		for(int j = 1;j <= n;++j) if(i != j) {
			vec.push_back((seg){ i, j });
		}
	}
	sort(vec.begin(), vec.end(), cmp0);
	for(int i = 1;i <= n;++i) {
		for(int j = 1;j <= n;++j) {
			for(int c = 1;c <= k + 1;++c) {
				dp[i][j][c] = -1e18;
			}
		}
		dp[i][i][1] = 0;
	}
	for(const seg & x : vec) {
		for(int i = 1;i <= n;++i) if(can[i][x.y][x.x] && can[i][x.x][x.y]) {
			const ll s = calc(i, x.x, x.y);
			for(int cnt = 1;cnt <= k;++cnt) {
				up(dp[i][x.y][cnt + 1], dp[i][x.x][cnt] + s);
			}
		}
	}
	ll ans = 0;
	for(int i = 1;i <= n;++i) {
		up(ans, dp[i][i][k + 1]);
	}
	printf("%lld.%d0\n", ans >> 1, int(ans % 2 * 5));
}