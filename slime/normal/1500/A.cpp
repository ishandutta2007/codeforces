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
int a[maxn];
int fl[6000005][2];
int main() {
	int n;
	cin >> n;
	vector<pi> cr;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cr.pb(mp(a[i], i));
	sort(cr.begin(), cr.end());
	for (int i = 1; i <= n; i++) a[i] = cr[i - 1].fi;
	if (n >= 6000) n = 6000;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (fl[a[i] + a[j]][0]) {
				if (fl[a[i] + a[j]][1] == j) continue;
				if (fl[a[i] + a[j]][0] == j) continue;
				cout << "YES" << endl;
				cout << cr[i - 1].se << ' ' << cr[j - 1].se << ' ' << cr[fl[a[i] + a[j]][0] - 1].se << ' ' << cr[fl[a[i] + a[j]][1] - 1].se << endl;
				return 0;
			}
		}
		for (int j = 1; j < i; j++) 
			fl[a[i] + a[j]][0] = i, 
			fl[a[i] + a[j]][1] = j;
	}
	cout << "NO" << endl;
	return 0;
}