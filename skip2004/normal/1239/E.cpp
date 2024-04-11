#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
const int maxn = 500;
using std::cin;
using std::cout;
std::mt19937 rd(time(0) + (size_t) new char + * new unsigned long long);
struct sol { int a[50]; } base;
int ans;
int n;


inline void up(int & x, int y) {
	if(x < y) {
		x = y;
	}
}

inline int calc(const sol & x) {
	static int pre[maxn];
	for(int i = 1;i <= n;++i) pre[i] = pre[i - 1] + x.a[i - 1];
	int ans = 0;
	for(int i = n, suf = 0;i >= 1;--i) {
		up(ans, pre[i] + (suf += x.a[i + n - 1]));
	}
	return ans;
}

namespace fire {
	void update(sol & a, int & ans) {
		for(int i = 0;i < n + n;++i) {
			for(int j = 0;j < i;++j) {
				std::swap(a.a[i], a.a[j]);
				int v = calc(a);
				if(v < ans) {
					ans = v;
				} else {
					std::swap(a.a[i], a.a[j]);
				}
			}
		}
	}
	void main() {
		sol now = base; 
		for(int i = 0;i < 3;++i) std::swap(now.a[rd() % (n + n)], now.a[rd() % (n + n)]);
		int val = calc(now);
		if(val < ans) {
			ans = val;
			base = now;
		}
		for(double t = 300;t >= 1e-13;t *= 0.95) {
			int x, y;
			do {
				x = rd() % (n + n);
				y = rd() % (n + n);
			} while(x == y);
			std::swap(now.a[x], now.a[y]);
			int v = calc(now);
			if(v < ans) {
				ans = v;
				base = now;
			}
			if(v <= val || exp((val - v) / t) > (double) rd() / rd.max()) {
			} else {
				std::swap(now.a[x], now.a[y]);
			}
		}
	}
}
sol out;
int best;
int A[maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 0;i < n + n;++i) cin >> base.a[i], A[i] = base.a[i];
	std::sort(A, A + n + n);
	out = base, best = calc(base);
	for(int i = 1;i <= 40;++i) {
		for(int i = 0;i < n;++i) base.a[i] = A[i + i], base.a[i + n] = A[i + i + 1];
		ans = calc(base), fire::update(base, ans);
		size_t t = clock();
		do {
			fire::main();
		} while(double(clock() - t) / CLOCKS_PER_SEC < 0.1);
		if(ans < best) {
			best = ans;
			out = base;
		}
		static int cnt;
		// cnt += ans == 118787;
		// cout << cnt << '/' << i << std::endl;
	}
	for(int i = 0;i < n + n;++i) {
		cout << out.a[i] << " \n"[i % n == n - 1];
	}
}