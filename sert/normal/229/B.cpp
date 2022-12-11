#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int INF = (int)1.1e9 + 41;

int findNextFree(int tme, const vector<pair<int, int>> &f) {
    return max(tme, lower_bound(f.begin(), f.end(), make_pair(tme, -INF))->second);    
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> es(n);
    for (int i = 0; i < m; i++) {
        int v1, v2, c;
        cin >> v1 >> v2 >> c;
        v1--;
        v2--;
        es[v1].emplace_back(v2, c);
        es[v2].emplace_back(v1, c);
    }

    vector<vector<int>> t(n);
    vector<vector<pair<int, int>>> f(n);

    for (int i = 0; i < n; i++) {
        int sz;
        cin >> sz;
        t[i].resize(sz);
        for (int j = 0; j < sz; j++) {
            cin >> t[i][j];
        }

        if (sz == 0) {
            f[i] = {{INF, -INF}};
            continue;
        }

        f[i].emplace_back(t[i][0] - 1, -INF);
        for (int j = 1; j < sz; j++) {
            if (t[i][j] - 1 > t[i][j - 1])
                f[i].emplace_back(t[i][j] - 1, t[i][j - 1] + 1);
        }
        f[i].emplace_back(INF, t[i].back() + 1);
    }

    vector<int> d(n, INF);
    d[0] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    vector<bool> u(n, false);

    while (!q.empty()) {
        int v = q.top().second;
        q.pop();
        if (u[v]) continue;
        u[v] = true;

        int tme = findNextFree(d[v], f[v]);
        for (const auto &[w, e] : es[v]) {            
            if (tme + e < d[w]) {
                d[w] = tme + e;
                q.push(make_pair(-d[w], w));
            }
        }
    }

    cout << (d[n - 1] == INF ? -1 : d[n - 1]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 2;
    for (int i = 1; i < T; i++) solve();    
#endif
}