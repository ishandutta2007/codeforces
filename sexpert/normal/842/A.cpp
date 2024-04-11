#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    ll owo = (l + k - 1)/k;
    for(ll b = x; b <= y; b++) {
        if(b * k >= l && b * k <= r) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}