#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int P = 1e9 + 7;

void solve() {
	int n = get(), k = get();
	int res = 0;
	for(int i = 31; i >= 0; i--) 
		res = (res * n + (k >> i & 1ll)) % P;
	cout << res << endl;;
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}