//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
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
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int n, m;
ll g;
vector<ll> sm;
ll rd;
int pl[maxn];
ll cal(ll a) { //  
	ll ans = 0;
	if (a >= g) ans += a / g * (g - sm.size()), a %= g;
	ans += a;
	for (auto h : sm)
		if (h <= a) ans -= 1;
	return ans;
} 
int main() {
	ll k;
	cin >> n >> m >> k;
	int gc = __gcd(n, m);
	g = 1ll * n * m / gc;
	ll rn = 0, rm = 0;
	while (1ll * rn * n % m != gc % m) rn++;
	while (1ll * rm * m % n != gc % n) rm++;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		pl[x] = i;
	}
	for (int j = 1; j <= m; j++) {
		int x;
		scanf("%d", &x);
		if (pl[x]) {
			int e = pl[x];
			int f = j;
			if (abs(j - e) % gc) continue;
			ll cr = min(j, e);
			e -= cr, f -= cr;
			e /= gc, f /= gc;
			cr += 1ll * e * rm * m + 1ll * f * rn * n;
			cr %= g;
			if (cr == 0) cr += g;
			sm.pb(cr);
		}
	}
	ll l = 0, r = 1e18;
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (cal(mid) >= k) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}