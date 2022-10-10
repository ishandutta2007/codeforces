#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll p, q, r, s;
        cin >> p >> q >> r >> s;
        ll m = abs(p - r) + 1;
        ll n = abs(q - s) + 1;
        cout << (m - 1)*(n - 1) + 1 << '\n';
    }
}