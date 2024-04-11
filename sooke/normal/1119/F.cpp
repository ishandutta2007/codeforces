#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

const int N = 250005;

bool vis[N];
int n, tms, deg[N];
long long ans, f[2][N];
std::vector<int> s[N], t[N];
std::set<std::pair<int, int>> e[N];

struct Heap {
    std::priority_queue<long long> a, b; long long tmp, sum;
    
    inline void update() { while (!a.empty() && !b.empty() && a.top() == b.top()) { a.pop(); b.pop(); } }
    inline void push(long long x) { sum += x; a.push(x); update(); }
    inline void pop(long long x) { sum -= x; b.push(x); update(); }
    inline long long pop() { tmp = a.top(); sum -= tmp; a.pop(); update(); return tmp; }
    inline int size() { return a.size() - b.size(); }
} hp[N];

void dfs(int u, int fa) {
    long long m = deg[u]--, sum = 0; std::vector<long long> a, b; vis[u] = true;
    for (m = std::max(m, 0ll); hp[u].size() > m; ) { hp[u].pop(); }
    for (auto i : e[u]) {
        int v = i.first, w = i.second;
        if (v != fa) {
            if (!vis[v]) { dfs(v, u); f[1][v] += w; }
            if (f[0][v] < f[1][v]) {
                sum += f[0][v]; hp[u].push(f[1][v] - f[0][v]);
                b.push_back(f[1][v] - f[0][v]);
            } else { sum += f[1][v]; m--; }
        }
    }
    for (m = std::max(m, 0ll); hp[u].size() > m; ) { a.push_back(hp[u].pop()); } f[0][u] = sum + hp[u].sum;
    for (m = std::max(m - 1, 0ll); hp[u].size() > m; ) { a.push_back(hp[u].pop()); } f[1][u] = sum + hp[u].sum;
    for (; !a.empty(); a.pop_back()) { hp[u].push(a.back()); }
    for (; !b.empty(); b.pop_back()) { hp[u].pop(b.back()); }
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        deg[u]++; deg[v]++; e[u].insert({v, w}); e[v].insert({u, w});
    }
    for (int i = 1; i <= n; i++) {
        s[deg[i]].push_back(i);
        for (int j = 0; j < deg[i]; j++) { t[j].push_back(i); }
    }
    for (int i = 0; i < n; i++) {
        for (auto u : s[i]) {
            for (auto j : e[u]) {
                int v = j.first, w = j.second;
                e[v].erase({u, w}); hp[v].push(w);
            }
        }
        for (auto u : t[i]) { vis[u] = false; }
        for (auto u : t[i]) {
            if (!vis[u]) { dfs(u, 0); ans += f[0][u]; }
        }
        printf("%I64d ", ans); ans = 0;
    }
    return 0;
} //