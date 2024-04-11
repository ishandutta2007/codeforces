#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
const int maxn = 5010;
using std::cin;
using std::cout;
struct T { int x, y; };
struct seg { T x, y; };
struct sg {
	int x, a0, a1;
	inline sg() {}
	inline sg(int a, int b, int c) { x = a, a0 = std::min(b, c), a1 = std::max(b, c); }
};
seg a[maxn];
sg a0[maxn];
sg a1[maxn];
int n;
int n0, n1;
typedef int AI[maxn / 32 + 1];
inline void flip(AI & x, int pos) { x[pos >> 5] |= 1 << (pos & 31); }
const int N = 10001;
AI less0[N], greater0[N];
AI less1[N], greater1[N];
int M;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 0;i < n;++i) {
		cin >> a[i].x.x >> a[i].x.y >> a[i].y.x >> a[i].y.y;
		a[i].x.x += 5000;
		a[i].x.y += 5000;
		a[i].y.x += 5000;
		a[i].y.y += 5000;
		if(a[i].x.x == a[i].y.x) {
			a0[++n0] = sg(a[i].x.x, a[i].x.y, a[i].y.y);
		} else {
			a1[++n1] = sg(a[i].x.y, a[i].x.x, a[i].y.x);
		}
	}
	if(n0 > n1) {
		std::swap(a0, a1);
		std::swap(n0, n1);
	}
	for(int i = 0;i < N;++i) {
		for(int j = 1;j <= n1;++j) {
			if(a1[j].a0 <= i) flip(less0[i], j);
			if(i <= a1[j].a1) flip(greater0[i], j);
			if(a1[j].x <= i) flip(less1[i], j);
			if(i <= a1[j].x) flip(greater1[i], j);
		}
	}
	int M = n1 >> 5;
	long long ans = 0;
	for(int i = 1;i <= n0;++i) {
		for(int j = i + 1;j <= n0;++j) {
			const int miny = std::max(a0[i].a0, a0[j].a0);
			const int maxy = std::min(a0[i].a1, a0[j].a1);
			if(miny < maxy) {
				int cnt = 0;
				int * a2 = less0[std::min(a0[i].x, a0[j].x)], * a3 = greater0[std::max(a0[i].x, a0[j].x)];
				int * a0 = greater1[miny], * a1 = less1[maxy];
				for(int k = 0;k <= M;++k) {
					cnt += __builtin_popcount(a0[k] & a1[k] & a2[k] & a3[k]);
				}
				ans += cnt * (cnt - 1) >> 1;
			}
		}
	}
	cout << ans << '\n';
}