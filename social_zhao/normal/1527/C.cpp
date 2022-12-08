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
int n, a[N], b[N], len, cnt[N];

int solve(int l, int r) {
	if(l >= r) return 0;
	int mid = (l + r) >> 1, res = solve(l, mid) + solve(mid + 1, r);
	for(int i = mid + 1; i <= r; i++) cnt[a[i]] += (n - i + 1);
	for(int i = l; i <= mid; i++) res = res + i * cnt[a[i]];
	for(int i = mid + 1; i <= r; i++) cnt[a[i]] -= (n - i + 1);
	return res;
}

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = b[i] = get();
	sort(b + 1, b + 1 + n), len = unique(b + 1, b + 1 + n) - b - 1;
	for(int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + 1 + len, a[i]) - b;
	printf("%lld\n", solve(1, n));
}

signed main() {
	int T = get();
	while(T--) solve(); 
	return 0;
}