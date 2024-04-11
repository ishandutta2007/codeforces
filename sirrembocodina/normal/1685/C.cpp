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
        int n;
        cin >> n;
        n *= 2;
        string s;
        cin >> s;
        vector<int> h(n + 1);
        for (int i = 0; i < n; i++) {
            h[i + 1] = h[i] + (s[i] == '(' ? 1 : -1);
        }
        bool was = false;
        for (int i = 1; i < n; i++) {
            if (h[i] < 0) {
                was = true;
            }
        }
        if (!was) {
            cout << "0\n";
            continue;
        }
        int l = n, r = 0;
        for (int i = 1; i < n; i++) {
            if (h[i] < 0) {
                l = min(l, i);
                r = max(r, i);
            }
        }
        int a = 0;
        for (int i = 0; i < l; i++) {
            if (h[a] < h[i]) {
                a = i;
            }
        }
        int b = n;
        for (int i = r + 1; i <= n; i++) {
            if (h[b] < h[i]) {
                b = i;
            }
        }
        int mx = l;
        for (int i = l; i <= r; i++) {
            if (h[mx] < h[i]) {
                mx = i;
            }
        }
        if (h[a] + h[b] >= h[mx]) {
            cout << "1\n" << a + 1 << ' ' << b << '\n';
            continue;
        }
        cout << "2\n1 " << mx << '\n' << mx + 1 << ' ' << n << '\n';
    }
}