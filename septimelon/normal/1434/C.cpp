#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-7;
const ll INFL = 1e16;
const int INF = 1e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

ll getdam(ll a, ll b, ll d, ll cc) {
    return a * cc - b * d * cc * (cc - 1) / 2;
}

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    
    if (a > b * c) {
        cout << "-1\n";
        return;
    }

    ll l = 1, ld = a, r = c / d + 3, rd = 0 - INFL;
    while (r - l > 2) {
        ll midl = (l * 2 + r) / 3;
        ll cdl = getdam(a, b, d, midl);
        ll midr = (l + r * 2) / 3;
        ll cdr = getdam(a, b, d, midr);
        if (cdl <= cdr && cdl > ld) {
            l = midl;
            ld = cdl;
        }
        else {
            r = midr;
            rd = cdr;
        }
    }

    ll ans = max(ld, rd);
    if (r != l) {
        ans = max({ ans, getdam(a, b, d, l + 1), getdam(a, b, d, r - 1) });
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}