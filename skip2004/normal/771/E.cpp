#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 300001;
typedef long long ll;
const int mod = 998244353;
int n;
int t[3][maxn];
int a[maxn], b[maxn], c[maxn];
int dp[maxn];
inline void up(int & x, int y) {
	if(x < y) {
		x = y;
	}
}
inline void init(int * a, int * b) {
	std::map<ll, int> map;
	ll s = 0;
	map[0] = 0;
	b[0] = -1;
	rep(i, 1, n) {
		s += a[i];
		if(map.count(s)) {
			b[i] = map[s];
		} else {
			b[i] = -1;
		}
		up(b[i], b[i - 1]);
		map[s] = i;
	}
}
std::map<int, int> map[maxn];
inline int calc(int x, int y) {
	if(map[x].count(y)) return map[x][y];
	int & ans = map[x][y] = 0;
	if(a[x] > b[y]) up(ans, calc(a[x], y) + 1);
	if(b[y] >= 0 && a[x] <= b[y]) up(ans, calc(x, b[y]) + 1);
	int d = c[std::min(x, y)];
	if(d >= 0) up(ans, calc(d, d) + 1);
	return ans;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) cin >> t[0][i];
	rep(i, 1, n) cin >> t[1][i];
	rep(i, 1, n) t[2][i] = t[0][i] + t[1][i];
	init(t[0], a), init(t[1], b), init(t[2], c);
	cout << calc(n, n) << '\n';
}