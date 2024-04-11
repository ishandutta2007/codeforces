#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int n, m, a[N], b[N];
vector<int> bin[N];

int gcd(int x, int y) { return y? gcd(y, x % y) : x; }

void solve() {
	n = get(), m = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	int d = 0;
	for(int i = 1; i <= m; i++) d = gcd(d, get());
	for(int i = 0; i < d; i++) bin[i].clear();
	for(int i = 1; i <= n; i++) bin[i % d].push_back(a[i]);
	int sum0 = 0, sum1 = 0, sum = 0;
	for(int i = 0; i < d; i++) {
		sort(bin[i].begin(), bin[i].end());
		int nw = 0, mx0 = 0x3f3f3f3f * bin[i].size(), mx1 = 0;
		for(int j = 0; j < bin[i].size(); j++) {
			nw += bin[i][j];
			if(j & 1) mx1 = min(mx1, nw);
			else mx0 = min(mx0, nw);
		}
		sum0 += mx0, sum1 += mx1, sum += nw;
	}
	printf("%lld\n", max(sum - 2 * sum0, sum - 2 * sum1));
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
7 1
1 -1 1 -1 1 -1 1
2
*/