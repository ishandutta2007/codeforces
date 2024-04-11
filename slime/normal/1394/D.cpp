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
// head
int t[maxn];
int h[maxn];
vi eg[maxn];
#define pl pair<ll, ll>
const ll inf = 1e18;
ll cal(int plz, vector<pl> cur, int nw) {
	// plz :
	int sz[2] = {0, 0};
	vector<ll> c[2];
	if (plz >= 0)
		sz[plz]++, 
		c[plz].pb(inf);
	ll tot = 0;
	for (auto v : cur) {
		if (v.fi >= v.se)
			sz[1]++, 
			c[1].pb(v.fi - v.se);
		else 
			sz[0]++, 
			c[0].pb(v.se - v.fi);
		tot += min(v.fi, v.se);
	}
	ll ans = tot + 1ll * max(sz[0], sz[1]) * nw;
	int tp = 0;
	if (sz[1] > sz[0]) tp = 1;
	sort(c[tp].begin(), c[tp].end());
	for (int j = 0; j < c[tp].size(); j++) {
		tot += c[tp][j];
		if (tot >= inf) break;
		chkmin(ans, tot + 1ll * max(sz[tp] - j - 1, sz[tp ^ 1] + j + 1) * nw);
	}
	return ans;
}
pl dfs(int a, int fa) {
	ll res[2] = {0, 0};
	vector<pl> cur;
	for (auto v : eg[a]) {
		if (v == fa) continue;
		cur.pb(dfs(v, a));
	}
	if (a == 1) {
		cout << cal(-1, cur, t[a]) << endl;
		exit(0);
	}
	for (int i = 0; i < 2; i++) {
		res[i] = inf;
		if (i == 0 && h[a] < h[fa]) continue;
		if (i == 1 && h[a] > h[fa]) continue;
		res[i] = cal(i ^ 1, cur, t[a]);
	}
	return mp(res[0], res[1]);
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &t[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &h[i]);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		eg[u].pb(v);
		eg[v].pb(u);
	}
	dfs(1, 0);
	return 0;
}