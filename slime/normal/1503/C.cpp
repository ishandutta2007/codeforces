//Awwawa! Dis cold yis ratten buy tEMMIE!
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
int a[maxn], c[maxn];
vector<pi> cr;
int main() {
	cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &c[i]), 
		ans += c[i], 
		cr.pb(mp(a[i], c[i]));
	sort(cr.begin(), cr.end());
	int mx = cr[0].fi;
	for (auto v : cr) {
		if (v.fi >= mx) ans += v.fi - mx;
		chkmax(mx, v.fi + v.se);
	} 
	printf("%lld\n", ans);
	return 0;
}