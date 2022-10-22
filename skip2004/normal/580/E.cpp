#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;

const int N = 100100;
const int mod = 998244353;
const int base = 114514;

int n, m, k;

char a[N];
inline int judge(u64 * a, u64 * b, int len) {
	for(int i = 0;i != len;++i) {
		if(a[i] != b[i]) return 0;
	}
	return 1;
}
inline int judge(char * a, char * b, int len) {
	for(int i = 0;i != len % 8;++i) {
		if(a[i] != b[i]) return 0;
	}
	return judge((u64*) (a + len % 8), (u64*) (b + len % 8), len >> 3);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> k;
	cin >> a + 1;
	for(int i = 1, opt, l, r, c;i <= m + k;++i) {
		cin >> opt >> l >> r >> c;
		if(opt == 1) {
			c += '0';
			for(int i = l;i <= r;++i) {
				a[i] = c;
			}
		} else {
			cout << (judge(a + l, a + l + c, (r - l + 1) - c) ? "YES" : "NO") << '\n';
		}
	}
}