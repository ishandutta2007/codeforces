#include <bits/stdc++.h>
#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "0\n";
            continue;
        }
        if (a < b && (b - a) % 2 == 1 ||
            a > b && (a - b) % 2 == 0) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
}