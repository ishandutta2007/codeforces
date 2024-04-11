#include <bits/stdc++.h>
#define ll long long
#define maxn 300005 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
#define maxn 300005
using namespace std;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

vector<pi> nx[5][maxn];
pi son[20][5][maxn / 5];
ll pl[20][5][maxn / 5];

ll sz[5][maxn];
int n, c, q;
int x[maxn];
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> c >> q;
		for (int i = 1; i <= n; i++)
			scanf("%d", &x[i]);
		for (int i = 1; i <= n + 1; i++)
			for (int j = 0; j <= c; j++) {
				sz[j][i] = 0;
				nx[j][i].clear();
				for (int q = 0; q < 20; q++)
					son[q][j][i] = mp(0, 0), 
					pl[q][j][i] = 0;
			}
		for (int i = 0; i <= c; i++)
			sz[i][n + 1] = 1;
		for (int i = n; i >= 1; i--)
			for (int j = 0; j <= c; j++) {
				sz[j][i] = 0;
				nx[j][i].clear();
				vector<pi> cur;
				for (int t = i; t <= min(n, i + j); t++)
					cur.pb(mp(x[t], t));
				sort(cur.begin(), cur.end());
				ll nsz = 0;
				ll sum = 0;
				for (auto v : cur) {
					pi ur = mp(j - (v.se - i), v.se + 1);
					nx[j][i].pb(ur);
					sz[j][i] += sz[ur.fi][ur.se];
					if (chkmax(nsz, sz[ur.fi][ur.se]))
						son[0][j][i] = ur, 
						pl[0][j][i] = 1 + sum;
					
					sum += sz[ur.fi][ur.se]; 
				}
				for (int t = 1; t < 20; t++) {
					pi um = son[t - 1][j][i];
					son[t][j][i] = son[t - 1][um.fi][um.se];
					pl[t][j][i] = pl[t - 1][j][i] + pl[t - 1][um.fi][um.se] - 1;
				}
			}
		while (q--) {
			int p;
			ll j;
			scanf("%d%lld", &p, &j);
			pi cur = mp(c, 1);
			int ans = 0;
			if (j > sz[cur.fi][cur.se]) ans = -1;
			else {
				while (1) {
					int fl = 0;
					for (int i = 19; i >= 0; i--) {
						pi ed = son[i][cur.fi][cur.se];
						if (ed.se > p) continue;
						if (ed.se == 0) continue;
						if (pl[i][cur.fi][cur.se] > j) continue;
						if (pl[i][cur.fi][cur.se] + sz[ed.fi][ed.se] - 1 < j) continue;
						j -= pl[i][cur.fi][cur.se] - 1;
						cur = ed;
					}
					for (auto h : nx[cur.fi][cur.se]) {
						if (j <= sz[h.fi][h.se]) {
							if (h.se > p) {
								// reverse cur.se ~ h.se - 1
								int epl = cur.se + h.se - 1 - p;
								ans = x[epl];
								break;
							}
							cur = h;
							break;
						}
						else 
							j -= sz[h.fi][h.se];
					}
					if (ans) break;
				}
			}
			printf("%d\n", ans);
		}
		
	}
	return 0;
}
/*
2
3 1 9
1 2 3
3 2


*/