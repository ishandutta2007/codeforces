#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using std::cin; using std::cout;
const int maxn = 400;
const int N = maxn;
typedef long long ll;
typedef std::bitset<N> set;
int n, m, r, c;
set shift[26][maxn][maxn];
set ans[maxn];
char buf[maxn][maxn | 1];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;++i) {
		cin >> buf[i];
		for(int j = 0;j < m;++j) {
			buf[i][j] -= 'a';
			for(int l = 0;l < m;++l) {
				const int su = j - l, now = su + (su >> 31 & m);
				shift[buf[i][j]][i][l].set(now);
			}
			ans[i].set(j);
		}
	}
	cin >> r >> c;
	for(int i = 0;i < r;++i) {
		for(int j = 0;j < c;++j) {
			char c;
			cin >> c;
			int I = i % n, J = j % m;
			if(c != '?') {
				c -= 'a';
				for(int k = 0;k < n;++k) {
					const int su = I + k - n;
					ans[k] &= shift[c][su + (su >> 31 & n)][J];
				}
			}
		}
	}
	for(int i = 0;i < n;++i) {
		for(int j = 0;j < m;++j) {
			cout.put(ans[i].test(j) + 48);
		}
		cout.put(10);
	}
}