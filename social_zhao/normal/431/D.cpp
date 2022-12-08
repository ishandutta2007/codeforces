#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

int m, k;
int dig[70], top, f[70][70];

int dp(int dep, int k, int lim) {
	if(k < 0) return 0;
	if(dep == 0) return k == 0;
	if(!lim && ~f[dep][k]) return f[dep][k];
	int res = 0;
	for(int i = 0; i <= (lim? dig[dep] : 1); ++i)
		res += dp(dep - 1, k - i, lim & (i == dig[dep]));
	if(!lim) f[dep][k] = res;
	return res;
}

int solve(int n) {
	top = 0;
	while(n) dig[++top] = n & 1, n >>= 1;
	memset(f, -1, sizeof(f));
	int res = dp(top, k, 1);
	return res;
}

int chk(int n) {
	int cnt = solve(n * 2) - solve(n);
	return cnt >= m;
}

signed main() {
	m = get(), k = get();
	int l = 1, r = 1e18, ans = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(chk(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}