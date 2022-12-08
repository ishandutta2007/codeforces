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
int n, a[N], tot;

int gcd(int x, int y) { return y? gcd(y, x % y) : x; }

signed main() {
	n = get();
	int prod = 1;
	for(int i = 1; i <= n; i++) if(gcd(i, n) == 1) prod = prod * i % n, a[++tot] = i;
	if(prod == 1) {
		printf("%lld\n", tot);
		for(int i = 1; i <= tot; i++) printf("%lld ", a[i]);
	}
	else {
		printf("%lld\n", tot - 1);
		for(int i = 1; i <= tot; i++) if(a[i] != prod) printf("%lld ", a[i]);
	}
	return 0;
}