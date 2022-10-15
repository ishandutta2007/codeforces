#include <cctype>
#include <cstdio>
#include <vector>
#include <queue>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, s;
long long dis[N];
std::vector<std::pair<int, int>> e[N];
std::priority_queue<std::pair<long long, int>> que;

void build(int u, int l, int r) {
    if (l >= r) { return; }
    int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
    if (l == mid) {
        e[n + u].push_back({l, 0});
        e[l].push_back({n * 5 + u, 0});
    } else {
        e[n + u].push_back({n + ls, 0});
        e[n * 5 + ls].push_back({n * 5 + u, 0});
        build(ls, l, mid);
    }
    if (mid + 1 == r) {
        e[n + u].push_back({r, 0});
        e[r].push_back({n * 5 + u, 0});
    } else {
        e[n + u].push_back({n + rs, 0});
        e[n * 5 + rs].push_back({n * 5 + u, 0});
        build(rs, mid + 1, r);
    }
}
void link1(int u, int l, int r, int pl, int pr, int v, int w) {
    if (l == pl && r == pr) {
        u = l == r ? l : n + u;
        e[v].push_back({u, w}); return;
    } int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
    if (pr <= mid) { link1(ls, l, mid, pl, pr, v, w); }
    else if (pl > mid) { link1(rs, mid + 1, r, pl, pr, v, w); }
    else {
        link1(ls, l, mid, pl, mid, v, w);
        link1(rs, mid + 1, r, mid + 1, pr, v, w);
    }
}
void link2(int u, int l, int r, int pl, int pr, int v, int w) {
    if (l == pl && r == pr) {
        u = l == r ? l : n * 5 + u;
        e[u].push_back({v, w}); return;
    } int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
    if (pr <= mid) { link2(ls, l, mid, pl, pr, v, w); }
    else if (pl > mid) { link2(rs, mid + 1, r, pl, pr, v, w); }
    else {
        link2(ls, l, mid, pl, mid, v, w);
        link2(rs, mid + 1, r, mid + 1, pr, v, w);
    }
}

void dijkstra() {
    for (int i = 0; i < n * 10; i++) { dis[i] = 1e18; }
    dis[s] = 0; que.push({0, s});
    while (!que.empty()) {
        long long d = -que.top().first; int u = que.top().second; que.pop();
        if (dis[u] < d) { continue; }
        for (auto i : e[u]) {
            int v = i.first, w = i.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w; que.push({-dis[v], v});
            }
        }
    }
}

int main() {
    n = read(); m = read(); s = read() - 1;
    build(1, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int opt = read();
        if (opt == 1) {
            int u = read() - 1, v = read() - 1, w = read();
            e[u].push_back({v, w});
        } else if (opt == 2) {
            int u = read() - 1, l = read() - 1, r = read() - 1, w = read();
            link1(1, 0, n - 1, l, r, u, w);
        } else if (opt == 3) {
            int u = read() - 1, l = read() - 1, r = read() - 1, w = read();
            link2(1, 0, n - 1, l, r, u, w);
        }
    }
    dijkstra();
    for (int i = 0; i < n; i++) { printf("%I64d ", dis[i] == 1e18 ? -1 : dis[i]); }
    return 0;
}