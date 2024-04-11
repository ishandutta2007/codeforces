#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
const int N = 400005;
const u64 inf = 1e18;

int T, m;

struct pr { u64 l, r; };
inline bool operator < (const pr & x, const pr & y) {
	return x.l < y.l;
}
u64 n, k;
u64 p[N];
pr range[N];

inline u64 calc_least(u64 x) {
	u64 sum = 0;
	for(int i = 0;i <= m;++i) {
		sum += (p[i] + x - 1) / x;
	}
	return sum;
}
inline u64 calc_most(u64 x) {
	u64 sum = 0;
	for(int i = 0;i <= m;++i) {
		sum += p[i] / x;
	}
	return sum;
}
inline void solve() {
	cin >> n >> m >> k;
	for(int i = 0;i < m;++i) cin >> p[i];
	p[m] = n;
	for(int i = m;i >= 1;--i) p[i] -= p[i - 1];

	u64 l = 0, r = n + 1;
	u64 c = m + 1 + k;
	for(;l + 1 < r;) {
		u64 mid = (l + r) >> 1;
		if(calc_least(mid) <= c) {
			r = mid;
		} else {
			l = mid;
		}
	}
	u64 max = r;
	l = 0, r = n + 1;
	for(;l + 1 < r;) {
		u64 mid = (l + r) >> 1;
		if(calc_most(mid) >= c) {
			l = mid;
		} else {
			r = mid;
		}
	}
	u64 min = l;
	int cnt = 0;
	for(int i = 0;i <= m;++i) {
		u64 c0 = (p[i] + max - 1) / max, v0 = p[i] / c0;
		u64 c1 = p[i] / min, v1 = c1 ? (p[i] + c1 - 1) / c1 : inf;
		if(v0 < min && v1 > max) {
			range[cnt++] = (pr){ v0, v1 };
		}
	}
	u64 ans = inf, R = max;
	if(!cnt) ans = max - min;
	else {
		std::sort(range, range + cnt);
		for(int i = 0;i < cnt;++i) ans = std::min(ans, R - range[i].l), R = std::max(range[i].r, R);
		ans = std::min(ans, R - min);
	}
	cout << ans << '\n';
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> T;
	for(int i = 0;i < T;++i) {
		solve();
	}
}