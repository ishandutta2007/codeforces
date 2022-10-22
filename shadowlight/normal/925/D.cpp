#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, m;
    cin >> n >> m;
    vector <vector <int> > gr(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    vector <int> d(n, INF), pred(n, -1);
    d[0] = 0;
    queue <int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : gr[v]) {
            if (d[u] == INF) {
                d[u] = d[v] + 1;
                pred[u] = v;
                q.push(u);
                continue;
            }
        }
    }
    vector <int> res;
    if (d[n - 1] != INF) {
        int now = n - 1;
        while (now) {
            res.push_back(now);
            now = pred[now];
        }
        res.push_back(0);
    }
    int len = (int) res.size() - 1;
    if (!res.size()) {
        len = INF;
    }
    if (len > 4) {
        for (int i = 0; i < n; i++) {
            if (d[i] == 2) {
                res.clear();
                res.push_back(n - 1);
                res.push_back(0);
                res.push_back(i);
                res.push_back(pred[i]);
                res.push_back(0);
                len = 4;
                break;
            }
        }
    }
    if (len > 5) {
        vector <bool> used(n, false);
        vector <bool> good(n, false);
        for (int v : gr[0]) {
            if (used[v]) continue;
            good[v] = 1;
            used[v] = 1;
            for (int u : gr[v]) {
                if (!u) continue;
                good[u] = 1;
                used[u] = 1;
            }
            for (int u : gr[v]) {
                if (!u) continue;
                for (int x : gr[u]) {
                    if (!x) continue;
                    if (!good[x]) {
                        res.clear();
                        res.push_back(n - 1);
                        res.push_back(v);
                        res.push_back(x);
                        res.push_back(u);
                        res.push_back(v);
                        res.push_back(0);
                        len = 5;
                        break;
                    }
                }
                if (len == 5) {
                    break;
                }
                if (gr[u].size() == gr[v].size()) {
                    continue;
                }
                good[u] = false;
                for (int x : gr[u]) {
                    good[x] = false;
                }
                for (int x = 0; x < n; x++) {
                    if (!x) continue;
                    if (good[x]) {
                        res.clear();
                        res.push_back(n - 1);
                        res.push_back(x);
                        res.push_back(u);
                        res.push_back(v);
                        res.push_back(x);
                        res.push_back(0);
                        len = 5;
                        break;
                    }
                }
                if (len == 5) {
                    break;
                }
                good[u] = true;
                for (int x : gr[u]) {
                    if (!x) continue;
                    good[x] = true;
                }
            }
            good[v] = 0;
            for (int u : gr[v]) {
                good[u] = 0;
            }
        }
    }
    if (len == INF) {
        cout << -1;
        return 0;
    }
    cout << len << "\n";
    reverse(res.begin(), res.end());
    for (int x : res) {
        cout << x + 1 << " ";
    }
}