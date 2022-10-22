#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 16;
typedef long long ll;
const int mod = 998244353;
#define popc __builtin_popcount
int n, a[maxn], b[maxn];
int sr, sb;
int f[1 << maxn][maxn * maxn];
inline void up(int & x, int y) {
	if(x < y) {
		x = y;
	}
}
inline void down(int & x, int y) {
	if(x > y) {
		x = y;
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	int sumr = 0, sumb = 0;
	for(int i = 0;i < n;++i) {
		char c; 
		cin >> c;
		(c == 'R' ? sr : sb) |= 1 << i;
		cin >> a[i] >> b[i];
		sumr += a[i];
		sumb += b[i];
	}
	const int N = n * (n - 1) >> 1;
	for(int i = 0;i < 1 << n;++i) for(int j = 0;j <= N;++j) {
		f[i][j] = -1e9;
	}
	f[0][0] = 0;
	for(int i = 0;i < 1 << n;++i) {
		int cr = popc(i & sr), cb = popc(i & sb);
		rep(j, 0, popc(i) * (popc(i) - 1) >> 1) {
			rep(k, 0, n - 1) if((i >> k & 1) == 0) {
				const int R = std::min(cr, a[k]), B = std::min(cb, b[k]);
				up(f[i | 1 << k][j + R], f[i][j] + B);
			}
		}
	}
	int ans = 1e9;
	rep(j, 0, N) {
		down(ans, std::max(sumr - j, sumb - f[(1 << n) - 1][j]));
	}
	cout << ans + n << '\n';
}