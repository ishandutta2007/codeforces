#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 100005, MaxD = 20;

int N, M, Q, d[MaxN], p[MaxD][MaxN];
std::vector<int> e[MaxN], w[MaxD][MaxN];

void go(int i, int parent, int depth) {
    p[0][i] = parent;
    d[i] = depth;
    for (int j : e[i]) if (j != parent) go(j, i, depth+1);
}
std::vector<int> add(const std::vector<int> &a, const std::vector<int> &b) {
    std::vector<int> v;
    int i = 0, j = 0;
    while (i+j < 10 && i < sz(a) && j < sz(b)) {
        if (a[i] < b[j]) { v.push_back(a[i]); i++; }
        else { v.push_back(b[j]); j++; }
    }
    while (i+j < 10 && i < sz(a)) { v.push_back(a[i]); i++; }
    while (i+j < 10 && j < sz(b)) { v.push_back(b[j]); j++; }
    return v;
}
std::pair<int, std::vector<int>> lca(int a, int b) {
    std::vector<int> min;
    if (d[a] > d[b]) std::swap(a, b);
    for (int i = MaxD-1; i >= 0; i--) if (d[b] - (1 << i) >= d[a]) {
        min = add(min, w[i][b]);
        b = p[i][b];
    }
    if (a == b) {
        min = add(min, w[0][a]);
        return std::make_pair(a, min);
    }
    for (int i = MaxD-1; i >= 0; i--) if (p[i][b] != p[i][a]) {
        min = add(min, w[i][b]);
        b = p[i][b];
        min = add(min, w[i][a]);
        a = p[i][a];
    }
    min = add(add(add(min, w[0][p[0][a]]), w[0][a]), w[0][b]);
    return std::make_pair(p[0][a], min);
}

int main()
{
    scanf("%d%d%d", &N, &M, &Q);
    for (int i = 0; i < N-1; i++) {
        int u, v; scanf("%d%d", &u, &v); u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 0; i < M; i++) {
        int c; scanf("%d", &c); c--;
        w[0][c].push_back(i+1);
    }
    go(0, -1, 0);
    for (int d = 0; d+1 < MaxD; d++) for (int i = 0; i < N; i++) {
        p[d+1][i] = p[d][p[d][i]];
        if (p[d][i] == -1) w[d+1][i] = w[d][i];
        else w[d+1][i] = add(w[d][i], w[d][p[d][i]]);
    }
    for (int i = 0; i < Q; i++) {
        int u, v, a; scanf("%d%d%d", &u, &v, &a); u--; v--;
        std::pair<int, std::vector<int>> info = lca(u, v);
        int k = std::min(a, sz(info.second));
        printf("%d ", k);
        for (int i = 0; i < k; i++) printf("%d ", info.second[i]);
        printf("\n");
    }
}