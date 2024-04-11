#include <bits/stdc++.h>

inline void read(int &x) {
    int c;
    while (!isdigit(c = getchar()));
    x = c - '0';
    while (isdigit(c = getchar())) {
        x = x * 10 + c - '0';
    }
}

const int max_N = (int) 1e5 + 21;
const int max_M = max_N * 21;

int n, m, dfn[max_N], low[max_N], cnt, Pst[max_N], Ptop, Est[max_M], Etop, ans;

std::vector<std::pair<int, int>> vec[max_N];

bool ret[max_M];

void tarjan(int u, int pre) {
    dfn[u] = low[u] = ++cnt;
    Pst[++Ptop] = u;
    for (auto e : vec[u]) {
        int v = e.first, w = e.second;
        if (w == pre) continue;
        if (!dfn[v]) {
            Est[++Etop] = w;
            tarjan(v, w);
            low[u] = std::min(low[u], low[v]);
            if (dfn[u] <= low[v]) {
                int Psiz = 1, Esiz = 0;
                do {
                    ++Psiz;
                } while (Pst[Ptop--] != v);
                std::vector<int> tmp;
                do {
                    ++Esiz;
                    tmp.push_back(Est[Etop]);
                } while (Est[Etop--] != w);
                if (Psiz == Esiz) {
                    for (auto i : tmp) {
                        ++ans;
                        ret[i] = true;
                    }
                }
            }
        } else if (dfn[v] < dfn[u]) {
            Est[++Etop] = w;
            low[u] = std::min(low[u], dfn[v]);
        }
    }
}

int main() {
    read(n), read(m);
    for (int i = 1, u, v; i <= m; ++i) {
        read(u), read(v);
        vec[u].push_back({v, i});
        vec[v].push_back({u, i});
    }
    for (int u = 1; u <= n; ++u)
        if (!dfn[u]) {
            tarjan(u, 0);
        }
    printf("%d\n", ans);
    if (!ans) return puts(""), 0;
    for (int i = 1; i <= m; ++i)
        if (ret[i]) {
            printf("%d%c", i, " \n"[!--ans]);
        }
    return 0;
}