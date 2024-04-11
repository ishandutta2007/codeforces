#include<bits/stdc++.h>
#define int long long
using namespace std;
 
int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}
 
const int N = 1e5 + 5;
int f[N], a[N];
 
void init() {
	f[0] = f[1] = 1;
	for(int i = 2; i <= 100000; i++) f[i] = min((int)1e18 + 1, f[i - 1] * 2);
}
 
void solve() {
	int n = get(), k = get();
	if(k > f[n]) return printf("-1\n"), void();
	for(int i = 1, now = 1; i <= n; i = now) {
		while(f[n - now] < k) k -= f[n - now], ++now;
		a[i] = now, ++now;
	}
	for(int i = 1; i <= n; i++) if(!a[i]) a[i] = a[i - 1] - 1;
	for(int i = 1; i <= n; i++) printf("%lld ", a[i]), a[i] = 0; printf("\n");
}
 
signed main() {
	init();
	int T = get();
	while(T--) solve();
	return 0;
}
 
/*
1
3 4
*/