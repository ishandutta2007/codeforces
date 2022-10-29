#include <bits/stdc++.h>

using namespace std;

int
main()
{
    ios_base::sync_with_stdio(false);
    int t, n;
    vector<int> a;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool found = false;
        int i = 1;
        while (i < n && abs(a[i] - a[i - 1]) <= 1) {
            ++i;
        }
        if (i == n) {
            cout << "NO\n";
        } else {
            cout << "YES\n" << i << ' ' << i + 1 << '\n';
        }
    }
    return 0;
}