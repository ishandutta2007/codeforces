#include <bits/stdc++.h>
#define ll long long
#define maxn 2000005 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int n, l, t;
db ans;
ll a[maxn];
int cal(ll num, int u) {
	if (num < 0) return 0;
	int res = (n - 1) * (num / l);
	num %= l;
	int pl = lower_bound(a + 1, a + n + 1, num) - a;
	if (a[pl] > num) pl--;
	if (u <= pl) pl--; 
//	cout << "CAL" << num << ' ' << u << ' ' << res + pl << ' ' << pl << endl;
	return res + pl;
}
int main() {
	cin >> n >> l >> t;
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	a[n + 1] = 1e9 + 7;
	ll dv = 2 * t / l + 1;
	for (int i = 1; i <= n; i++) {
		ans += cal(a[i] + 2 * t, i), 
		ans -= cal(a[i], i);
		ans += cal(a[i] - 1 + dv * l, i), 
		ans -= cal(a[i] - 2 * t - 1 + dv * l, i);
	}
	ans /= 8;
	printf("%.10lf\n", ans);
	return 0;
}