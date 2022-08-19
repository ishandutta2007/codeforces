#include <bits/stdc++.h>
#define ll long long
#define maxn 55 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int dis[maxn], tr[maxn];
int dp[maxn][maxn];
int cr[maxn][maxn];
int cnt; // 1    
const int inf = 1e9;
int cal(int num, int bg) {
	for (int i = cnt; i >= 0; i--) {
		for (int j = 0; j <= num; j++) {
			if (i == cnt) {
				if (j == 0) dp[i][j] = inf;
				else dp[i][j] = 0; 
			}
			else {
				dp[i][j] = 0;
				for (int c = 0; c <= j; c++) {
					if (dis[i] == inf && c) continue;
					int nres = dis[i] + cr[i][bg - c]; // remem : cr   DP 
					if (c == 0) nres = inf;
					nres = min(nres, dp[i + 1][j - c]);
					dp[i][j] = max(dp[i][j], nres);
				}
			}
		}
	}
//	cout << "CAL" << num << ' ' << dp[0][num] << endl;
	return dp[0][num];
}
int dep[maxn];
vector<pi> eg[maxn];
int fl[maxn];
int ans = 0;
void dfs(int a, int fa) {
	ans += fl[a];
	for (auto v : eg[a])  {
		if (v.fi == fa) continue;
		dep[v.fi] = dep[a] + v.se, dfs(v.fi, a);
	}
}
int n;
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		eg[u].pb(mp(v, w));
		eg[v].pb(mp(u, w)); 
	}
	for (int i = 1; i <= n; i++) {
		if (eg[i].size() == 1)
			tr[cnt++] = i;
	}
/*	for (int i = 0; i < cnt; i++)
		cout << tr[i] << ' ';
	cout << endl;
*/	int s, m;
	cin >> s >> m;
	for (int i = 0; i < m; i++) {
		int pl;
		cin >> pl;
		fl[pl]++;
	}
	for (int i = 0; i <= m; i++)
		for (int j = 0; j < cnt; j++) {
			if (i == 0) cr[j][i] = 0;
			else {
				dep[tr[j]] = 0;
				dfs(tr[j], 0);
				for (int k = 0; k < cnt; k++)
					dis[k] = dep[tr[k]];
				cr[j][i] = cal(i, i);
	//			cout << "CUR" << j << ' ' << i << ' ' << cr[j][i] << endl;
			}
		}
	int res = inf;
	for (auto v : eg[s]) {
		for (int j = 1; j <= n; j++)
			dep[j] = inf;
		ans = 0;
		dep[v.fi] = v.se;
	//	dep[s] = 0;
		dfs(v.fi, s);
		for (int k = 0; k < cnt; k++)
			dis[k] = dep[tr[k]];
		res = min(res, cal(ans, m));
	}
	cout << res << endl;
	return 0;
}