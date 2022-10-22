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

bool isund(ll x1, ll y1, ll x2, ll y2, ll fx, ll fy) {
    if ((fx - x2) * (y2 - y1) == (fy - y2) * (x2 - x1)) {
        return true;
    }
    ll dx = x2 - x1;
    ll dy = y2 - y1;
    ll cfy = y1;
    if (dy != 0) {
        cfy += ((fx - x1) * dy + dx * 1000000000LL) / dx - 1000000000LL;
    }
    return cfy < fy;
}

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void updb(ll cx, ll cy, ll& bx, ll& by, ll fx, ll fy) {
    //if (isund(cx, cy, bx, by, fx, fy)) {
        bx = cx;
        by = cy;
    //}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, h;
    cin >> n >> h;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    ld ans = 0;
    ll bx = x[n - 2], by = y[n - 2];
    ans += dist(x[n - 2], y[n - 2], x[n - 1], y[n - 1]);
    for (int ci = n - 3; ci >= 0; --ci) {
        //cout << ci << ": ";
        if (!isund(x[ci], y[ci], bx, by, x[n - 1], y[n - 1] + h)) {
            //cout << "over\n";
            continue;
        }
        if (x[ci + 1] == bx || isund(x[ci + 1], y[ci + 1], bx, by, x[n - 1], y[n - 1] + h)) {
            //cout << "full view " << dist(x[ci], y[ci], x[ci + 1], y[ci + 1]) << "\n";
            ans += dist(x[ci], y[ci], x[ci + 1], y[ci + 1]);
            updb(x[ci], y[ci], bx, by, x[n - 1], y[n - 1] + h);
            continue;
        }
        ld a1, a2, c1, c2;
        a1 = (ld)(y[ci + 1] - y[ci]) / (ld)(x[ci + 1] - x[ci]);
        c1 = (ld)y[ci] - a1 * x[ci];
        a2 = (ld)(y[n - 1] + h - by) / (ld)(x[n - 1] - bx);
        c2 = (ld)by - a2 * bx;
        ld intx = (c2 - c1) / (a1 - a2);
        ld inty = a1 * intx + c1;
        ans += dist(x[ci], y[ci], intx, inty);
        //cout << "seen " << dist(x[ci], y[ci], intx, inty) << "\n";
        updb(x[ci], y[ci], bx, by, x[n - 1], y[n - 1] + h);
    }

    cout << setprecision(15) << ans << "\n";

    return 0;
}