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
ll chk(ll p, ll q, ll s) {
	ll ans = 0;
	while (p % s == 0) {
		p /= s;
		if (p % q) 
			return p;
	}
	return 0;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		ll p, q;
		cin >> p >> q;
		ll ans = p;
		if (p % q) ans = p;
		else {
			ans = 0;
			for (int i = 2; 1ll * i * i <= q; i++) {
				if (q % i == 0)
					chkmax(ans, chk(p, q, i)), 
					chkmax(ans, chk(p, q, q / i));
			}
			chkmax(ans, (chk(p, q, q)));
		}
		cout << ans << endl;
	}
	return 0;
}