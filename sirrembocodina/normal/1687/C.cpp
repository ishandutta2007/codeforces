#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

struct my_hash {
    inline size_t operator()(const pair<int, int>& a) const {
        return a.first * 31 + a.second;
    }
};

int32_t main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i + 1];
        }
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[i + 1] -= x;
        }
        for (int i = 0; i < n; i++) {
            a[i + 1] += a[i];
        }
        n++;
        set<int> s;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) {
                s.insert(i);
            }
        }
        vector<vector<int>> l(n), r(n);
        vector<int> L(m), R(m);
        queue<int> q;
        for (int i = 0; i < m; i++) {
            cin >> L[i] >> R[i];
            L[i]--;
            l[L[i]].push_back(i);
            r[R[i]].push_back(i);
            if (a[L[i]] == 0 && a[R[i]] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            vector<int> del;
            for (auto it = s.lower_bound(L[i]); it != s.end() && *it < R[i]; it++) {
                del.push_back(*it);
            }
            for (int x: del) {
                s.erase(x);
                a[x] = 0;
                for (int i: l[x]) {
                    if (a[L[i]] == 0 && a[R[i]] == 0) {
                        q.push(i);
                    }
                }
                for (int i: r[x]) {
                    if (a[L[i]] == 0 && a[R[i]] == 0) {
                        q.push(i);
                    }
                }
            }
        }
        cout << (s.size() ? "NO\n" : "YES\n");
    }
}