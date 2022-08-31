#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define pi pair<int, ll>
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
int n;
ll k;
int a[maxn];
int b[maxn];
ll work(ll x) {
	//<= x 
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll ed = a[i] - x;
		if (ed <= 1) b[i] = 0;
		else {
			ll er = sqrt(ed / 3) - 20;
			er = max(er, 0ll);
	//		while (er * er * 3 > ed) er--;
			while (3 * er * er + 3 * er + 1 < ed) er++;
			b[i] = min((ll)a[i], er);
		}	
		ans += b[i];
	} 
	return ans;
}
ll cal(int a, int b) {
	return 1ll * b * (a - 1ll * b * b);
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	ll l = -4e18, r = 4e18;
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (mid == r) mid--;
		if (work(mid) <= k) r = mid;
		else l = mid + 1;
	}
	ll nd = k - work(l);
	for (int i = 1; i <= n; i++) {
		while (nd > 0 && b[i] < a[i] && cal(a[i], b[i] + 1) - cal(a[i], b[i]) >= l) {
			nd--;
			b[i]++;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", b[i]);
	return 0;
}