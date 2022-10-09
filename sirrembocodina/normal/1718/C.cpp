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
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int N = n;
        vector<int> p;
        for (int i = 2; i * i <= N; i++) {
            if (N % i) {
                continue;
            }
            p.push_back(i);
            while (N % i == 0) {
                N /= i;
            }
        }
        if (N > 1) {
            p.push_back(N);
        }
        multiset<int> cand;
        vector<vector<int>> b(p.size());
        for (int i = 0; i < p.size(); i++) {
            b[i].resize(n / p[i]);
            for (int j = 0; j < n / p[i]; j++) {
                for (int k = 0; k < p[i]; k++) {
                    b[i][j] += a[j + k * (n / p[i])] * (n / p[i]);
                }
                cand.insert(b[i][j]);
            }
        }
        cout << *--cand.end() << '\n';
        while (q--) {
            int j, x;
            cin >> j >> x;
            j--;
            for (int i = 0; i < p.size(); i++) {
                int& cur = b[i][j % (n / p[i])];
                cand.erase(cand.find(cur));
                cur += (x - a[j]) * (n / p[i]);
                cand.insert(cur);
            }
            a[j] = x;
            cout << *--cand.end() << '\n';
        }
    }
}