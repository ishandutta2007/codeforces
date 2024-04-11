#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 65;
int n, a[N];

int qpow(int x, int y) {
	return 1ll << y;
}

void solve() {
	n = get();
	int cnt0 = 0, cnt1 = 0;
	for(int i = 1; i <= n; i++) a[i] = get(), cnt0 += a[i] == 0, cnt1 += a[i] == 1;
	cout << cnt1 * qpow(2, cnt0) << endl;
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
2
1 0
*/