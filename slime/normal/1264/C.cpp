#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353 
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
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
int p[maxn];
ll s[maxn];
ll te[maxn], bt[maxn]; 
int n, q;
ll ans;
set<int> ss;
int tp[maxn];
ll cal(int l, int r) {
	return (te[l] - te[r]) * bt[r] % mod;
} 
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		s[i] = 100ll * ksm(p[i], mod - 2) % mod;
	}
	te[n + 1] = bt[n + 1] = 1;
	for (int i = n; i >= 1; i--)
		te[i] = te[i + 1] * s[i] % mod, 
		bt[i] = ksm(te[i], mod - 2);
	for (int i = n; i >= 1; i--)
		te[i] += te[i + 1], te[i] %= mod;
	ss.insert(1), ss.insert(n + 1);
	ans = cal(1, n + 1);
	#define iter set<int>::iterator
	for (int i = 1; i <= q; i++) {
		int u;
		scanf("%d", &u);
		tp[u] ^= 1;
		if (tp[u]) {
			iter ur = ss.lower_bound(u), bd = ur;
			bd--;
			ans -= cal(*bd, *ur);
			ans += cal(*bd, u), ans += cal(u, *ur);
			ss.insert(u);
		}
		else {
			ss.erase(u);
			iter ur = ss.lower_bound(u), bd = ur;
			bd--;
			ans += cal(*bd, *ur);
			ans -= cal(*bd, u), ans -= cal(u, *ur);
		}
		ans %= mod;
		if (ans < 0) ans += mod;
		printf("%lld\n", ans);
	}
	return 0;
}
/*
1 2
..
*/