#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = a[i] - b[i];
    }

    sort(c.begin(), c.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int min_j = upper_bound(c.begin(), c.end(), -c[i]) - c.begin();
        int first_good = max(i + 1, min_j);
        ans += n - first_good;
    }
    cout << ans << endl;
}


// -2 -1 0 3 5