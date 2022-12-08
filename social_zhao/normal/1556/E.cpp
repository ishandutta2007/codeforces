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
int n, q, a[N], b[N], sum[N];
int mx[N][30], mn[N][30];

int qmin(int l, int r) {
	int len = (int)log2(r - l + 1);
	return min(mn[l][len], mn[r - (1 << len) + 1][len]);
}

int qmax(int l, int r) {
	int len = (int)log2(r - l + 1);
	return max(mx[l][len], mx[r - (1 << len) + 1][len]);
}

signed main() {
	n = get(), q = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 1; i <= n; i++) b[i] = get();
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + b[i] - a[i];
	for(int i = 1; i <= n; i++) mx[i][0] = mn[i][0] = sum[i];
	for(int j = 1; j <= 20; j++)
		for(int i = 1; i + (1 << j) - 1 <= n; i++)
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]), mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
//	for(int i = 1; i <= n; i++) printf("%lld ", sum[i]); printf("\n");
	for(int i = 1; i <= q; i++) {
		int l = get(), r = get();
		if(sum[r] - sum[l - 1] != 0) { printf("-1\n"); continue; }
		int mn = qmin(l, r) - sum[l - 1], mx = qmax(l, r) - sum[l - 1];
//		printf("%lld %lld\n", mn, mx);
		if(mn < 0) { printf("-1\n"); continue; }
		printf("%lld\n", mx);
	}
	return 0;
}