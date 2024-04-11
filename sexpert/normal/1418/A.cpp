#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll x, y, k;
        cin >> x >> y >> k;
        cout << k + ((y * k + k - 1) + x - 2)/(x - 1) << '\n';
    }
}