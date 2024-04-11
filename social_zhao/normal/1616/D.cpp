#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5e4 + 5;
int n, a[N], x, pre[N], b[N], len, f[N], g[N];

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	x = get();
	for(int i = 1; i <= n; i++) a[i] -= x;
	f[1] = 1, g[1] = a[1];
	for(int i = 2; i <= n; i++) {
		if(g[i - 1] + a[i] >= 0) f[i] = f[i - 1] + 1, g[i] = min(g[i - 1], 0ll) + a[i];
		else f[i] = f[i - 1], g[i] = 1e18;
	}
	cout << f[n] << endl;
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
10
2 4 2 4 2 4 2 4 2 4
3
*/