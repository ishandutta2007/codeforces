#include <bits/stdc++.h>
using namespace std;

#define N 100100
#define M 1046

int n, m, deg[N], g[N];
vector <int> adj[N], radj[N];
const int mod = 998244353;

int expmod(int x, int n) {
	int rlt = 1;
	while (n) {
		if (n & 1) rlt = 1ll * rlt * x % mod;
		x = 1ll * x * x % mod, n >>= 1;
	}
	return rlt;
}

inline int invmod(int x) {
	return expmod(x, mod - 2);
}

int a[M][M], b[M], x[M];
int sgn(int a) { return a < 0 ? -1 : a > 0; }
int Gauss(int n) {
    int r = 0; //order of coefficient matrix
    for (int i = 0; i < n; i ++) {
        int j = r;
        for (int k = r; k < n; k ++) if (abs(a[k][i]) > abs(a[j][i])) j = k;
        if (!sgn(a[j][i])) continue;
        swap(b[r], b[j]);
        for (int k = 0; k < n; k ++) swap(a[r][k], a[j][k]);
        int c = invmod(a[r][i]);
        for (j = 0; j < n; j ++) if (j != r && sgn(a[j][i])) {
                int tmp = 1ll * a[j][i] * c % mod;
                b[j] = (b[j] - 1ll * tmp * b[r]) % mod;
                for (int k = 0; k < n; k ++) a[j][k] = (a[j][k] - 1ll * tmp * a[r][k]) % mod;
            }
        r ++;
    }
    for (int i = 0; i < n; i ++) x[i] = 0;
    for (int i = 0; i < n; i ++) if (sgn(b[i])) {
            int j;
            for (j = 0; j < n && !sgn(a[i][j]); j ++);
            if (j == n) return 0; //no solution
            else x[j] = 1ll * b[i] * invmod(a[i][j]) % mod;
        }
    return r < n ? -1 : 1;
}

bool vis[M];
int cnt[M];

int main() {
    scanf("%d %d", &n, &m);
    while (m --) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		radj[v].push_back(u);
		deg[u] ++;
    }
    queue <int> Q;
    for (int i = 1; i <= n; i ++) if (!deg[i]) Q.push(i);
    while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (auto v : adj[u]) vis[g[v]] = 1;
		while (vis[g[u]]) g[u] ++;
		for (auto v : adj[u]) vis[g[v]] = 0;
		for (auto v : radj[u]) {
			deg[v] --;
			if (!deg[v]) Q.push(v);
		}
    }
    int mx = *max_element(g + 1, g + n + 1);
    int up = 1;
    while (up <= mx) up <<= 1;
    for (int i = 1; i <= n; i ++) cnt[g[i]] ++;

    for (int i = 0; i < up; i ++) {
		b[i] = (i > 0);
		for (int j = 0; j < up; j ++) a[i][i^j] = -cnt[j];
		a[i][i] += (n + 1);
    }


    Gauss(up);
    if (x[0] < 0) x[0] += mod;
    printf("%d\n", x[0]);

    return 0;
}