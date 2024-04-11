#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
vi r[maxn];
int eg[200][200], dis[200][200];
int q[maxn];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll k;
		scanf("%lld", &k);
		for (int j = 0; j < 61; j++) 
			if (k & (1ll << j)) r[j].pb(i);
	}
	int idcnt = 0;
	memset(dis, -1, sizeof(eg));
	for (int j = 0; j < 61; j++) {
		if (r[j].size() >= 3) {
			cout << 3 << endl;
			return 0;
		} 
		else if (r[j].size() == 2) {
			if (!q[r[j][0]]) q[r[j][0]] = ++idcnt;
			if (!q[r[j][1]]) q[r[j][1]] = ++idcnt;
			int u = q[r[j][0]], v = q[r[j][1]];
			eg[u][v] = eg[v][u] = 1;
			dis[u][v] = dis[v][u] = 1;
		}
	}
	for (int i = 1; i <= idcnt; i++)
		for (int j = 1; j <= idcnt; j++)
			if (dis[i][j] != 1) dis[i][j] = maxn, eg[i][j] = maxn;
	int mn = maxn;
	for (int i = 1; i <= idcnt; i++) {
		for (int j = 1; j < i; j++)
			for (int k = 1; k < j; k++)
				mn = min(mn, eg[i][j] + dis[j][k] + eg[k][i]);
			//	cout << i << " " << j << " " << k << endl;
		for (int j = 1; j <= idcnt; j++)
			for (int k = 1; k <= idcnt; k++)
				dis[j][k] = min(dis[j][k], dis[i][k] + dis[j][i]);
	}
	if (mn == maxn) cout << -1 << endl;
	else cout << mn << endl;
	return 0;
}