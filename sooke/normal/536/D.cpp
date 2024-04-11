#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 2e3 + 5;

int n, m, s, t, ns, nt, a[N], cnt[N][N];
long long diss[N], dist[N], sum[N][N], f[2][N][N], fs[N], ft[N], ps[N], pt[N];
std::vector<std::pair<int, int>> e[N];

void dijkstra(int s, long long dis[]) {
    std::priority_queue<std::pair<long long, int>> que;
    memset(dis, 60, (n + 1) * 8); dis[s] = 0;
    for (que.push({0, s}); !que.empty(); ) {
        int u = que.top().second;
        long long d = -que.top().first;
        que.pop();
        if (d != dis[u]) { continue; }
        for (auto i : e[u]) {
            int v = i.first, w = i.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                que.push({-dis[v], v});
            }
        }
    }
}

int discrete(long long ar[]) {
    std::vector<long long> tb;
    for (int i = 1; i <= n; i++) {
        tb.push_back(ar[i]);
    }
    std::sort(tb.begin(), tb.end());
    tb.resize(std::unique(tb.begin(), tb.end()) - tb.begin());
    for (int i = 1; i <= n; i++) {
        ar[i] = std::lower_bound(tb.begin(), tb.end(), ar[i]) - tb.begin();
    }
    return tb.size();
}

int main() {
    n = read(); m = read(); s = read(); t = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    for (int i = 0; i < m; i++) {
        int u = read(), v = read(), w = read();
        e[u].push_back({v, w}); e[v].push_back({u, w});
    }
    dijkstra(s, diss); dijkstra(t, dist);
    ns = discrete(diss); nt = discrete(dist);
    for (int i = 1; i <= n; i++) {
        cnt[diss[i]][dist[i]] += 1;
        sum[diss[i]][dist[i]] += a[i];
    }
    for (int i = ns; i >= 0; i--) {
        for (int j = nt; j >= 0; j--) {
            cnt[i][j] += cnt[i][j + 1] + cnt[i + 1][j] - cnt[i + 1][j + 1];
            sum[i][j] += sum[i][j + 1] + sum[i + 1][j] - sum[i + 1][j + 1];
        }
    }
    for (int i = nt; i >= 0; i--) { ps[i] = ns; }
    for (int i = ns; i >= 0; i--) { pt[i] = nt; }
    for (int i = ns; i >= 0; i--) {
        for (int j = nt; j >= 0; j--) {
            if (cnt[i][j] == 0) { continue; }
            for (; cnt[ps[j]][j] < cnt[i][j]; ps[j]--) {
                fs[j] = std::min(fs[j], f[1][ps[j]][j]);
            }
            for (; cnt[i][pt[i]] < cnt[i][j]; pt[i]--) {
                ft[i] = std::min(ft[i], f[0][i][pt[i]]);
            }
            f[0][i][j] = sum[i][j] - fs[j];
            f[1][i][j] = sum[i][j] - ft[i];
        }
    }
    if (f[0][0][0] * 2 < sum[0][0]) { printf("Cry\n"); return 0; }
    if (f[0][0][0] * 2 > sum[0][0]) { printf("Break a heart\n"); return 0; }
    printf("Flowers\n");
    return 0;
}