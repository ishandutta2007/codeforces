//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 405 /*rem*/
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
int d[maxn][maxn]; 
vi eg[maxn];
int fl[maxn];
int hv[maxn]; //  
int diff[maxn], r[maxn];
int ans[maxn][maxn];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			d[i][j] = 1e9;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		d[a][b] = d[b][a] = 1;
		eg[a].pb(b), eg[b].pb(a);
	}
	for (int i = 1; i <= n; i++) d[i][i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				chkmin(d[j][k], d[j][i] + d[i][k]), 
				d[k][j] = d[j][k];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j < i) ans[i][j] = ans[j][i];
			else {
				memset(fl, 0, sizeof(fl));
				int res = 1;
				for (int k = 1; k <= n; k++) 
					if (d[i][k] + d[j][k] == d[i][j]) {
						if (fl[d[i][k]]) res = 0;
						else fl[d[i][k]] = 1;
					}
				for (int k = 1; k <= n; k++) 
					if ((d[i][k] - d[j][k] + d[i][j]) & 1) res = 0;
				if (res) {
					for (int k = 1; k <= n; k++) {
						diff[k] = (d[i][k] - d[j][k] + d[i][j]) / 2;
						r[k] = d[i][k];
					}
					for (int k = 1; k <= n; k++) {
						if (d[i][k] + d[j][k] == d[i][j]) continue;
						int cnt = 0;
						for (auto v : eg[k]) 
							if (diff[v] == diff[k] && r[v] == r[k] - 1) cnt++;
						res = 1ll * res * cnt % mod;
					}
				}
				ans[i][j] = res;
			}
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}