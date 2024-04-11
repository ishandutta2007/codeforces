#include <bits/stdc++.h>

const int N = 755, V = 1e7 + 5;

char str[V];
int n, end[N], cp[N];
bool e[N][N], vis[N], visl[N], visr[N], used[N];
std::vector<int> ans;

struct AcAutomaton {
    int tot, son[V][2], ft[V], fail[V], clz[V];
    
    AcAutomaton() { tot = 1; son[0][0] = son[0][1] = -1; }

    int insert(char str[]) {
        int u = 1;
        for (int i = 0; str[i]; i++) {
            int x = str[i] - 'a';
            if (son[u][x] == 0) { son[u][x] = ++tot; }
            ft[son[u][x]] = u; u = son[u][x];
        }
        return u;
    }

    void build() {
        std::queue<int> que;
        for (int x = 0; x < 2; x++) {
            if (son[1][x] > 0) {
                que.push(son[1][x]);
                fail[son[1][x]] = 1;
            } else {
                son[1][x] = 1;
            }
        }
        for (; !que.empty(); que.pop()) {
            int u = que.front(), v;
            if (clz[u] == 0) { clz[u] = clz[fail[u]]; }
            for (int x = 0; x < 2; x++) {
                if (son[u][x] > 0) {
                    for (v = fail[u]; son[v][x] == 0; v = fail[v]);
                    que.push(son[u][x]);
                    fail[son[u][x]] = son[fail[u]][x] == 0 ? 1 : son[fail[u]][x];
                } else {
                    son[u][x] = son[fail[u]][x];
                }
            }
        }
    }
} aam;

bool hungary(int u) {
    if (vis[u]) { return false; }
    vis[u] = true;
    for (int v = 1; v <= n; v++) {
        if (e[u][v] == 0) { continue; }
        if (cp[v] == 0 || hungary(cp[v])) {
            cp[v] = u; return true;
        }
    }
    return false;
}

void dfs(int u) {
    if (visl[u]) { return; }
    visl[u] = true;
    for (int v = 1; v <= n; v++) {
        if (e[u][v] == 0) { continue; }
        if (!visr[v]) { visr[v] = true; dfs(cp[v]); }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str);
        end[i] = aam.insert(str);
        aam.clz[end[i]] = i;
    }
    aam.build();
    for (int i = 1; i <= n; i++) {
        for (int u = end[i]; u != 1; u = aam.ft[u]) {
            if (aam.clz[u] != i) {
                e[aam.clz[u]][i] = true;
            } else {
                e[aam.clz[aam.fail[u]]][i] = true;
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                e[i][j] |= e[i][k] & e[k][j];
            }
        }
    }
    int cnt = 0;
    for (int u = 1; u <= n; u++) {
        memset(vis, false, n + 1);
        cnt += hungary(u);
    }
    for (int v = 1; v <= n; v++) {
        used[cp[v]] = true;
    }
    for (int u = 1; u <= n; u++) {
        if (used[u]) { continue; }
        dfs(u);
    }
    for (int i = 1; i <= n; i++) {
        if (visl[i] && !visr[i]) { ans.push_back(i); }
    }
    printf("%d\n", ans.size());
    for (auto i : ans) { printf("%d ", i); }
    return 0;
}