//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 2005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
ll ksm(ll a, ll b) {
	if (b < 0) b += mod - 1;
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
ll jc[maxn], bjc[maxn];
ll cur[maxn][maxn];
ll e[maxn][maxn];
ll pw[maxn][maxn];
ll bs[maxn];
int a[maxn];
int main() {
	cur[0][0] = 1;
	jc[0] = bjc[0] = 1;
	for (int i = 1; i < maxn; i++)
		jc[i] = jc[i - 1] * i % mod, 
		bjc[i] = ksm(jc[i], mod - 2);
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++) {
			if (j == 0) pw[i][j] = 1;
			else pw[i][j] = pw[i][j - 1] * i % mod;
		}
	int n, k;
	cin >> n >> k;
	int sum = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i], sum += a[i];
	for (int i = 0; i < maxn; i++)
		bs[i] = ksm(pw[sum][i], mod - 2);
	for (int i = 1; i <= n; i++) {
		vector<array<int, 3> > s;
		for (int j = 0; j <= a[i] / k; j++) {
			if (a[i] == k && j == 1) continue;
			ll w = bjc[j];
			if (j & 1) w *= -1;
			ll cr = a[i] - j * k;
			cr = cr * ksm(sum, mod - 2) % mod;
			s.pb({j, a[i] - j * k, w * ksm(cr, j) % mod});
			if (j) s.pb({j - 1, a[i] - j * k, w * ksm(cr, j - 1) % mod * j % mod});
		}
		vector<array<int, 3> > cm;
		for (int j = 0; j <= sum; j++)
			for (int k = 0; k <= sum; k++)
				if (cur[j][k])
					cm.pb({j, k, cur[j][k]});
		memset(e, 0, sizeof(e));
		for (auto u : s)
			for (auto v : cm)
				e[u[0] + v[0]][u[1] + v[1]] += 1ll * u[2] * v[2] % mod;
		for (int j = 0; j <= sum; j++)
			for (int k = 0; k <= sum; k++)
				cur[j][k] = e[j][k] % mod;
	}
	ll ans = 0;
	for (int j = 0; j <= sum; j++)
		for (int k = 0; k <= sum; k++) {
			if (!cur[j][k]) continue;
			ll h = 1ll * k * ksm(sum, mod - 2) % mod;
			if (h == 1) continue;
			ll w = jc[j] * ksm(1 - h, -(j + 1)) % mod;
			ans += w * cur[j][k];
			ans %= mod;
		}
	ans *= -1;
	ans %= mod;
	if (ans < 0) ans += mod;
	cout << ans << endl;
	return 0;
}