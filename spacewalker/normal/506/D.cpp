#include <bits/stdc++.h>

using namespace std;
constexpr int BIG_NUMBER = 300;

struct onion {
    int n;
    vector<int> par;
    onion(int n) : n(n), par(n, -1) {}
    int find(int i) {
        return (par[i] < 0 ? i : par[i] = find(par[i]));;
    }
    void join(int i, int j) {
        i = find(i), j = find(j);
        if (i == j) return;
        if (par[i] > par[j]) swap(i, j);
        par[i] += par[j]; par[j] = i;
    }
};

int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<vector<pair<int, int>>> colors(m);
    for (int i = 0; i < m; ++i) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        --a; --b; --c;
        colors[c].emplace_back(a, b);
    }
    map<pair<int, int>, int> special;
    auto addPair = [&] (int x, int y) {
        if (x < y) swap(x, y);
//        printf("adding pair %d %d\n", x, y);
        special[make_pair(x, y)]++;
    };
    auto getCount = [&] (int x, int y) {
        if (x < y) swap(x, y);
        return special[make_pair(x, y)];
    };

    for (int i = 0; i < m; ++i) {
        if (colors[i].size() > BIG_NUMBER || colors[i].size() == 0) continue;
        vector<int> ivs;
        for (auto [a, b] : colors[i]) {
            ivs.push_back(a); ivs.push_back(b);
        }
        sort(begin(ivs), end(ivs));
        ivs.erase(unique(begin(ivs), end(ivs)), end(ivs));
        auto cmpv = [&] (int v) {
            return distance(begin(ivs), lower_bound(begin(ivs), end(ivs), v));
        };
        vector<bool> vis(ivs.size());
        vector<vector<int>> sgraph(ivs.size());
        for (auto [a, b] : colors[i]) {
            sgraph[cmpv(a)].push_back(cmpv(b));
            sgraph[cmpv(b)].push_back(cmpv(a));
        }
        for (int j = 0; j < ivs.size(); ++j) {
            if (vis[j]) continue;
//            printf("search j %d i %d\n", j, i);
            vector<int> thiscomp;
            queue<int> q; q.push(j); vis[j] = true;
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                thiscomp.push_back(cur);
                for (int nxt : sgraph[cur]) if (!vis[nxt]) {
                    vis[nxt] = true;
                    q.push(nxt);
                }
            }
            for (int x : thiscomp) for (int y : thiscomp) if (x > y) addPair(ivs[x], ivs[y]);
        }
    }
    vector<onion> bigColors;
    for (int i = 0; i < m; ++i) {
        if (colors[i].size() <= BIG_NUMBER) continue;
        bigColors.emplace_back(n);
        for (auto [a, b] : colors[i]) bigColors.back().join(a, b);
    }
    int q; scanf("%d", &q);
    while (q--) {
        int u, v; scanf("%d %d", &u, &v); --u; --v;
        int ans = getCount(u, v);
        for (onion &o : bigColors) if (o.find(u) == o.find(v)) ++ans;
        printf("%d\n", ans);
    }
    return 0;
}