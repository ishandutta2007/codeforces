//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
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
/*11469018098471
7877074948913
68804730901483
*/
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
ll cur[maxn];
ll gcd(ll a, ll b) {
	if (!b) return a;
	return  gcd(b, a % b);
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		ll k;
		scanf("%d%lld", &n, &k);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &cur[i]);
		ll cr = 0;
		for (int i = 2; i <= n; i++)
			cr = gcd(cr, cur[i] - cur[1]);
		if ((k - cur[1]) % cr) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}