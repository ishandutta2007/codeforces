#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 4e5 + 5;
int n, a[N], ans;

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	a[0] = a[n + 1] = 0, ans = 0;
	for(int i = 1; i <= n; i++) ans += max(a[i] - a[i - 1], 0ll) + max(a[i] - a[i + 1], 0ll);
	for(int i = 1; i <= n; i++)
		if(a[i] > a[i - 1] && a[i] > a[i + 1]) ans -= a[i] - max(a[i - 1], a[i + 1]);
	printf("%lld\n", ans);
}

signed main() {
	int T = get();
	while(T--) solve();
	return 0;
}