#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n + 2);
        int k = 0;
        for (int i = 1; i <= n; i++) {
            int b;
            cin >> b;
            k = max(k, min(b, i));
            g[b].push_back(i);
        }
        queue<int> q;
        q.push(0);
        q.push(n + 1);
        vector<int> ans;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (0 < v && v < n + 1) {
                ans.push_back(v);
            }
            for (int to: g[v]) {
                if (g[to].empty()) {
                    q.push(to);
                }
            }
            for (int to: g[v]) {
                if (!g[to].empty()) {
                    q.push(to);
                }
            }
        }
        cout << k << '\n';
        for (int x: ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}