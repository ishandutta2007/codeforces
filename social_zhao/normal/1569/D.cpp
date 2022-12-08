#include<bits/stdc++.h>
#define int long long 
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e5 + 5;
int n, m, k, _x[N], _y[N], x[N], y[N];
int cntr[N], cntc[N], ans;
map<pair<int, int>, int> R, C;

void solve() {
	n = get(), m = get(), k = get(), ans = 0;
	for(int i = 1; i <= n; i++) _x[i] = get();
	for(int i = 1; i <= m; i++) _y[i] = get();
	for(int i = 1; i <= k; i++) {
		x[i] = get(), y[i] = get();
		int l = upper_bound(_x + 1, _x + 1 + n, x[i]) - _x - 1;
		int r = lower_bound(_x + 1, _x + 1 + n, x[i]) - _x;
		int d = upper_bound(_y + 1, _y + 1 + m, y[i]) - _y - 1;
		int u = lower_bound(_y + 1, _y + 1 + m, y[i]) - _y;
		if(l == r && d == u) continue;
		if(l != r) {
			ans += cntr[l] - R[{l, d}];
			cntr[l]++, R[{l, d}]++;
		}
		if(d != u) {
			ans += cntc[d] - C[{l, d}];
			cntc[d]++, C[{l, d}]++;
		}
	}
	printf("%lld\n", ans);
	for(int i = 1; i <= k; i++) {
//		x[i] = get(), y[i] = get();
		int l = upper_bound(_x + 1, _x + 1 + n, x[i]) - _x - 1;
		int r = lower_bound(_x + 1, _x + 1 + n, x[i]) - _x;
		int d = upper_bound(_y + 1, _y + 1 + m, y[i]) - _y - 1;
		int u = lower_bound(_y + 1, _y + 1 + m, y[i]) - _y;
		if(l == r && d == u) continue;
		if(l != r) cntr[l] = 0, R[{l, d}] = 0;
		if(d != u) cntc[d] = 0, C[{l, d}] = 0;
	}
}

signed main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
5 4 9
0 1 2 6 1000000
0 4 8 1000000
4 4
2 5
2 2
6 3
1000000 1
3 8
5 8
8 8
6 8

*/