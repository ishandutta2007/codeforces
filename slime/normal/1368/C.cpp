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
	int n;
	cin >> n;
	vector<pi> res;
	for (int i = 0; i <= n + 1; i++) {
		res.pb(mp(i, i));
		if (i != n + 1)
			res.pb(mp(i, i + 1)), 
			res.pb(mp(i + 1, i));
	}
	cout << res.size() << endl;
	for (auto v : res)
		cout << v.fi << ' ' << v.se << endl;
	return 0;
}