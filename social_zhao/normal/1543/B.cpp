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
	int sum = 0;
	for(int i = 1; i <= n; i++) a[i] = get(), sum += a[i];
	cout << (sum % n) * (n - sum % n) << endl;
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}