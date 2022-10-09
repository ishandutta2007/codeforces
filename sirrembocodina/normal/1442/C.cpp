#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int mod = 998244353;

vector<vector<pair<int, int>>> g;

struct vertex {
    int steps;
    int inv;
    int ind;
    bool operator<(const vertex& b) const {
        if (inv == b.inv) {
            return steps > b.steps;
        }
        if (inv > 30 || b.inv > 30) {
            return inv > b.inv;
        }
        return steps + (1ll << inv) > b.steps + (1ll << b.inv);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    g.resize(2 * n);
    forn (i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back({b, 0});
        g[b + n].push_back({a + n, 0});
    }
    forn (a, n) {
        g[a].push_back({a + n, 1});
        g[a + n].push_back({a, 1});
    }
    vector<int> d(2 * n, 2e18);
    deque<int> q;
    vector<bool> used(2 * n);
    d[0] = 0;
    q.push_back(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        if (used[v]) {
            continue;
        }
        used[v] = true;
        for (auto tolen: g[v]) {
            int to = tolen.first, len = tolen.second;
            if (d[to] <= d[v] + len) {
                continue;
            }
            d[to] = d[v] + len;
            if (len) {
                q.push_back(to);
            } else {
                q.push_front(to);
            }
        }
    }
    forn (i, 2 * n) {
        g[i].pop_back();
        //cerr << d[i] << " ";
    }
    //cerr << endl;
    vector<vector<vertex>> dv(2 * n);
    forn (i, 2 * n) {
        dv[i].resize(max(1ll, 20ll));
        forn (j, dv[i].size()) {
            dv[i][j].ind = i;
            dv[i][j].inv = 1e9;
        }
    }
    priority_queue<vertex> pq;
    dv[0][0].inv = dv[0][0].steps = 0;
    pq.push(dv[0][0]);
    while (!pq.empty()) {
        vertex v = pq.top();
        //cerr << v.ind << " " << v.inv << " " << v.steps << endl;
        if (v.ind == n - 1 || v.ind == 2 * n - 1) {
            int ans = 1;
            forn (i, v.inv) {
                ans *= 2;
                ans %= mod;
            }
            ans += mod - 1;
            ans += v.steps;
            ans %= mod;
            cout << ans << endl;
            return 0;
        }
        pq.pop();
        if (v < dv[v.ind][v.inv - d[v.ind]]) {
            continue;
        }
        for (auto tolen: g[v.ind]) {
            int to = tolen.first;
            vertex new_to = v;
            new_to.ind = to;
            new_to.steps++;
            if (v.inv - d[new_to.ind] >= dv[to].size()) {
                continue;
            }
            if (dv[to][v.inv - d[new_to.ind]] < new_to) {
                dv[to][v.inv - d[new_to.ind]] = new_to;
                pq.push(new_to);
            }
        }
        v.inv++;
        v.ind = v.ind < n ? v.ind + n : v.ind - n;
        if (v.inv - d[v.ind] >= dv[v.ind].size()) {
            continue;
        }
        if (dv[v.ind][v.inv - d[v.ind]] < v) {
            dv[v.ind][v.inv - d[v.ind]] = v;
            pq.push(v);
        }
    }
}