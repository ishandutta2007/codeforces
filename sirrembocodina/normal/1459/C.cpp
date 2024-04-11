#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int d = 0;
    for (int i = 1; i < n; i++) {
        d = __gcd(d, a[i] - a[0]);
    }
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        cout << __gcd(a[0] + b, d) << " ";
    }
}