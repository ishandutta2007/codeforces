#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;

    int mn = max(n - a1 * (k1 - 1) - a2 * (k2 - 1), 0), mx = 0;
    if (k1 < k2) {
        mx += min(n / k1, a1);
        n -= mx * k1;
        mx += min(n / k2, a2);
    } else {
        mx += min(n / k2, a2);
        n -= mx * k2;
        mx += min(n / k1, a1);
    }

    cout << mn << " " << mx << "\n";

    return 0;
}