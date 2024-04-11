#include <bits/stdc++.h>
#define LL long long
#define pii pair<int, int >
using namespace std;
const int N = 1e5 + 100, M = 3e5 + 7;
const LL MOD = 1e9 +7;
vector<pii > p[N];
LL dp[M], gou[M], dp1[M], gou1[M];
int f[N], par[N][20], dep[N], dis[N], u[N], v[N], w[N];
bool vis[N];
vector<int > vec[50];

int find(int x){
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void dfs(int x, int fa, int r){
	par[x][0] = fa; dep[x] = dep[fa] + 1; dis[x] = r;
	for (pii v : p[x]) if (v.first != fa){
		dfs(v.first, x, v.second);
	}
}
void init(int n){
	for (int i = 1; i < 20; i++){
		for (int j = 1; j <= n; j++){
			par[j][i] = par[par[j][i - 1]][i - 1];
		}
	}
}
int lca(int u, int v){
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 19; i >= 0; i--) if ((dep[u] - dep[v]) >> i & 1) u = par[u][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; i--) if (par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
	return par[u][0];
}

void fwt(LL a[], int n){
    for (int d = 1; d < n; d <<= 1){
		for (int m = d << 1, i = 0; i < n; i += m){
			for (int j = 0; j < d; j++){
				LL x = a[i + j], y = a[i + j + d];
				a[i + j] = (x + y) % MOD;
				a[i + j + d] = (x - y + MOD) % MOD;
			}
		}
    }
}
void ifwt(LL a[], int n){
	int inv2 = (MOD + 1) / 2;
	for (int d = 1; d < n; d <<= 1){
		for (int m = d << 1, i = 0; i < n; i += m){
			for (int j = 0; j < d; j++){
				LL x = a[i + j], y = a[i + j + d];
				a[i + j] = (x + y) * inv2 % MOD;
				a[i + j + d] = (x - y + MOD) * inv2 % MOD;
			}
		}
	}
}

int main(){
	//freopen("in.txt", "r", stdin);
	int n, m, n1 = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) f[i] = i;
    int x = 0;
	for (int i = 1; i <= m; i++){
		scanf("%d%d%d", &u[i], &v[i], &w[i]); x ^= w[i];
        if (find(u[i]) != find(v[i])){
			vis[i] = true;
            p[u[i]].push_back({v[i], w[i]}); p[v[i]].push_back({u[i], w[i]});
            f[find(u[i])] = find(v[i]);
			n1++;
        }
	}
	if (n1 != n - 1){
		printf("0 0");
		return 0;
	}
	dfs(1, 0, 0);
	init(n);
	int cnt = 0;
	for (int i = 1; i <= m; i++){
		if (!vis[i]){
            vec[++cnt].push_back(w[i]);
			int now = u[i], lc = lca(u[i], v[i]);
			while (now != lc){
				vec[cnt].push_back(dis[now]); now = par[now][0];
			}
			now = v[i];
			while (now != lc){
				vec[cnt].push_back(dis[now]); now = par[now][0];
			}
		}
	}
	int t = 131072;
	for (int i = 0; i < t; i++) dp[i] = 0;
    dp[x] = 1; fwt(dp, t);
    for (int i = 0; i < t; i++) dp1[i] = dp[i];
    for (int i = 1; i <= cnt; i++){
		for (int j = 0; j < t; j++) gou[j] = 0, gou1[j] = 0;
        for (int j : vec[i]) gou[j]++, gou1[j] = 1;
		fwt(gou, t); fwt(gou1, t);
        for (int j = 0; j < t; j++){
			dp[j] = dp[j] * gou[j] % MOD;
			dp1[j] = dp1[j] * gou1[j] % MOD;
        }
    }
    ifwt(dp, t); ifwt(dp1, t);
    for (int i = 0; i < t; i++){
		if (dp1[i]){
			printf("%d %lld\n", i, dp[i]);
			return 0;
		}
    }
	return 0;
}