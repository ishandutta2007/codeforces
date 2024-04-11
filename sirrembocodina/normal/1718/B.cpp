#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

bool check(vector<int>& cnt) {
    for (int j = 1; j < 44; j++) {
        if (cnt[j] > 1) {
            return false;
        }
    }
    for (int j = 1; j + 1 < 44; j++) {
        if (!cnt[j] && cnt[j + 1]) {
            return false;
        }
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    vector<int> f = {1, 1};
    while (true) {
        int x = f.back() + f[f.size() - 2];
        if (x > 1e9) {
            break;
        }
        f.push_back(x);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<bitset<44>> a(n);
        vector<bitset<44>> b(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            int y = x - 1;
            for (int j = f.size() - 1; j >= 0; j--) {
                if (x >= f[j]) {
                    x -= f[j];
                    a[i][j] = true;
                }
            }
            for (int j = f.size() - 1; j >= 0; j--) {
                if (y >= f[j]) {
                    y -= f[j];
                    b[i][j] = true;
                }
            }
        }
        bool ok = false;
        vector<int> cnt(44);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 44; j++) {
                cnt[j] += a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            if (b[i][1]) {
                continue;
            }
            for (int j = 0; j < 44; j++) {
                cnt[j] += b[i][j] - a[i][j];
            }
            if (check(cnt)) {
                ok = true;
            }
            for (int j = 0; j < 44; j++) {
                cnt[j] -= b[i][j] - a[i][j];
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}