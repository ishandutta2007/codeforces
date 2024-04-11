#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 100100;

typedef long long ll;

int a0[maxn], c0[maxn];
int a1[maxn], c1[maxn];

inline void put(int * a, int * c, int l, int r, int x) {
	for(int i = l;i < r;++i) {
		if(a[i] > x) a[i] = x;
		c[i] = 1;
	}
}
inline ll ask(int l, int r) {
	ll ans = 0;
	for(int i = l;i < r;++i) {
		if(c0[i] && c1[i]) {
			ans += a0[i] + a1[i];
		}
	}
	return ans;
}
int q;
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> q;
	for(int i = 1;i <= 100000;++i) a0[i] = a1[i] = 1e9 + 10;
	for(int i = 0, opt, l, r, k;i < q;++i) {
		cin >> opt >> l >> r;
		if(opt == 1) {
			cin >> k;
			if(k > 0) put(a0, c0, l, r, k);
			else put(a1, c1, l, r, -k);
		} else {
			cout << ask(l, r) << '\n';
		}
	}
}