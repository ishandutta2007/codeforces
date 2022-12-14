#include <bits/stdc++.h>

using namespace std;

#define N 100005

vector <int> adj[N], chr[N];

int d[N];
int Q[N];
bool vis[N];

int Min;
int cnt[N];
bool isbegin[N];

vector <int> V[2];
int pa[N], pc[N];
bool chk[N];
char s[N];

main() {
    //freopen("G.in", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i ++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back(b);
        adj[b].push_back(a);
        chr[a].push_back(c);
        chr[b].push_back(c);
    }
    for (int i = 0; i < n; i ++) {
        pa[i] = -1;
        d[i] = n + 10;
    }

    int h = 1, t = 0;
    Q[++ t] = 0, vis[0] = 1, d[0] = 0;
    while (h <= t) {
        int cur = Q[h ++];
        for (int i = 0; i < adj[cur].size(); i ++) {
            int nxt = adj[cur][i];
            if (vis[nxt]) continue;
            vis[nxt] = 1;
            d[nxt] = d[cur] + 1;
            Q[++ t] = nxt;
        }
    }

    Min = n + 10;

    h = 1, t = 0;
    Q[++ t] = n - 1, isbegin[n - 1] = 1, cnt[n - 1] = 0;
    while (h <= t) {
        int cur = Q[h ++];
        if (Min > d[cur]) Min = d[cur];
        for (int i = 0; i < adj[cur].size(); i ++) {
            int nxt = adj[cur][i];
            if (isbegin[nxt]) continue;
            if (chr[cur][i]) continue;
            isbegin[nxt] = 1;
            pa[nxt] = cur;
            cnt[nxt] = cnt[cur] + 1;
            Q[++ t] = nxt;
        }
    }

    for (int i = 0; i < n; i ++) {
        if (d[i] > Min) isbegin[i] = 0;
    }
    for (int i = 0; i < n; i ++) if (isbegin[i]) {
        chk[i] = 1;
        V[0].push_back(i);
    }

    bool bf = 0;
    int len = 0;
    for (int runs = 0; runs < Min; runs ++) {
        V[bf ^ 1].clear();
        int mn = 11;
        for (int i = 0; i < V[bf].size(); i ++) {
            int u = V[bf][i];
            for (int j = 0; j < adj[u].size(); j ++) {
                int v = adj[u][j];
                if (d[v] != d[u] - 1) continue;
                if (chr[u][j] < mn) mn = chr[u][j];
            }
        }
        s[len ++] = mn + '0';
        for (int i = 0; i < V[bf].size(); i ++) {
            int u = V[bf][i];
            for (int j = 0; j < adj[u].size(); j ++) {
                int v = adj[u][j];
                if (d[v] != d[u] - 1) continue;
                if (chr[u][j] == mn) {
                    if (pa[v] == -1) pa[v] = u;
                    else if (cnt[pa[v]] > cnt[u]) pa[v] = u;
                    cnt[v] = cnt[u] + 1;
                    if (!chk[v]) {
                        chk[v] = 1;
                        V[bf ^ 1].push_back(v);
                    }
                }
            }
        }
        bf ^= 1;
    }
    s[len] = 0;
    if (!len) strcpy(s, "0");
    printf("%s\n%d\n", s, cnt[0] + 1);
    int src;
    for (src = 0; src != n - 1; src = pa[src]) printf("%d ", src);
    printf("%d\n", n - 1);
}