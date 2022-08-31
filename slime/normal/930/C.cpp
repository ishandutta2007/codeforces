#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
int lb(int x) {
	return x & -x;
}
int d[maxn];
void upd(int pl, int num) {
	while (pl < maxn)
		d[pl] = max(d[pl], num), 
		pl += lb(pl);
}
int q(int pl) {
	int ans = 0 ;
	while (pl) {
		ans = max(ans, d[pl]);
		pl -= lb(pl);
	}
	return ans;
}
int x[maxn];
int n, m;
int e[maxn], f[maxn];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		x[l]++, x[r + 1]--;
	}
	x[0] = 1;
	for (int i = 1; i <= m; i++)
		x[i] += x[i - 1];
	for (int i = 1; i <= m; i++)
		e[i] = q(x[i]) + 1, upd(x[i], e[i]);
	memset(d, 0, sizeof(d));
	for (int i = m; i >= 1; i--)
		f[i] = q(x[i]) + 1, upd(x[i], f[i]);
	int ans = 0;
	for (int i = 1; i <= m; i++)
		ans = max(ans, e[i] + f[i] - 1);
	for (int i = 1; i <= m; i++)
		e[i] = max(e[i], e[i - 1]);
	for (int i = m; i >= 1;i--)
		f[i] = max(f[i], f[i + 1]);
	for (int i = 1; i <= m; i++)
		ans = max(ans, e[i - 1] + f[i + 1]);
	cout << ans << endl;
	return 0;
}