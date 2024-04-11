#include<bits/stdc++.h>
//#define _GLIBCXX_DEBUG

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1e9 + 7;
const ld EPS = 1e-6;



void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<unordered_set<int>> g(n);
    for (int rq = 0; rq < m; rq++) {
        int u, v;
        cin >> u >> v;
        g[u - 1].insert(v - 1);
        g[v - 1].insert(u - 1);
    }
    if ((ll) k * (k - 1) > 2 * m) {
        cout << "-1\n";
        return;
    }
    queue<int> q, fast;
    for (int i = 0; i < n; i++) {
        if (g[i].size() < k - 1) fast.push(i);
        else if (g[i].size() == k - 1) q.push(i);
    }
    while (!q.empty() || !fast.empty()) {
        int v;
        if (!fast.empty()) {
            v = fast.front();
            fast.pop();
        } else {
            v = q.front();
            q.pop();
        }
        if (g[v].size() > k - 1)
            return;
        if (g[v].size() == k - 1) {
            bool was = false;
            for (auto i : g[v]) {
                for (auto j : g[v]) {
                    if (i == j)
                        break;
                    if (g[i].find(j) == g[i].end()) {
                        was = true;
                        break;
                    }
                }
            }
            if (!was) {
                cout << "2\n" << v + 1;
                for (auto i : g[v]) cout << ' ' << i + 1;
                cout << '\n';
                return;
            }
        }
        for (auto i : g[v]) {
            g[i].erase(v);
            if (g[i].size() == k - 1) q.push(i);
            else if (g[i].size() == k - 2) fast.push(i);
        }
        g[v].clear();
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!g[i].empty()) ans.push_back(i);
    }
    if (!ans.empty()) {
        cout << "1 " << ans.size() << '\n';
        for (auto i : ans) cout << i + 1 << ' ';
        cout << '\n';
    } else cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    for (int req = 0; req < t; ++req)
        solve();
}