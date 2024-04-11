#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        if (n <= 2) {
            cout << 1;
        } else {
            n -= 3;
            cout << 2 + (n / x);
        }
        cout << '\n';
    }

}