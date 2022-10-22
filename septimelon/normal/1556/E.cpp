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

const ll MOD = 998244353;
const ld EPS = 1e-11;
const ll INFL = 2e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

vector<ll> max_del; /// del is : for i in [0, ci] : sum(a[i] - b[i])

void add_max_del(int ci, int cl, int cr, int fi, ll del) {
    if (cr <= fi || cl > fi) {
        return;
    }

    if (cr - cl == 1) {
        max_del[ci] = del;
        return;
    }

    int cm = (cl + cr) / 2;
    add_max_del(ci * 2 + 1, cl, cm, fi, del);
    add_max_del(ci * 2 + 2, cm, cr, fi, del);
    max_del[ci] = max(max_del[ci * 2 + 1], max_del[ci * 2 + 2]);
}

ll get_max_del(int ci, int cl, int cr, int fl, int fr) {
    if (cl >= fr || cr <= fl) {
        return -INFL;
    }
    if (cl >= fl && cr <= fr) {
        return max_del[ci];
    }
    int cm = (cl + cr) / 2;
    return max(get_max_del(ci * 2 + 1, cl, cm, fl, fr), get_max_del(ci * 2 + 2, cm, cr, fl, fr));
}

vector<ll> min_del; /// del is : for i in [0, ci] : sum(a[i] - b[i])

void add_min_del(int ci, int cl, int cr, int fi, ll del) {
    if (cr <= fi || cl > fi) {
        return;
    }

    if (cr - cl == 1) {
        min_del[ci] = del;
        return;
    }

    int cm = (cl + cr) / 2;
    add_min_del(ci * 2 + 1, cl, cm, fi, del);
    add_min_del(ci * 2 + 2, cm, cr, fi, del);
    min_del[ci] = min(min_del[ci * 2 + 1], min_del[ci * 2 + 2]);
}

ll get_min_del(int ci, int cl, int cr, int fl, int fr) {
    if (cl >= fr || cr <= fl) {
        return INFL;
    }
    if (cl >= fl && cr <= fr) {
        return min_del[ci];
    }
    int cm = (cl + cr) / 2;
    return min(get_min_del(ci * 2 + 1, cl, cm, fl, fr), get_min_del(ci * 2 + 2, cm, cr, fl, fr));
}

vector<ll> sum_del; /// del is : for i in [0, ci] : sum(a[i] - b[i])

void add_sum_del(int ci, int cl, int cr, int fi, ll del) {
    if (cr <= fi || cl > fi) {
        return;
    }

    if (cr - cl == 1) {
        sum_del[ci] = del;
        return;
    }

    int cm = (cl + cr) / 2;
    add_sum_del(ci * 2 + 1, cl, cm, fi, del);
    add_sum_del(ci * 2 + 2, cm, cr, fi, del);
    sum_del[ci] = sum_del[ci * 2 + 1] + sum_del[ci * 2 + 2];
}

ll get_sum_del(int ci, int cl, int cr, int fl, int fr) {
    if (cl >= fr || cr <= fl) {
        return 0;
    }
    if (cl >= fl && cr <= fr) {
        return sum_del[ci];
    }
    int cm = (cl + cr) / 2;
    return get_sum_del(ci * 2 + 1, cl, cm, fl, fr) + get_sum_del(ci * 2 + 2, cm, cr, fl, fr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    max_del.assign(n * 4 + 5, -INFL);
    min_del.assign(n * 4 + 5, INFL);
    sum_del.assign(n * 4 + 5, 0);
    vector<ll> del(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        del[i + 1] = del[i] + a[i] - b[i];
        add_max_del(0, 0, n, i, del[i + 1]);
        add_min_del(0, 0, n, i, del[i + 1]);
        //add_sum_del(0, 0, n, i, abs(a[i] - b[i]));
    }

    for (int qq = 0; qq < q; ++qq) {
        int l, r;
        cin >> l >> r;
        --l;

        ll otr_del = del[r] - del[l];
        if (otr_del != 0LL) {
            cout << "-1\n";
            continue;
        }
        ll max_del = get_max_del(0, 0, n, l, r) - del[l];
        if (max_del > 0LL) {
            cout << "-1\n";
            continue;
        }
        ll min_del = get_min_del(0, 0, n, l, r) - del[l];
        //ll ans = get_sum_del(0, 0, n, l, r) / 2;
        cout << -min_del << "\n";
    }

    return 0;
}