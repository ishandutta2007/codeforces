#include <bits/stdc++.h>
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
typedef long long ll;

const int MaxM = 200005, MaxD = 20;

int N, M, a[MaxM], b[MaxM], r[MaxM], p[MaxD][MaxM], depth[MaxM];
std::vector<std::pair<int, int>> v, e[MaxM];
ll w[MaxM], max[MaxD][MaxM], total, ans[MaxM];

int find(int a) { return (r[a] == a ? a : r[a] = find(r[a])); }
void join(int a, int b) { r[find(b)] = find(a); }
void go(int i) {
    for (auto &x : e[i]) {
        int to = x.first, weight = x.second;
        if (to != p[0][i]) {
            depth[to] = depth[i] + 1;
            p[0][to] = i;
            max[0][to] = weight;
            go(to); // gah!
        }
    }
}
ll getMax(int a, int b) {
    ll m = -1e9;
    if (depth[a] > depth[b]) std::swap(a, b);
    for (int d = MaxD-1; d >= 0; d--) if (depth[b] - (1<<d) >= depth[a]) {
        domax(m, max[d][b]);
        b = p[d][b];
    }
    if (a == b) return m;
    for (int d = MaxD-1; d >= 0; d--) if (p[d][a] != p[d][b]) {
        domax(m, std::max(max[d][a], max[d][b]));
        a = p[d][a]; b = p[d][b];
    }
    domax(m, std::max(max[0][a], max[0][b]));
    return m;
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d%d%lld", &a[i], &b[i], &w[i]); a[i]--; b[i]--;
        v.push_back({w[i], i});
    }

    std::sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) r[i] = i;
    for (auto &x : v) {
        int i = x.second;
        if (find(a[i]) != find(b[i])) {
            join(a[i], b[i]);
            total += x.first;
            e[a[i]].push_back({b[i], w[i]});
            e[b[i]].push_back({a[i], w[i]});
        }
    }
    p[0][0] = 0;
    max[0][0] = -1e9;
    go(0);
    for (int d = 0; d+1 < MaxD; d++) {
        for (int i = 0; i < N; i++) {
            p[d+1][i] = p[d][p[d][i]];
            max[d+1][i] = std::max(max[d][i], max[d][p[d][i]]);
        }
    }
    
    for (int i = 0; i < N; i++) r[i] = i;
    for (auto &x : v) {
        int i = x.second;
        if (find(a[i]) != find(b[i])) {
            join(a[i], b[i]);
            ans[i] = total;
        } else {
            ans[i] = total - getMax(a[i], b[i]) + w[i];
        }
    }
    for (int i = 0; i < M; i++) printf("%lld\n", ans[i]);
}