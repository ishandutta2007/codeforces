//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 300005 /*rem*/
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
int a[maxn]; 
int main() {
	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n * 2; i++)
		scanf("%d", &a[i]);
	sort(a +1, a + 2 * n + 1);
	for (int i = 1; i <= 2 * n; i++)
		if ( i> n) ans += a[i];
		else ans -= a[i];
	ans %= mod;
	for (int i = 1; i <= n; i++) {
		ll bk = ksm(i, mod - 2);
		ans = ans * bk % mod * bk % mod;
	}
	for (int i = 1; i <= 2 * n; i++)
		ans = ans * i % mod;
	cout << ans << endl;
	return 0;
}