#pragma GCC optimize("O3")

#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

const ll MOD = 998244353;
const ld EPS = 1e-11;
const ld INFLD = 1e20;
const ll INFL = 4e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

//mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(643896);

double ReadDouble() {
    string s;
    cin >> s;
    return stol(s);
}

void Solve() {
    int l = INF, r = -INF;
    int cl = INF, cr = INF, cb = INF;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int nl, nr, nc;
        cin >> nl >> nr >> nc;
        if (nl < l) {
            cl = nc;
            cb = INF;
        }
        if (nl == l) {
            cl = min(cl, nc);
        }
        if (nr > r) {
            cr = nc;
            cb = INF;
        }
        if (nr == r) {
            cr = min(cr, nc);
        }
        if ((nl < l && nr >= r) || (nl <= l && nr > r)) {
            cb = nc;
        }
        if (nl == l && nr == r) {
            cb = min(cb, nc);
        }
        l = min(l, nl);
        r = max(r, nr);

        //cout << l << " " << r << endl;

        cout << min(cl + cr, cb) << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // LOCAL

    int t = 1;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        Solve();
    }

    return 0;
}