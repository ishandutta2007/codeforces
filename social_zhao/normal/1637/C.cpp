#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 100005;
int n, a[N];

void solve() {
	n = get();
	int ans = 0, even = 0, mx = 0, odd = 0;
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 2; i < n; i++) {
		ans += (a[i] + 1) / 2;
		even |= a[i] != 0 && a[i] % 2 == 0;
		if(a[i] % 2 == 1) mx = max(mx, a[i]), ++odd;
	}
	if(n == 3 && a[2] % 2 == 1) cout << -1 << endl;
	else if(!even && mx == 1) cout << -1 << endl;
	else cout << ans << endl;
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}