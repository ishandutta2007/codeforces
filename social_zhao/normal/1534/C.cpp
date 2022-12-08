#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 4e5 + 5, P = 1e9 + 7;
int a[N], b[N], n, tot, fa[N];

int find(int x) { return x == fa[x]? x : fa[x] = find(fa[x]); }

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res; 
}

void solve() {
	n = get(), tot = n;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 1; i <= n; i++) b[i] = get();
	for(int i = 1; i <= n; i++) {
		int x = find(a[i]), y = find(b[i]);
		if(x != y) tot--, fa[x] = y;
	}
	printf("%lld\n", qpow(2, tot));
} 

signed main() {
	int T = get();
	while(T--) solve();
	return 0;
}