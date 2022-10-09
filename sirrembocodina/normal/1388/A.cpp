#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n <= 30) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        if (n - 30 == 6) {
            cout << "6 10 15 5" << endl;
        } else if (n - 30 == 10) {
            cout << "6 10 15 9" << endl;
        } else if (n - 30 == 14) {
            cout << "6 10 15 13" << endl;
        } else {
            cout << "6 10 14 " << n - 30 << endl;
        }
    }
}