#include "bits/stdc++.h"

#define int long long

#define sqr(x) ((x) * (x))

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
        while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        bool eq = true;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] != a[0]) {
                eq = false;
            }
        }
        if (eq) {
            cout << n << endl;
        } else {
            cout << 1 << endl;
        }
    }
}