#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int q = 0; q < t; q++) {
        int n;
        cin >> n;
        int sum = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
            mx = max(mx, x);
        }
        if (sum < 2 * mx || sum % 2) {
            cout << "T" << endl;
        } else {
            cout << "HL" << endl;
        }
    }
    return 0;
}