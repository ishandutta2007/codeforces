#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    while (l != r) {
        ans = ans * 2 + 1;
        l /= 2;
        r /= 2;
    }
    cout << ans;

    return 0;
}