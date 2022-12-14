#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 300010;

int n, m, hei[MaxN];
vector <int> g[MaxN];
vector <pair <int, int> > cost[MaxN];
map <int, long long> dp[MaxN];
long long add[MaxN];

inline void Update(int v, int d, long long val) {
    map <int, long long> :: iterator it = dp[v].upper_bound(d);
    if (!dp[v].empty() && it != dp[v].begin()) {
        --it;
        if (it->second <= val) {
            return;
        }
    }
    dp[v][d] = val;
    for (bool ok = true; ok; ) {
        ok = false;
        map <int, long long> :: iterator it = dp[v].upper_bound(d);
        if (it != dp[v].end() && it->second >= val) {
            dp[v].erase(it);
            ok = true;
        }
    }
}

long long dfs(int v, int p) {
    long long total = 0;
    for (int i = 0; i < (int)g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p) {
            continue;
        }
        hei[to] = hei[v] + 1;
        dfs(to, v);
        if (dp[to].empty()) {
            printf("-1\n");
            exit(0);
        }
        total += dp[to].rbegin()->second + add[to];
    }
    add[v] = 0;
    for (int i = 0; i < (int)g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p) {
            continue;
        }
        add[to] += total - (dp[to].rbegin()->second + add[to]);
        if (dp[to].size() > dp[v].size()) {
            dp[v].swap(dp[to]);
            swap(add[v], add[to]);
        }
        for (map <int, long long> :: iterator it = dp[to].begin(); it != dp[to].end(); ++it) {
            Update(v, it->first, it->second + add[to] - add[v]);
        }
    }
    for (int i = 0; i < (int)cost[v].size(); ++i) {
        int u = cost[v][i].first, c = cost[v][i].second;
        Update(v, hei[u], total + c - add[v]);
    }
    dp[v].erase(hei[v]);
    return total;
}

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        if (u != v) {
            cost[u].push_back(make_pair(v, c));
        }
    }
    cout << dfs(1, 0) << '\n';
    return 0;
}