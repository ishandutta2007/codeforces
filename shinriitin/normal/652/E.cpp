#include <bits/stdc++.h>

const int max_N = (int) 3e5 + 21;

int n, m, a, b, ebcc_cnt, ebcc_no[max_N], st[max_N], top;

int dfn[max_N], low[max_N], cnt;

std::vector<std::pair<int, bool>> vec[max_N];

std::vector<int> ebcc[max_N];

void tarjan(int u, int p) {
    st[++top] = u;
    dfn[u] = low[u] = ++cnt;
    for (auto e : vec[u]) {
        int v = e.first;
        if (v == p) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = std::min(low[u], low[v]);
        } else if (dfn[v] < dfn[u]) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        std::vector<int>().swap(ebcc[++ebcc_cnt]);
        do {
            ebcc_no[st[top]] = ebcc_cnt;
            ebcc[ebcc_cnt].push_back(st[top]);
        } while (st[top--] != u);
    }
}

bool vis[max_N][2];

void dfs(int x, int pre, bool sta) {
    vis[x][sta] = true;
    if (!sta) {
        for (auto u : ebcc[x]) {
            for (auto e : vec[u]) {
                int v = e.first, w = e.second;
                if (ebcc_no[u] != ebcc_no[v]) continue;
                if (w) {
                    vis[x][sta = true] = true;
                    break;
                }
            }
        }
    }
    for (auto u : ebcc[x]) {
        for (auto e : vec[u]) {
            int v = e.first, w = e.second;
            if (ebcc_no[v] == pre) continue;
            if (ebcc_no[u] == ebcc_no[v]) continue;
            if (vis[ebcc_no[v]][sta | w]) continue;
            dfs(ebcc_no[v], x, sta | w);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v, w; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        vec[u].push_back({v, w});
        vec[v].push_back({u, w});
    }
    tarjan(1, 0);
    scanf("%d%d", &a, &b);
    dfs(ebcc_no[a], 0, false);
    puts(vis[ebcc_no[b]][true] ? "YES" : "NO");
    return 0;
}