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
// head
int n, m, d;
int a[maxn];
ll fr[maxn];
int main() {
	cin >> n >> d >> m;
	ll ans = -1e18;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int pl = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] <= m) chkmax(pl, i);
	if (pl)
		reverse(a + 1, a + pl + 1);
	for (int i = 1; i <= n; i++) {
	//	cout << a[i] << ' ';
		fr[i] = fr[i - 1];
		if (a[i] <= m) fr[i] += a[i];
	}
	ans = fr[n];
	ll tot = 0;
	ll sum = 0;
	for (int i = n; i >= 1; i--) {
		if (a[i] <= m) break;
		sum += a[i];
		tot += 1;
		ll cur = d * (tot - 1) + tot;
		ll ud = n - cur;
		if (ud >= 0)
			chkmax(ans, fr[ud] + sum);
	}
	cout << ans << endl;
	return 0;
}