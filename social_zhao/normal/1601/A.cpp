#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5e5 + 5;
int n, a[N];

int gcd(int x, int y) { return y? gcd(y, x % y) : x; }

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	int res = 0;
	for(int i = 0; i < 30; i++) {
		int cnt = 0;
		for(int j = 1; j <= n; j++) cnt += (a[j] >> i & 1);
		res = gcd(res, cnt);
	}
	for(int i = 1; i <= n; i++) if(res % i == 0) cout << i << " ";
	cout << endl; 
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}