#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
int mn[maxn];
int c(int u, int v) {
	// 1u v 
	if (v > 2 * u) return 0;
	if (v < 2) return 0;
	int bg = max(1, v - u), ed = min(u, v - 1);
	return ed - bg + 1; 
}
int rm[maxn];
int mu[maxn];
int bpr[maxn];
void gt(int q) {
	for (int i = 1; i <= 2 * q; i++) rm[i] = 0;
	for (int i = 1; i <= q; i++)
		if (mu[i]) {
			int dv = q / i;
			for (int s = 1; s <= 2 * dv; s++)
				rm[s * i] += mu[i] * c(dv, s);
		}
} 
int main() {
	for (int i = 0; i < maxn; i++) bpr[i] = 1, mu[i] = 1;
	for (int i = 2; i < maxn; i++) {
		if (!bpr[i]) continue;
		for (int j = 1; j * i < maxn; j++)
			bpr[i * j] = 0, 
			mu[i * j] *= -1;
		for (int j = 1; 1ll * j * i * i < maxn; j++)
			mu[j * i * i] = 0;
	}
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	for (int i = 2; i <= 2 * n - 2; i++) 
		mn[i] = c(n - 1, i);
	for (int i = 1; i < n; i++) {
		int q = (n - 1) / i;
		int cnt = 0;
		gt(q);
		for (int s = 1; s <= n / i + 1 && s <= 2 * q; s++) {
			int nr = rm[s];
			mn[i * s] -= nr;
			cnt = (cnt + nr) % mod;
		}
		ans += 1ll * cnt * ksm(k, i) % mod, 
		ans %= mod;
	}
	for (int i = n + 1; i <= 2 * n; i++) {
		ans += 1ll * mn[i] * ksm(k, i - n);
		ans %= mod;
	}
	ll bk = ksm(ksm(k, n), mod - 2);
	ans = ans * bk % mod;
	cout << ans << endl;
	return 0;
}