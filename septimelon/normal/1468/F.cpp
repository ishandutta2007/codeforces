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

//#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e18;
const ll INF = 1e9 + 7;
const ld PI = acos(-1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

ll gcd(ll a, ll b) {
    if (a * b == 0) {
        return max(a, b);
    }
    return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    map<pair<int, int>, int> m;
    for (int i = 0; i < n; ++i) {
        ll x, y, u, v;
        cin >> x >> y >> u >> v;
        ll dx = u - x, dy = v - y;
        ll cgcd = gcd(abs(dx), abs(dy));
        dx /= cgcd;
        dy /= cgcd;
        if (m.count({ dx, dy }) == 0) {
            m[{dx, dy}] = 1;
        }
        else {
            ++m[{dx, dy}];
        }
        //cout << dx << " " << dy << "\n";
    }

    ll ans = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        ll cop = 0;
        pair<int, int> op = it->first;
        op.first *= -1;
        op.second *= -1;
        if (m.count({ op }) > 0) {
            cop = m[op];
            ans += (ll)it->second * (ll)cop;
        }
    }

    cout << ans / 2LL << "\n";
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