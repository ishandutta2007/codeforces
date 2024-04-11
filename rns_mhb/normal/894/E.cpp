#include <bits/stdc++.h>
using namespace std;
#define N 1000010
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
#define fi first
#define se second
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, s;
vector<pii>v[N], a[N];
vector<int>rv[N];

int C, col[N], ord[N], ft;
bool vis[N];

void dfs(int x) {
	vis[x] = 1;
	for (int i = 0; i < v[x].size(); i ++) if (!vis[v[x][i].fi]) dfs(v[x][i].fi);
	ord[ft--] = x;
}
void rdfs(int x) {
	col[x] = C;
	for (int i = 0; i < rv[x].size(); i ++) if (!col[rv[x][i]]) rdfs(rv[x][i]);
}

void SCC() {
	ft = n;
	for (int i = 1; i <= n; i ++) if (!vis[i]) dfs(i);
	C = 0;
	for (int i = 1; i <= n; i ++) if (!col[ord[i]]) C ++, rdfs(ord[i]);
}

ll vw[N], dp[N];

void calc(int u) {
	vis[u] = 1;
	for (int i = 0; i < a[u].size(); i ++) {
		if (!vis[a[u][i].fi]) calc(a[u][i].fi);
		chkmax(dp[u], a[u][i].se + dp[a[u][i].fi]);
	}
	dp[u] += vw[u];
}

int main() {
	scanf("%d%d", &n, &m);
	int x, y, w;
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d%d", &x, &y, &w);
		v[x].pb(mp(y, w));
		rv[y].pb(x);
	}
	scanf("%d", &s);
	SCC();
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < v[i].size(); j ++) {
			int u = v[i][j].fi;
			if (col[u] == col[i]) {
				ll k = (sqrt(8ll * v[i][j].se) + 1) / 2;
				vw[col[i]] += k * (6ll * v[i][j].se - k * k + 1) / 6;
			}
			else a[col[i]].pb(mp(col[u], v[i][j].se));
		}
	}
	for (int i = 1; i <= C; i ++) vis[i] = 0;
	calc(col[s]);
	cout<<dp[col[s]]<<endl;
    return 0;
}