#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

vector<int> g[200100];
vector<int> rg[200100];

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    forn (i, m) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
        rg[y].push_back(x);
    }
    int k;
    cin >> k;
    vector<int> p(k);
    forn (i, k) {
        cin >> p[i];
        p[i]--;
    }
    vector<int> d(n, 2e9);
    vector<bool> used(n, false);
    queue<int> q;
    q.push(p.back());
    d[p.back()] = 0;
    used[p.back()] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to: rg[v]) {
            if (!used[to]) {
                q.push(to);
                d[to] = d[v] + 1;
                used[to] = true;
            }
        }
    }
    int mn = 0, mx = 0;
    for (int i = 0; i < k - 1; ++i) {
        int v = p[i];
        int to = p[i + 1];
        if (d[v] != d[to] + 1) {
            mn++;
            mx++;
            continue;
        }
        int cnt = 0;
        for (int to2: g[v]) {
            if (d[v] == d[to2] + 1) {
                cnt++;
            }
        }
        if (cnt > 1) {
            mx++;
        }
    }
    cout << mn << " " << mx << endl;
}