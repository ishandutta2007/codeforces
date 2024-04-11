#include <bits/stdc++.h>

const int max_N = (int) 1e5 + 21;
const int sqrt_N = 400 + 21;

int n, q, t[max_N], v[max_N];

std::vector<int> e[max_N];

bool black[max_N], key[max_N], clear[max_N];

struct v_edge {
    int v, white, total;
};

std::vector<v_edge> ve[max_N];

int lazy[max_N];

void build(int u, int p = 0, int white = 0, int total = 0) {
    if (key[u]) {
        if (p) ve[p].push_back({u, white, total});
        for (auto v : e[u]) build(v, u);
    } else {
        if (!black[u]) ++white;
        for (auto v : e[u]) build(v, p, white, total + 1);
    }
}

void solve1(int u) {
    if (!black[u]) {
        black[u] = true;
        return;
    }
    ++lazy[u];
    for (auto edge : ve[u]) {
        if (edge.white + 1 > lazy[u]) continue;
        solve1(edge.v);
    }
}

void solve2(int u) {
    black[u] = false;
    lazy[u] = 0;
    clear[u] = true;
    for (auto &edge : ve[u]) {
        edge.white = edge.total;
        solve2(edge.v);
    }
}

void rebuild(int u, int p = 0, bool clr = false) {
    if (key[u]) {
        p = lazy[u];
        clr |= clear[u];
    } else {
        if (clr) black[u] = false;
        if (!black[u] && p) {
            black[u] = true;
            --p;
        }
    }
    for (auto v : e[u]) rebuild(v, p, clr);
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 2, p; i <= n; ++i) {
        scanf("%d", &p);
        e[p].push_back(i);
    }
    for (int i = 1; i <= q; ++i) {
        scanf("%d%d", t + i, v + i);
    }
    for (int T = 1; T <= q; T += sqrt_N) {
        for (int j = 0; j < sqrt_N && T + j <= q; ++j) {
            key[v[T + j]] = true;
        }
        build(1);
        for (int j = 0; j < sqrt_N && T + j <= q; ++j) {
            int i = T + j;
            if (t[i] == 1) {
                solve1(v[i]);
            } else if (t[i] == 2) {
                solve2(v[i]);
            } else {
                puts(black[v[i]] ? "black" : "white");
            }
        }
        rebuild(1);
        for (int j = 0; j < sqrt_N && T + j <= q; ++j) {
            int i = v[T + j];
            lazy[i] = 0;
            key[i] = clear[i] = false;
            std::vector<v_edge>().swap(ve[i]);
        }
    }
    return 0;
}