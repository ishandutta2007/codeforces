#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
const int N = 7050;
typedef std::bitset<N> set;
set left, right;
int n, m, d;
int a[maxn];
int x[maxn];
inline int min(const set & x) { return x._Find_first(); }
inline void up(double & x, double y) {
	if(x < y) {
		x = y;
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> d;
	rep(i, 1, n) {
		cin >> a[i];
	}
	a[n + 1] = 2e9;
	cin >> m;
	rep(i, 1, m) {
		static int i0 = 1, i1 = 1;
		cin >> x[i];
		left <<= x[i] - x[i - 1];
		right >>= x[i] - x[i - 1];
		for(;a[i0] < x[i];++ i0) {
			if(x[i] - a[i0] - 1 < N) {
				left.set(x[i] - a[i0] - 1);
			}
		}
		for(;a[i1] < x[i] + N;++ i1) {
			if(x[i] <= a[i1]) {
				right.set(a[i1] - x[i]);
			}
		}
		double out = atan2(1, std::min(min(left), min(right)));
		up(out, 2 * atan2(1, min(left & right)));
		up(out, 2 * atan2(1, min(left & right << 1)));
		up(out, 2 * atan2(1, min(left << 1 & right)));
		printf("%.12lf\n", out);
	}
}