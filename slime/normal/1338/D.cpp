//Awwawa! Dis cold yis ratten buy tE'MMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
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
int dp[2][3][maxn]; //   
vi eg[maxn];
int fa[maxn];
pi cmx(int a, int fa, int x, int y) {
	int mx[2] = {0, 0};	
	for (auto v : eg[a]) {
		if (v == fa) continue;
		int cr = dp[x][y][v];
		if (cr > mx[0]) mx[1] = mx[0], mx[0] = cr;
		else if (cr > mx[1]) mx[1] = cr;  
	} 
	return mp(mx[0], mx[1]);
}
void dfs(int a, int fa) {
	for (auto v : eg[a]) {
		if (v == fa) continue;
		dfs(v, a);
	}
	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < 3; j++) {
			dp[i][j][a] = 0;
			// 
			if (i == 1) {
				int cans = 1;
				for (auto v : eg[a]) {
					if (v == fa) continue;
					cans = max(cans, dp[0][min(2, j + 1)][v] + 1);
				}
				if (j == 0) { //  
					pi qr = cmx(a, fa, 0, 2);
					cans = max(cans, qr.fi + qr.se + 1);
				}
				dp[i][j][a] = cans;
			} 
			//
			// 1 
			// 2
			int srs = eg[a].size();
			if (fa) srs--;
			int cu = 0;
			for (int q = 0; q <= 2; q++) // q >= 2 
				for (int m = 0; m <= srs - q; m++) {
					if (j == 2 && q == 2) continue;
					if (m + j >= 2) m = srs - q;
					int tt = min(2, m + j);
					if (q == 2) tt = 2;
					pi um = cmx(a, fa, 1, tt);
					int r[2] = {um.fi, um.se};
					int cm = m;
					for (int t = 0; t < q; t++)
						cm += r[t];
					cu = max(cu, cm);
				}
			dp[i][j][a] = max(dp[i][j][a], cu);
	//		cout << i << ' ' << j << ' ' << a << ' ' << dp[i][j][a] << endl;
		}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) { 
		int u, v;
		scanf("%d%d", &u, &v);
		eg[u].pb(v), eg[v].pb(u);
	}
	dfs(1, 0);
	printf("%d\n", dp[1][0][1]);
	return 0;
}