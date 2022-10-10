#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll p, a, b, c;
        cin >> p >> a >> b >> c;
        auto f = [](ll x, ll y) {
            if(x % y == 0)
                return 0LL;
            return y - (x % y);
        };
        cout << min({f(p, a), f(p, b), f(p, c)}) << '\n';
    }
}