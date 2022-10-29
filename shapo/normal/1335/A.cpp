#include <bits/stdc++.h>

using namespace std;

int
main()
{
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n;
        cin >> n;
        int l = 1, r = (n - 1) / 2;
        if (r >= l) {
            cout << (r - l + 1) << '\n';
        } else {
            cout << 0 << '\n';
        }
        // Another way
        // cout << max(0, r - l + 1) << '\n';
    }
    return 0;
}