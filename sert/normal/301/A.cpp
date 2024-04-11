#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 34;

int n, a[N], mn = 1e9, sum, less0, x;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n * 2 - 1; i++) {
        cin >> x;
        if (abs(x) < mn)
            mn = abs(x);
        sum += abs(x);
        if (x < 0)
            less0++;
    }
    // cout << sum << " " << mn << "\n";
    if (less0 % 2 && n % 2 == 0)
        sum -= mn * 2;
    cout << sum;
    return 0;
}