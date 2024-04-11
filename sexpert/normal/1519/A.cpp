#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll r, b, d;
        cin >> r >> b >> d;
        cout << ((r <= (d + 1) * b && b <= (d + 1) * r) ? "YES" : "NO") << '\n';
    }
}