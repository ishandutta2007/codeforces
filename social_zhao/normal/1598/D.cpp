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
int n, a[N], b[N];
map<int, int> cnta, cntb;

int C3(int n) { return n * (n - 1) * (n - 2) / 6; }

void solve() {
	n = get();
	cnta.clear(), cntb.clear();
	for(int i = 1; i <= n; i++) a[i] = get(), b[i] = get(), cnta[a[i]]++, cntb[b[i]]++;
	int ans = C3(n);
	int sum1 = 0, sum2 = 0, sum3 = 0;
	for(int i = 1; i <= n; i++) {
		sum1 += C3(cnta[a[i]]), sum2 += C3(cntb[b[i]]), sum3 += (cnta[a[i]] - 1) * (cntb[b[i]] - 1);
	}
	cout << ans - sum3 << endl;
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}