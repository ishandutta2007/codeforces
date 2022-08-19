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
int main() {
	int t;
	cin >> t;
	int d, m;
	for (int i = 0; i < t; i++) {
		cin >> d >> m;
		ll ans = 1;
		for (int j = 0; j < 30; j++) {
			int l = (1 << j), r = (1 << (j + 1)) - 1;
			r = min(r, d);
			ans = ans * max(1, (r - l + 2)) % m;
		} 
		ans = (ans + m - 1) % m;
		cout << ans << endl;
	} 
	
	return 0;
}