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

vector<bool> used;
vector<int> p;

bool dfs(int v) {
    used[v] = true;
    if (used[p[v]]) {
        return true;
    }
    return !dfs(p[v]);
}

int32_t main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn (i, n) {
            cin >> a[i];
            a[i]--;
        }
        vector<int> b(n);
        forn (i, n) {
            cin >> b[i];
            b[i]--;
        }
        used.assign(n, false);
        p.resize(n);
        forn (i, n) {
            p[a[i]] = b[i];
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                cnt += dfs(i);
            }
        }
        int x = (n - cnt) / 2;
        /*int ans = 0;
        forn (i, x) {
            ans += n - i - i - 1;
        }*/
        cout << 2 * (n - 1) * x - 2 * x * (x - 1) << '\n';
    }
}