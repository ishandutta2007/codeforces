//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 3050005 /*rem*/
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
	for (int i = 0; i < t; i++) {
		ll n;
		scanf("%lld", &n);
		for (int i = 0; i < 63; i += 2) {
			ll c1 = (1ll << i) - 1;
			if (c1 >= n) {
				ll ls = (1ll << (i - 2)) - 1;
				ll dv = n - ls;
			//	cout  << "!!!" << dv << endl;
				ll id = (dv - 1) / 3;
				ll mt = (1ll << (i - 2));
				ll u[3] = {id, 0, 0};
				ll cu = 0;
				for (int j = 0; j < i; j += 2) {
					ll nd = (id >> j) % 4;
					ll mm = 0;
					if (nd == 0) mm = 0;
					if (nd == 1) mm = 2;
					if (nd == 2) mm = 3;
					if (nd == 3) mm = 1;
					cu += mm * (1ll << j); 
				}
				u[1] = cu, u[2] = id ^ cu;
				ll ans = 0;
				if (dv % 3 == 1) ans = mt + u[0];
				else if (dv % 3 == 2) ans = mt * 2 + u[1];
				else ans = mt * 3 + u[2];
				printf("%lld\n", ans);
				break;
			}
		} 
	}
	return 0;
}