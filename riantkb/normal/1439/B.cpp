#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int M = 1000000007;
const long long LM = 1LL << 60;


vector<int> solve(const vector<vector<int>>& edge, int k) {
    int n = edge.size();
    queue<int> q;
    vector<int> deg(n);
    vector<bool> del(n);
    for (int i = 0; i < n; ++i) {
        deg[i] = edge[i].size();
        if (deg[i] < k) {
            del[i] = true;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (auto& i : edge[p]) {
            if (del[i]) continue;
            --deg[i];
            if (deg[i] < k) {
                del[i] = true;
                q.push(i);
            }
        }
    }
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (!del[i]) {
            res.push_back(i);
        }
    }
    return res;
}

vector<int> solve2(const vector<vector<int>>& edge, int k) {
    int n = edge.size();
    queue<int> q;
    vector<int> deg(n);
    vector<bool> del(n);
    for (int i = 0; i < n; ++i) {
        deg[i] = edge[i].size();
        if (deg[i] < k - 1) {
            del[i] = true;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (auto& i : edge[p]) {
            if (del[i]) continue;
            --deg[i];
            if (deg[i] < k - 1) {
                del[i] = true;
                q.push(i);
            }
        }
    }
    // bool exi = false;
    // for (int i = 0; i < n; ++i) {
    //     if (!del[i]) {
    //         exi = true;
    //     }
    // }
    // if (!exi) {
    //     return {};
    // }

    vector<bool> pushed(n);
    for (int i = 0; i < n; ++i) {
        if (!del[i] && deg[i] == k - 1) {
            pushed[i] = true;
            q.push(i);
        }
    }
    vector<unordered_set<int>> edgeset(n);
    for (int i = 0; i < n; ++i) {
        for (auto& e : edge[i]) {
            edgeset[i].insert(e);
        }
    }

    while (!q.empty()) {
        int p = q.front();
        q.pop();
        if (deg[p] == k - 1) {
            vector<int> v;
            v.push_back(p);
            for (auto& i : edge[p]) {
                if (!del[i]) {
                    v.push_back(i);
                }
            }
            // assert((int)v.size() == k);
            bool ok = true;
            for (int i = 0; i < k && ok; ++i) {
                for (int j = i + 1; j < k; ++j) {
                    if (!edgeset[v[i]].count(v[j])) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                return v;
            }
        }
        for (auto& i : edge[p]) {
            if (del[i]) continue;
            --deg[i];
            if (deg[i] == k - 1 && !pushed[i]) {
                pushed[i] = true;
                q.push(i);
            }
        }
        del[p] = true;
    }
    return {};
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> edge(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        {
            vector<int> s0 = solve(edge, k);
            if (s0.size() > 0) {
                cout << 1 << ' ' << s0.size() << '\n';
                for (int i = 0; i < (int)s0.size(); ++i) {
                    cout << s0[i] + 1 << (i + 1 < (int)s0.size() ? ' ' : '\n');
                }
                continue;
            }
        }
        {
            vector<int> s1 = solve2(edge, k);
            if (s1.size() > 0) {
                cout << 2 << '\n';
                for (int i = 0; i < (int)s1.size(); ++i) {
                    cout << s1[i] + 1 << (i + 1 < (int)s1.size() ? ' ' : '\n');
                }
                continue;
            }
        }
        cout << -1 << '\n';
    }
    return 0;
}