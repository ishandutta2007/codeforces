#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define ld long double
using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> X(n);
        for (int i = 0; i < n; i++) {
            cin >> X[i];
        }
        sort(all(X));
        int g = 0;
        for (int i = 0; i < n - 1; i++) {
            g = gcd(g, X[i + 1] - X[i]);
        }
        if (k < 0) {
            k = g - abs(k) % g;
        }
        if (X[0] < 0) {
            X[0] = g - abs(X[0]) % g;
        }
        if (k % g == X[0] % g) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}