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

bool ok(vector<int>& a, int m) {
    int sum = 0;
    bool all2 = true;
    for (int x: a) {
        sum += x;
        if (x > 2) {
            all2 = false;
        }
    }
    if (sum < m || (all2 && m % 2 == 1)) {
        return false;
    }
    return true;
}

int32_t main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a, b;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            if (x / n >= 2) {
                a.push_back(x / n);
            }
            if (x / m >= 2) {
                b.push_back(x / m);
            }
        }
        if (ok(a, m) || ok(b, n)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}