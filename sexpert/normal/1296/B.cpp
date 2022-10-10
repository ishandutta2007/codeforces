#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll s;
        cin >> s;
        ll ans = 0;
        while(s > 0) {
            if(s < 10) {
                ans += s;
                break;
            }
            ll x = s / 10;
            s %= 10;
            s += x;
            ans += 10*x;
        }
        cout << ans << '\n';
    }
}