#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
int ph[maxn], bpr[maxn];
int c[maxn], cnt = 0;
int main() {
	for (int i = 0; i < maxn; i++)
		ph[i] = i, bpr[i] = 1;
	for (int i = 2; i < maxn; i++) {
		if (!bpr[i]) continue;
		ph[i] = i - 1;
		for (int j = 2; j * i < maxn; j++)
			ph[i * j] = ph[i * j] / i * (i - 1), 
			bpr[i * j] = 0;
	}
	int n, k;
	cin >> n >> k;
	ll fn = 1e9;
	fn *= fn;
	for (int tp = 0; tp < 2; tp++) {
		cnt = 0;
		for (int j = 3; j <= n; j++) {
			if (!tp && (j % 2 == 0)) continue;
			c[cnt++] = ph[j];
		}
		sort(c, c + cnt);
		if (cnt < k) continue;
		ll ans = 0;
		for (int j = 0; j < k; j++)
			ans += c[j];
		ans++;
		ans += tp;
		fn = min(fn, ans);
	}
	cout << fn << endl;
	return 0;
}