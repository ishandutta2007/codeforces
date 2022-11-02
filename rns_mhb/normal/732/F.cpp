#include <bits/stdc++.h>
using namespace std;
#define N 400040
#define pb push_back
#define x first
#define y second

typedef pair <int, int> pii;
vector <pii> v[N];
vector <pii> w[N];
vector <int> bd;
int s[N], f[N], vis[N];
int dt[N], low[N], T, C, cnt;
int c[N], rt[N], mx[N], sz[N];
int q[N], qs, g[N], rev[N];
int n, m;

void dfs_1(int k, int p = 0) {
    dt[k] = low[k] = ++ T;
    vis[k] = 1; q[++ qs] = k;
    for (int i = 0; i < v[k].size(); i ++) {
        pii r = v[k][i];
        if (r.x == p) continue;
        if (vis[r.x]) low[k] = min(low[k], dt[r.x]);
        else {
            dfs_1(r.x, k); rev[r.y] = k;
            low[k] = min(low[k], low[r.x]);
            if (low[r.x] > dt[k]) bd.pb(r.y);
        }
    }
    if (dt[k] == low[k]) {
        int y;
        ++ cnt; c[cnt] = C; sz[cnt] = 0;
        do {
			y = q[qs --];
            g[y] = cnt;
			sz[cnt] ++;
        } while (y != k) ;
    }
    return;
}

void dfs_2(int k, int p = 0) {
    for (int i = 0; i < w[k].size(); i ++) {
		pii x = w[k][i];
        if (x.x == p) continue;
        rev[x.y] = (k == g[s[x.y]] ? f[x.y] : s[x.y]);
        dfs_2(x.x, k);
    }
    return;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d", &s[i], &f[i]);
        v[s[i]].pb(pii(f[i], i));
        v[f[i]].pb(pii(s[i], i));
    }
    for (int i = 1; i <= n; i ++) if (!dt[i]) {
		mx[++ C] = 0;
		dfs_1(i);
    }
    for (int i = 1; i <= cnt; i ++) if (mx[c[i]] < sz[i]) mx[c[i]] = sz[i], rt[c[i]] = i;
    int ans = n + 1;
    for (int i = 1; i <= C; i ++) ans = min(ans, mx[i]);
    printf("%d\n", ans);
    for (int i = 0; i < bd.size(); i ++) {
        int j = bd[i];
        int x = g[s[j]], y = g[f[j]];
        w[x].pb(pii(y, j));
        w[y].pb(pii(x, j));
    }
    for (int i = 1; i <= C; i ++) dfs_2(rt[i]);
    for (int i = 1; i <= m; i ++) {
        int x = s[i], y = f[i];
        if (rev[i]) {
            if (rev[i] == x) swap(x, y);
            printf("%d %d\n", y, x);
        }
        else {
            if (dt[x] > dt[y]) swap(x, y);
            printf("%d %d\n", y, x);
        }
    }
}