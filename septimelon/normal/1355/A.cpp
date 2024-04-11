#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int miind(ll a) {
    ll ans = 9;
    while (a > 0) {
        ans = min(ans, a % 10);
        a /= 10;
    }
    return ans;
}

int maind(ll a) {
    ll ans = 0;
    while (a > 0) {
        ans = max(ans, a % 10);
        a /= 10;
    }
    return ans;
}

void solve() {
    ll a, k;
    cin >> a >> k;
    for (ll i = 1; i < k; ++i) {
        int mul = miind(a) * maind(a);
        if (mul == 0) {
            break;
        }
        a += mul;
    }
    cout << a << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }
    return 0;
}