#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 998244353;
const ll INF = 1000000000000000000LL;

ll sum(ll a, ll b) {
    ll ans = a + b;
    while (ans > MOD) {
        ans -= MOD;
    }
    return ans;
}

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

void solve() {
    ll n, s;
    cin >> n >> s;
    
    vector<ll> cf;
    ll cs = 0LL;
    for (ll cn = n; cn > 0LL; cn /= 10LL) {
        cs += cn % 10;
        cf.push_back(cn % 10);
    }

    if (cs <= s) {
        cout << "0\n";
        return;
    }

    /*ll down = 0LL;
    cs = 0LL;
    for (int i = cf.size() - 1; i >= 0; --i) {
        down *= 10LL;
        down += cf[i];
        cs += cf[i];
        if (cs >= s) {
            while (cs > s) {
                --cs;
                --down;
            }
            for (int j = i - 1; j >= 0; --j) {
                down *= 10LL;
            }
            break;
        }
    }*/

    ll up = 0LL;
    cs = 0LL;
    for (int i = cf.size() - 1; i >= 0; --i) {
        up *= 10LL;
        up += cf[i];
        cs += cf[i];
        if (cs >= s) {
            while (up % 10LL != 0) {
                ++up;
            }
            for (int j = i - 1; j >= 0; --j) {
                up *= 10LL;
            }
            break;
        }
    }

    ll ans = up - n;

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}