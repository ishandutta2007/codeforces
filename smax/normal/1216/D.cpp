#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, mx = 0, a[200000];
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int gcd = 0;
    long long total = 0;
    for (int i=0; i<n; i++) {
        gcd = __gcd(gcd, mx - a[i]);
        total += mx - a[i];
    }

    cout << total / gcd << " " << gcd << "\n";

    return 0;
}