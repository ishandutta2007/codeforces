#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int sum = 0;
    vector<int> a;
    for (int i = 1; i <= n; ++i) {
        sum += (i - 1) / 2;
        if (sum < m) {
            a.push_back(i);
            continue;
        }
        a.push_back(i + (sum - m) * 2);
        break;
    }
    if (sum < m) {
        cout << -1 << endl;
        return 0;
    }
    int cur = 0;
    while (a.size() < n) {
        a.push_back(100000000 + cur);
        cur += 11000;
    }
    forn (i, n) {
        cout << a[i] << " ";
    }
    cout << endl;
}