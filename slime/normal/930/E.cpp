#include <bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 1000000007
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
struct bit {
	int lb(int x) {
		return x & -x;
	}
	int d[maxn];
	void upd(int pl, int num) {
		while (pl < maxn)
			d[pl] = (d[pl] + num) % mod,
			pl += lb(pl);
	}
	int q(int pl) {
		int ans = 0 ;
		while (pl) {
			ans = (ans + d[pl]) % mod,
			pl -= lb(pl);
		}
		return ans;
	}
	int q(int l, int r) {
		return (q(r) - q(l - 1)) % mod;
	}
}bb[3];
struct th {
	int l, r, tp;
	th(){}
	th(int a, int b, int c) {
		l = a, r = b, tp = c;
	}
	bool operator < (const th &s)const {
		return l < s.l;
	}
}p[maxn];
ll dp[maxn];
int k, n, m;
const int bk2 = (mod + 1) / 2;
int main() {
	cin >> k >> n >> m;
	for (int i = 1; i <= n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		p[i] = th(l, r, 0);
	}
	for (int i = n + 1; i <= n + m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		p[i] = th(l, r, 1);
	}
	sort(p + 1, p + n + m + 1);
	ll ans = 0;
	int mn[2] = {k + 1, k + 1};
	for (int i = n + m; i >= 1; i--) {
	//	cout << i << endl;
		dp[i] = -ksm(2, k - p[i].r);
		int l = i, r = n + m;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (p[mid + 1].l <= p[i].r) l = mid + 1;
			else r = mid;
		}
	//	cout << i << endl;
		// zuihouyige <= 
		dp[i] += -bb[p[i].tp].q(1, l);
		dp[i] += ksm(bk2, p[i].r) * -bb[2].q(l + 1, n + m);
		dp[i] %= mod;	
		if (p[i].r >= mn[p[i].tp]) dp[i] = 0;
		mn[p[i].tp] = min(mn[p[i].tp], p[i].r);
	//	cout << i << ' ' << p[i].tp << endl;
		bb[p[i].tp].upd(i, dp[i]);	
		
		bb[2].upd(i, dp[i] * ksm(2, p[i].l - 1) % mod);
		ans += dp[i] * ksm(2, p[i].l - 1), ans %= mod;
	//	cout << i << ' ' << p[i].l << ' ' << p[i].r << ' ' << p[i].tp << ' ' << dp[i] << endl;
	}
	ans += ksm(2, k), ans %= mod;
	if (ans < 0) ans += mod;
	cout << ans << endl;
	return 0;
}