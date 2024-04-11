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
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        vector<int> c(n);
        int cur = 0;
        while (true) {
            int v = -1;
            for (int i = 0; i < n; i++) {
                if (c[i]) {
                    continue;
                }
                if (v == -1 || d[i] > d[v]) {
                    v = i;
                }
            }
            if (v == -1) {
                break;
            }
            cur++;
            c[v] = cur;
            for (int j = 0; j < d[v] - 1; j++) {
                cout << "? " << v + 1 << endl;
                int to;
                cin >> to;
                to--;
                if (c[to]) {
                    for (int i = 0; i < n; i++) {
                        if (c[i] == cur) {
                            c[i] = c[to];
                        }
                    }
                    break;
                }
                c[to] = cur;
            }
        }
        cout << "! ";
        for (int i = 0; i < n; i++) {
            cout << c[i];
            if (i + 1 < n) {
                cout << ' ';
            }
        }
        cout << endl;
    }
}