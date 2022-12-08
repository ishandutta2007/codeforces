#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5, P = 998244353;
int n, k, v[N];

void solve() {
	n = get(), k = get();
	for(int i = 1; i <= n; i++) v[i] = get();
	int ans = 1;
	for(int i = n - k + 1; i <= n; i++) if(v[i] > 0) ans = 0;
	for(int i = 1; i <= k; i++) ans = ans * i % P;
	for(int i = 1; i <= n - k; i++) {
		if(v[i] == -1) ans = ans * (k + i) % P;
		else if(v[i] > 0) ans = ans * (v[i] < k + i);
		else ans = ans * (k + 1) % P;
	}
	cout << ans << endl;
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}