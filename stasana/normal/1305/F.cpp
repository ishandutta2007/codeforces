#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

typedef int64_t ll;

mt19937 rng(666);

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];

    }
    shuffle(a.begin(), a.end(), rng);
    ll m = min(n, (ll)20);
    vector<ll> maybe(1, 2);
    for (ll x = 0; x < m; ++x) {
        if (a[x] == 1) {
            continue;
        }
        for (ll y = 1; y < m; ++y) {
            if (a[y] == 1) {
                continue;
            }
            for (ll dx = -1; dx <= 1; ++dx) {
                for (ll dy = -1; dy <= 1; ++dy) {
                    ll z = gcd(a[x] + dx, a[y] + dy);
                    for (ll d = 2; d * d <= z; ++d) {
                        if (z % d == 0) {
                            maybe.emplace_back(d);
                        }
                        while (z % d == 0) {
                            z /= d;
                        }
                    }
                    if (z != 1) {
                        maybe.emplace_back(z);
                    }
                }
            }
        }
    }
    sort(maybe.begin(), maybe.end());
    maybe.resize(unique(maybe.begin(), maybe.end()) - maybe.begin());
    ll result = (ll)(1e18) + 666;
    for (ll i : maybe) {
        ll local_res = 0;
        for (ll x : a) {
            if (x < i) {
                local_res += i - x;
            } else {
                ll z = x % i;
                local_res += min(z, i - z);
            }
        }
        result = min(result, local_res);
    }
    cout << result << endl;
    return 0;
}