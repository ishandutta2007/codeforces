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
int x[maxn], y[maxn];
int fl[maxn];
ll sqr(int a) {
	return 1ll * a * a;
}
ll dis(int a, int b) {
	return sqr(x[a] - x[b]) + sqr(y[a] - y[b]);
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	int pl = 1;
	vi cur;
	for (int i = 1; i <= n; i++) {
		fl[pl] = 1;
		cur.pb(pl);
		ll mx = 0, id = 0;
		for (int j = 1; j <= n; j++) {
			if (fl[j]) continue;
			if (chkmax(mx, dis(pl, j))) id = j;
		}
		pl = id;
	}
	for (auto v : cur) cout << v << ' ';
	return 0;
}