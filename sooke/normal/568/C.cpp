#include <bits/stdc++.h>

inline int read() {
    char opt[3];
    scanf("%s", opt);
    return opt[0] == 'V' ? 0 : 1;
}

const int N = 405;

int n, m, q, bln[N], clz[N][2], vis[N], gg[N], tag[N];
char str[N], ans[N];
bool rch[N][N], ban[N];
std::vector<int> e[N];

void dfs1(int u, int s) {
    if (vis[u] == s) { return; }
    vis[u] = s; rch[s][u] = true;
    for (auto v : e[u]) { dfs1(v, s); }
}

void dfs2(int u) {
    if (tag[u] != 0) { return; }
    tag[u] = 1; tag[u ^ 1] = -1;
    for (auto v : e[u]) { dfs2(v); }
}

bool check(int u) {
    if (tag[u] == 1) { return true; }
    if (tag[u] == -1) { return false; }
    dfs2(u);
    return true;
}

bool solve() {
    for (int k = n; k >= 0; k--) {
        for (int u = 0; u < n * 2; u++) {
            tag[u] = 0;
        }
        for (int u = 0; u < n * 2; u++) {
            if (ban[u ^ 1]) { dfs2(u); }
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int s = 0;
            if (i < k) { s = str[i] - 'a'; }
            if (i == k) { s = str[i] - 'a' + 1; }
            ans[i] = '?';
            if (clz[s][0] < clz[s][1]) {
                if (ans[i] == '?' && clz[s][0] < m && check(i * 2 + 0)) {
                    ans[i] = clz[s][0] + 'a';
                }
                if (ans[i] == '?' && clz[s][1] < m && check(i * 2 + 1)) {
                    ans[i] = clz[s][1] + 'a';
                }
            } else {
                if (ans[i] == '?' && clz[s][1] < m && check(i * 2 + 1)) {
                    ans[i] = clz[s][1] + 'a';
                }
                if (ans[i] == '?' && clz[s][0] < m && check(i * 2 + 0)) {
                    ans[i] = clz[s][0] + 'a';
                }
            }
            if (ans[i] == '?') { flag = false; break; }
            if (i < k && ans[i] != str[i]) { flag = false; break; }
        }
        if (flag) { return true; }
    }
    return false;
}

int main() {
    scanf("%s", str); m = strlen(str);
    for (int i = 0; i < m; i++) {
        bln[i] = str[i] == 'V' ? 0 : 1;
    }
    clz[m][0] = clz[m][1] = m;
    for (int i = m - 1; i >= 0; i--) {
        clz[i][0] = clz[i + 1][0];
        clz[i][1] = clz[i + 1][1];
        clz[i][bln[i]] = i;
    }
    scanf("%d%d", &n, &q);
    for (int i = 0; i < q; i++) {
        int u, v, optu, optv;
        scanf("%d", &u); u--; optu = read();
        scanf("%d", &v); v--; optv = read();
        e[u * 2 + optu].push_back(v * 2 + optv);
        optu ^= 1; optv ^= 1;
        e[v * 2 + optv].push_back(u * 2 + optu);
    }
    for (int u = 0; u < n * 2; u++) {
        dfs1(u, u);
    }
    for (int u = 0; u < n * 2; u++) {
        for (int v = 0; v < n * 2; v++) {
            if (rch[u][v] && rch[u][v ^ 1]) {
                ban[u] = true; break;
            }
        }
    }
    for (int u = 0; u < n * 2; u++) {
        if (ban[u] && ban[u ^ 1]) {
            printf("-1\n"); return 0;
        }
    }
    scanf("%s", str);
    if (solve()) {
        printf("%s\n", ans);
    } else {
        printf("-1\n");
    }
    return 0;
}