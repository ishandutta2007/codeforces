#include <bits/stdc++.h>
#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << (n / 2 + 1) * (n / 2 + 1) << endl;
    } else {
        cout << 2 * (n / 2 + 2) * (n / 2 + 1) << endl;
    }
}