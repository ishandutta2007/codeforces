//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 10005 /*rem*/
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
int d[maxn];
int dp[maxn][1005];
const int inf = 2e9 + 9;
int gt(int a, int b) {
	return a * 1005 + b;
} 
int cnt[2];
const int mxs = maxn * 1005;
int f[mxs], nx[mxs];
vi fs[1005];
int g, r;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &d[i]);
	sort(d + 1, d + m + 1);
	scanf("%d%d", &g, &r);
	for (int i = 1; i <= m; i++)
		for (int j = 0; j <= g; j++)
			dp[i][j] = inf;
	dp[1][g] = 0;
	f[cnt[0]++] = gt(1, g);
	int ans = inf;
	while (1) {
		if (!cnt[0]) break;
		cnt[1] = 0;
		for (int i = 0; i <= g; i++) {
			fs[i].clear();
			vector<int>().swap(fs[i]);
		}
		if (cnt[0]) {
			fs[g].resize(cnt[0]);
			for (int j = 0; j < cnt[0]; j++)
				fs[g][j] = f[j];
		}
		for (int q = g; q >= 0; q--) {
			for (int i = 0; i < fs[q].size(); i++) {
				int cu = fs[q][i];
				int u = cu / 1005, v = cu % 1005;
			//	cout << u << ' ' << v << ' ' << dp[u][v] << endl;
				if (u == m) ans = min(ans, dp[u][v]);
				if (u < m) {
					int nu = u + 1, nv = v - (d[u + 1] - d[u]), nw = dp[u][v] + (d[u + 1] - d[u]);
					if (nv >= 0 && dp[nu][nv] > nw) {
						dp[nu][nv] = nw;
						fs[nv].pb(gt(nu, nv));
					}
				}
				if (u >= 2) {
					int nu = u - 1, nv = v + (d[u - 1] - d[u]), nw = dp[u][v] + (d[u] - d[u - 1]);
					if (nv >= 0 && dp[nu][nv] > nw) {
						dp[nu][nv] = nw;
						fs[nv].pb(gt(nu, nv));
					}
				}
				if (v == 0) {
					int nu = u, nv = g, nw = dp[u][v] + r;
					if (nv >= 0 && dp[nu][nv] > nw) {
						dp[nu][nv] = nw;
						nx[cnt[1]++] = gt(nu, nv);
					}
				}
			}
		}
		cnt[0] = cnt[1];
		for (int j = 0; j < cnt[0]; j++)
			f[j] = nx[j];
		cnt[1] = 0;
	}
	if (ans == inf) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}