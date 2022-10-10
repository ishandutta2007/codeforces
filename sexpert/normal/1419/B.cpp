#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll x, y;
        cin >> x;
        y = 1;
        int ans = 0;
        for(ll n = 1; n <= 30; n++) {
            if((1LL << (2*n - 1)) - (1LL << (n - 1)) <= x) {
                x -= ((1LL << (2*n - 1)) - (1LL << (n - 1)));
                ans++;
            }
        }
        cout << ans << '\n';
    }
}