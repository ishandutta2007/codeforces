#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, k, ans0, ans1, dis[N], a[N];
std::vector<int> e[N], _e[N];

void bfs(int s) {
    for (int u = 0; u <= n; u++) { dis[u] = -1; }
    std::queue<int> que; dis[s] = 0;
    for (que.push(s); !que.empty(); que.pop()) {
        int u = que.front();
        for (auto v : e[u]) {
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                que.push(v);
            }
        }
    }
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        e[v].push_back(u);
        _e[u].push_back(v);
    }
    k = read();
    for (int i = 0; i < k; i++) {
        a[i] = read();
    }
    bfs(a[k - 1]);
    for (int i = 1; i < k; i++) {
        int u = a[i - 1], v = a[i];
        if (dis[u] != dis[v] + 1) { ans0++; }
        bool flag = false;
        for (auto w : _e[u]) {
            if (dis[u] - 1 == dis[w] && w != v) { flag = true; }
        }
        if (flag) { ans1++; }
    }
    printf("%d %d\n", ans0, ans1);
    return 0;
}