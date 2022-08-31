#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int cnt[maxn];
ll ans;
int l, r;
int a[maxn];
ll sqr(int a) {
	return 1ll * a * a;
}
void upd(int pl, int tp) {
	ans -= sqr(cnt[pl]);
	cnt[pl] += tp, 
	ans += sqr(cnt[pl]);
} 
void mv(int x, int y) {
	while (l > x) 
		l--, upd(a[l], 1);
	while (r < y) 
		r++, upd(a[r], 1);
	while (l < x)
		upd(a[l], -1), l++;
	while (r > y) 
		upd(a[r], -1), r--;
}
ll dp[22][maxn];
int n, k;
void solve(int k, int l, int r, int ex, int ey) {
	if (l > r) return ;
	int mid = (l + r) / 2;
	int npl = 0;
	for (int i = max(ex, mid); i <= ey; i++) {
		mv(mid, i);
		ll cur = ans + dp[k - 1][i + 1];
		if (cur <= dp[k][mid]) {
			dp[k][mid] = cur;
			npl = i;
		}
	}
	solve(k, l, mid - 1, ex, npl);
	solve(k, mid + 1, r, npl, ey);
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);	
	l = 1, r = 1; ans = 1, cnt[a[1]] = 1;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < maxn; j++)
			dp[i][j] = 1e18;
		dp[i][n + 1] = 0;
		if (i == 0) dp[i][n + 1] = 0;
		else 
			solve(i, 1, n, 1, n);
	//	for (int j = 1; j <= n + 1; j++)
	//		cout << i << ' ' << j << ' ' << dp[i][j] << endl;
	}
	cout << (dp[k][1] - n) / 2 << endl;
	return 0;
}