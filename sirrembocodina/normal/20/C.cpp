#include <bits/stdc++.h>

#define int int64_t

using namespace std;

vector<vector<pair<int, int>>> g;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    int st = 0;
    vector<int> d(n, 2e18);
    vector<int> p(n, -2);
    p[st] = -1;
    d[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({d[st], st});
    vector<bool> handled(n);
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        if (handled[v]) {
            continue;
        }
        handled[v] = true;
        for (auto e: g[v]) {
            int to = e.first, len = e.second;
            if (d[to] > d[v] + len) {
                d[to] = d[v] + len;
                p[to] = v;
                pq.push({d[to], to});
            }
        }
    }
    int cur = n - 1;
    if (p[cur] == -2) {
        cout << -1;
        return 0;
    }
    vector<int> ans;
    while (cur != -1) {
        ans.push_back(cur);
        cur = p[cur];
    }
    reverse(ans.begin(), ans.end());
    for (int v: ans) {
        cout << v + 1 << ' ';
    }
}