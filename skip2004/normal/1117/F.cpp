#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 100100;
using AI = int[17];
int can[1 << 17];
AI con[1 << 17];
int n, p, ans;
inline void fwt(AI * a, int lim) {
	lim >>= 1;
	if(!lim) return ;
	for(int i = 0;i < lim;++i) {
		for(int j = 0;j < p;++j) {
			a[i + lim][j] |= a[i][j];
		}
	}
	fwt(a, lim), fwt(a + lim, lim);
}
int edge[17];
int a[maxn];

int cnt[17];
int set[17];
inline void run(int * a) {
	for(int i = 0;i < p;++i) set[i] = 0;
	for(int i = 1;i <= n;++i) {

		for(int x = 0;x < p;++x) {
			if(set[x] >> x & 1) {
				con[set[x] ^ 1 << x][x] |= 1 << a[i];
				con[set[x] ^ 1 << x][a[i]] |= 1 << x;
			}
		}
		for(int x = 0;x < p;++x) set[x] |= 1 << a[i];
		set[a[i]] = 1 << a[i];
	}
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> p;
	for(int i = 1;i <= n;++i) {
		char ch;
		cin >> ch;
		a[i] = ch - 'a';
		++ cnt[a[i]];
	}
	for(int i = 0, x;i < p;++i) {
		for(int j = 0;j < p;++j) {
			cin >> x;
			edge[i] |= x << j;
		}
	}
	run(a);
	fwt(con, 1 << p);
	std::reverse(con, con + (1 << p));
	can[(1 << p) - 1] = 1;
	ans = n;
	for(int i = (1 << p) - 1;i >= 0;--i) {
		int su = 0;
		for(int x = 0;x < p;++x) if(i >> x & 1) {
			can[i] &= (~edge[x] & con[i][x] & i) == 0;
			su += cnt[x];
		}
		if(can[i]) {
			for(int j = 0;j < p;++j) if(i >> j & 1) {
				can[i ^ 1 << j] = 1;
			}
			if(su < ans) ans = su;
		}
	}
	cout << ans << '\n';
}