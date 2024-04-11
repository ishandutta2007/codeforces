#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
const int maxn = 4096;
int w, n, q;
int cnt[maxn], a[maxn], g[maxn];
#define def(name, opt) inline void name(int & x, int & y) { opt; }
def(AF, x += y);
def(IAF, x -= y);
def(OF, y += x);
def(IOF, y -= x);
def(XF, int t = y; y = x - y; x += t);
def(IXF, int t = y; y = x - y >> 1; x = x + t >> 1);


inline void fwt(int * a, int A, int O, int X) {
	for(int i = 1;i < 1 << w;i <<= 1) {
		if(A & i) for(int j = 0;j < 1 << w;j += i + i) for(int k = 0;k < i;++k) AF(a[j + k], a[i + j + k]);
		if(O & i) for(int j = 0;j < 1 << w;j += i + i) for(int k = 0;k < i;++k) OF(a[j + k], a[i + j + k]);
		if(X & i) for(int j = 0;j < 1 << w;j += i + i) for(int k = 0;k < i;++k) XF(a[j + k], a[i + j + k]);
	}
}
inline void ifwt(int * a, int A, int O, int X) {
	for(int i = 1;i < 1 << w;i <<= 1) {
		if(A & i) for(int j = 0;j < 1 << w;j += i + i) for(int k = 0;k < i;++k) IAF(a[j + k], a[i + j + k]);
		if(O & i) for(int j = 0;j < 1 << w;j += i + i) for(int k = 0;k < i;++k) IOF(a[j + k], a[i + j + k]);
		if(X & i) for(int j = 0;j < 1 << w;j += i + i) for(int k = 0;k < i;++k) IXF(a[j + k], a[i + j + k]);
	}
}
int main() { 
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	using std::cin;
	using std::cout;
	cin >> w >> n >> q;
	for(int i = 0, x;i < n;++i) {
		cin >> x;
		++ cnt[x];
	}
	for(int i = 0;i < q;++i) {
		int A = 0, O = 0, X = 0, a = 0, o = 0, x = 0;
		for(int j = w - 1;j >= 0;--j) {
			char c; cin >> c;
			if(c == 'A') A |= 1 << j;
			if(c == 'O') O |= 1 << j;
			if(c == 'X') X |= 1 << j;
			if(c == 'a') a |= 1 << j;
			if(c == 'o') o |= 1 << j;
			if(c == 'x') x |= 1 << j;
		}
		for(int i = 0;i < 1 << w;++i) g[i] = cnt[i];
		fwt(g, A | a, O | o, X | x);
		for(int i = 0;i < 1 << w;++i) g[i] *= g[i];
		ifwt(g, A | a, O | o, X | x);
		cout << g[a | o | x] << '\n';
	}
}