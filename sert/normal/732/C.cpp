#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
const int N = (int)1e6 + 34;
ll n, k, ans;

ll go(ll a, ll b, ll c) {
    if (a < 0 || b < 0 || c < 0)
        return (ll)4e18;
    ll mx = max(a, max(b, c));
    return mx * 3 - a - b - c;
}

int main() {
    init();

    ll a, b, c;
    cin >> a >> b >> c;
    ans = ll(4e18) + 2;
    ans = min(ans, go(a - 1, b, c));
    ans = min(ans, go(a, b - 1, c));
    ans = min(ans, go(a, b, c - 1));
    ans = min(ans, go(a - 1, b - 1, c));
    ans = min(ans, go(a - 1, b, c - 1));
    ans = min(ans, go(a, b - 1, c - 1));
    ans = min(ans, go(a, b, c));

    cout << ans;

    return 0;
}