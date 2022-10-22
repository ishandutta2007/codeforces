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

void mov(ll& cx, ll cf, ll dt) {
    if (abs(cx - cf) <= dt) {
        cx = cf;
    }
    else if (cf > cx) {
        cx += dt;
    }
    else {
        cx -= dt;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<ll> t(n), x(n);
    int succ = 0;
    ll cx = 0, cf = 0;
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> x[i];
    }

    cf = x[0];
    for (int i = 1; i < n; ++i) {
        ll lx = cx;
        mov(cx, cf, t[i] - t[i - 1]);
        if ((cx - x[i - 1]) * (lx - x[i - 1]) <= 0) {
            ++succ;
        }
        if (cx == cf) {
            cf = x[i];
        }
    }
    if ((cx - x[n - 1]) * (cf - x[n - 1]) <= 0) {
        ++succ;
    }

    cout << succ << "\n";
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
}