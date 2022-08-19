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
int n;
int p[maxn];
int tt[maxn];
bool bpr[1505];
int prs[maxn], prcnt = 0;
int m[maxn][2];
vector<pi> c[maxn]; 
int main() {
	for (int i = 0; i < 1505; i++) bpr[i] = 1;
	for (int j = 2; j < 1505; j++)
		if (bpr[j]) {
			prs[prcnt++]  = j;
			for (int k = 2; k * j < 1505; k++)
				bpr[k * j] = 0;
		}
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	sort(p + 1, p + n + 1);
	for (int i = n; i >= 1; i--) {
		if (!tt[p[i]]) c[i].pb(mp(p[i], 1)), tt[p[i]] = 1;
		else {
			int u = p[i] - 1;
			for (int j = 0; j < prcnt; j++) {
				int cur = 0;
				while (u % prs[j] == 0) u /= prs[j], cur++;
				c[i].pb(mp(prs[j], cur));
				tt[prs[j]] = max(tt[prs[j]], cur); 
			}
			if (u > 1)
				c[i].pb(mp(u, 1)), 
				tt[u] = max(tt[u], 1);
		}
	}
	for (int i = 1; i <= n; i++) 
		for (auto v : c[i]) {
			int a = v.fi, b = v.se;
			if (b > m[a][0]) m[a][1] = m[a][0], m[a][0] = b;
			else if (b > m[a][1]) m[a][1] = b;
		}
	int fl = 0;
	for (int i = 1; i <= n; i++) {
		int cs = 1;
		for (auto v : c[i]) {
			int a = v.fi, b = v.se;
			if (m[a][0] == b && m[a][0] != m[a][1]) cs = 0;
		} 
		if (cs) fl = 1;
	}
	ll ans = 1;
	for (int i = 0; i < maxn; i++)
		if (tt[i]) ans = ans * ksm(i, tt[i]) % mod;
	if (fl) ans = (ans + 1) % mod; 
	cout << ans << endl;
	return 0;
}