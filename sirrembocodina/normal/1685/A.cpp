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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (n % 2) {
            cout << "NO\n";
            continue;
        }
        if (a[n / 2] != a[n / 2 - 1]) {
            cout << "YES\n";
            for (int i = 0; i < n / 2; i++) {
                cout << a[i] << ' ' << a[n / 2 + i] << ' ';
            }
            cout << '\n';
            continue;
        }
        int x = 0, y = 0;
        for (int i = 0; i < n / 2; i++) {
            x += a[i] == a[n / 2];
        }
        for (int i = n / 2; i < n; i++) {
            y += a[i] == a[n / 2];
        }
        if (x + y >= n / 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < n / 2; i++) {
                cout << a[i] << ' ' << a[n / 2 + i] << ' ';
            }
            cout << '\n';
        }
    }
}