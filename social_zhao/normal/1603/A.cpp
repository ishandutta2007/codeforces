#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, a[N];

int gcd(int x, int y) { return y? gcd(y, x % y) : x; }

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	int lcm = 1;
	for(int i = 1; i <= n; i++) {
		lcm = lcm / gcd(lcm, i + 1) * (i + 1);
		if(a[i] % lcm == 0) return printf("NO\n"), void();
		if(lcm > 1000000000) break;
	}
	printf("YES\n");
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}