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

//int mod = 998244353;

int32_t main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                b[i] += a[i][j] * j;
            }
        }
        int B = b[0] + b[1] + b[2] - min(b[0], min(b[1], b[2])) - max(b[0], max(b[1], b[2]));
        int k = -1;
        for (int i = 0; i < n; i++) {
            if (b[i] != B) {
                k = i;
                break;
            }
        }
        cout << k + 1 << ' ' << b[k] - B << '\n';
    }
}