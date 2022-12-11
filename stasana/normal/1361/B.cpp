#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef int64_t ll;

const ll MOD = 1'000'000'007;

ll power(ll x, ll n) {
    if (n == 0) {
        return 1;
    }
    if (n & 1) {
        return x * power(x * x % MOD, n >> 1) % MOD;
    }
    return power(x * x % MOD, n >> 1);
}

void solve() {
    ll n, p;
    cin >> n >> p;

    vector<ll> a(n);
    for (ll& i : a) {
        cin >> i;
    }

    if (p == 1) {
        cout << (n & 1) << "\n";
        return;
    }

    sort(a.rbegin(), a.rend());

    ll result = power(p, a[0]);

    map<ll, ll> x;

    x[a[0]] = 1;

    ll sign = -1;

    for (ll i = 1; i < n; ++i) {
        ll id = a[i];
        result = (result + sign * power(p, id) + MOD) % MOD;
        x[id] += sign;
        while (x[id] == sign * p) {
            x[id + 1] += sign;
            x[id] = 0;
            ++id;
        }
        while (!x.empty() && x.rbegin()->second == 0) {
            x.erase(x.rbegin()->first);
        }
        if (x.empty() || x.rbegin()->second < 0) {
            sign = 1;
        } else {
            sign = -1;
        }
    }
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    for (ll i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}