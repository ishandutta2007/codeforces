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
const ld EPS = 1e-11;
const ll INFL = 1e16;
const ll INF = 1e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

vector<ll> sum, minv, maxv;

void updmm(int ci, int cl, int cr) {
    if (cr - cl == 1) {
        return;
    }
    int mid = (cl + cr) / 2;
    maxv[ci * 2 + 1] = max(maxv[ci * 2 + 1], minv[ci]);
    minv[ci * 2 + 1] = max(minv[ci * 2 + 1], minv[ci]);
    if (minv[ci * 2 + 1] == maxv[ci * 2 + 1]) {
        sum[ci * 2 + 1] = minv[ci * 2 + 1] * (ll)(mid - cl);
    }
    maxv[ci * 2 + 2] = max(maxv[ci * 2 + 2], minv[ci]);
    minv[ci * 2 + 2] = max(minv[ci * 2 + 2], minv[ci]);
    if (minv[ci * 2 + 2] == maxv[ci * 2 + 2]) {
        sum[ci * 2 + 2] = minv[ci * 2 + 2] * (ll)(cr - mid);
    }
}

void setv(int ci, int cl, int cr, int i, int v) {
    if (cr <= i || cl > i) {
        return;
    }
    if (cr - cl == 1) {
        sum[ci] = v;
        minv[ci] = v;
        maxv[ci] = v;
        return;
    }

    int mid = (cl + cr) / 2;
    setv(ci * 2 + 1, cl, mid, i, v);
    setv(ci * 2 + 2, mid, cr, i, v);
    sum[ci] = sum[ci * 2 + 1] + sum[ci * 2 + 2];
    minv[ci] = minv[ci * 2 + 2];
    maxv[ci] = maxv[ci * 2 + 1];
}

void seto(int ci, int cl, int cr, int r, ll v) {
    updmm(ci, cl, cr);

    r = min(r, cr);
    if (r <= cl) {
        return;
    }
    if (minv[ci] >= v) {
        return;
    }

    if (r == cr && maxv[ci] <= v) {
        minv[ci] = v;
        maxv[ci] = v;
        sum[ci] = v * (1LL * cr - cl);
        return;
    }
    if (cr - cl == 1) {
        return;
    }

    int mid = (cl + cr) / 2;
    seto(ci * 2 + 1, cl, mid, r, v);
    seto(ci * 2 + 2, mid, cr, r, v);

    sum[ci] = sum[ci * 2 + 1] + sum[ci * 2 + 2];
    minv[ci] = minv[ci * 2 + 2];
    maxv[ci] = maxv[ci * 2 + 1];
}

int collect(int ci, int cl, int cr, int l, ll& tots) {
    updmm(ci, cl, cr);

    l = max(l, cl);
    if (l >= cr || minv[ci] > tots) {
        return 0;
    }
    
    if (l == cl && tots >= sum[ci]) {
        tots -= sum[ci];
        return cr - cl;
    }


    int mid = (cl + cr) / 2;
    return collect(ci * 2 + 1, cl, mid, l, tots) + collect(ci * 2 + 2, mid, cr, l, tots);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    sum.assign(n * 4 + 5, 0);
    minv.assign(n * 4 + 5, 0);
    maxv.assign(n * 4 + 5, 0);

    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        setv(0, 0, n, i, a);
    }

    for (int i = 0; i < q; ++i) {
        ll t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            seto(0, 0, n, x, y);
        }
        else {
            cout << collect(0, 0, n, x - 1, y) << "\n";
        }
    }

    return 0;
}