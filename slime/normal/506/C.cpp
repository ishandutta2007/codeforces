#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
int n, m, k, p;
int h[maxn], a[maxn];
int d[maxn];
bool check(ll x) {
	ll mn = 0;
	for (int i = 1; i <= n; i++) {
		ll dv = h[i] + 1ll * a[i] * m;
		dv -= x;
		if (dv > 0) {
			mn += dv / p;
			if (dv % p) mn++;
		}
	}
	if (mn > m * k) return 0;
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= n; i++) {
		for (ll s = x + 1; s <= 1ll * a[i] * m; s += p) {
			int pl = s / a[i];
			if (s % a[i]) pl++;
			d[pl]++; // 
		}
	}
	for (int i = 1; i <= m; i++) {
		d[i] += d[i - 1];
		if (d[i] > (i - 1) * k) return 0;
	}
	return 1;
}
int main() {
	scanf("%d%d%d%d", &n, &m, &k, &p);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &h[i], &a[i]);
	ll L = 0, R = 1e18;
	while (L < R) {
		ll mid = (L + R) >> 1;
		if (check(mid)) R = mid;
		else L = mid + 1;
	}
	cout << L << endl;
	return 0;
}
/*
5
1 2 3
2 3 4
4 5 3
3 4 2
1
2
*/