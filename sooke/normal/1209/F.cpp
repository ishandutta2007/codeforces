#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 1e9 + 7;

const int N = 1e6 + 5;

int n, m, tot, dis[N];
bool vis[N];
std::vector<int> vecc, e[N][10];
std::vector<std::vector<int>> vec, vecv;

void insert(int u, int v, int w) {
    for (; w >= 10; w /= 10) {
        e[++tot][w % 10].push_back(v); v = tot;
    } e[u][w].push_back(v);
}

void bfs() {
    vecv.push_back({1});
    while (true) {
        vec = vecv;
        if (vec.empty()) { break; }
        vecv.clear();
        for (auto c : vec) {
            for (int i = 0; i < 10; i++) {
                vecc.clear();
                for (auto u : c) {
                    for (auto v : e[u][i]) {
                        if (vis[v]) { continue; }
                        vis[v] = true; vecc.push_back(v);
                        dis[v] = (dis[u] * 10ll + i) % mod;
                    }
                }
                if (!vecc.empty()) { vecv.push_back(vecc); }
            }
        }
    }
}

int main() {
    n = read(); m = read(); tot = n;
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = i;
        insert(u, v, w); insert(v, u, w);
    } bfs();
    for (int i = 2; i <= n; i++) { printf("%d\n", dis[i]); }
    return 0;
} //