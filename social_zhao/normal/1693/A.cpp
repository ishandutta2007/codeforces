#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, a[N];

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	while(n > 0 && a[n] == 0) --n;
	if(n == 0) return printf("Yes\n"), void();
	int now = 0, flag = 1, i = 0;
	for(i = 1; i <= n && flag; i++) {
		now += a[i];
		if(now < 0) flag = 0;
		else if(now == 0) break;
	}
	if(now == 0 && i == n) printf("Yes\n");
	else printf("No\n");
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}