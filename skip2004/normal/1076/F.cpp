#include<bits/stdc++.h>
#define pb push_back
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;
typedef unsigned long long u64;
typedef unsigned u32;
typedef long long ll;

const int mod = 998244353;

inline void reduce(int & x) {
	x += x >> 31 & mod;
}
inline void add(int & x, int y) {
	x += y - mod, x += x >> 31 & mod;
}
inline void sub(int & x, int y) {
	x -= y, x += x >> 31 & mod;
}
inline void fma(int & x, int y, int z) {
	x = (x + (ll) y * z) % mod;
}
inline void up(int & x, int y) {
	if(x < y) x = y;
}
inline void down(int& x, int y) {
	if(x > y) x = y;
}
template<const int *a>
inline int cmp(const int & x, const int & y) {
	return a[x] < a[y];
}

const int maxn = 300300;
int x[maxn], y[maxn];
int n, k;

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int n, k;
	cin >> n >> k;
	int a = 0, b = 0;
	rep(i, 1, n) cin >> x[i];
	rep(i, 1, n) cin >> y[i];
	rep(i, 1, n) {
		if((ll) y[i] * k + (k - a) < x[i] || (ll) x[i] * k + (k - b) < y[i]) {
			puts("NO");
			return 0;
		}
		a = std::max<ll>(0, x[i] - (k - a) - ll(y[i] - 1) * k);
		b = std::max<ll>(0, y[i] - (k - b) - ll(x[i] - 1) * k);
	}
	puts("YES");
}