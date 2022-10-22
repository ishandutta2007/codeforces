#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod = (int)1e9+7;

ll tentodigits(ll x) {
    ll ans = 1;
    while (x > 0) {
        ans *= 10;
        x /= 10;
    }
    return ans;
}

ll rev(ll x) {
    ll ans = 0;
    while (x > 0) {
        ans *= 10;
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

ll mul(ll x, ll y) {
    return 1LL * x * y % mod;
}

ll sum(ll x, ll y) {
    return (1LL * x + y) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k;
    cin >> k >> mod;
    ll ans = 0;
    for (int i = 1; i <= k; ++i) {
        ans = sum(ans, sum(mul(i, tentodigits(i)), rev(i)));
    }
    cout << ans << '\n';

    return 0;
}