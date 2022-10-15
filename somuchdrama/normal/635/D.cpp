#include <algorithm>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <utility>

#include <bitset>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))
#define print(a)            cerr << (a) << '\n'
#define dbg(a)              cerr << #a << " = " << (a) << '\n'
#define dbg2(a, b)          cerr << #a << " = " << (a) << " " << #b << " = " << (b) << '\n'
#define dbg3(a, b, c)       cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << '\n'
#define dbg4(a, b, c, d)    cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << " " << #d << " = " << (d) << '\n'
#define dbg5(a, b, c, d, e) cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << " " << #d << " = " << (d) << " " << #e << " = " << (e) << '\n'
#define PI 3.1415926535897932384626433

using std::cerr;
using std::cin;
using std::cout;

using std::bitset;
using std::deque;
using std::map;
using std::pair;
using std::priority_queue;
using std::queue;
using std::set;
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;

using std::abs;
using std::max;
using std::min;

using std::sort;
using std::swap;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pul;

void init() {
    std::iostream::sync_with_stdio(0);
    cout << std::fixed;
    cout.precision(10);
    cerr << std::fixed;
    cerr.precision(10);
    srand(time(0));
}

const int MAXN = 200001;
ll ta[4 * MAXN], tb[4 * MAXN];
ll a, b;
ll get_a(int v, int tl, int tr, int l, int r) {
    if ((l > tr) || (r < tl))
        return 0;
    if ((l <= tl) && (tr <= r))
        return ta[v];
    int tm = (tl + tr) / 2;
    return get_a(v * 2, tl, tm, l, r) + get_a(v * 2 + 1, tm + 1, tr, l, r);
}
ll get_b(int v, int tl, int tr, int l, int r) {
    if ((l > tr) || (r < tl))
        return 0;
    if ((l <= tl) && (tr <= r))
        return tb[v];
    int tm = (tl + tr) / 2;
    return get_b(v * 2, tl, tm, l, r) + get_b(v * 2 + 1, tm + 1, tr, l, r);
}

void update_a(int v, int tl, int tr, int ind, ll val) {
    if ((ind > tr) || (ind < tl))
        return;
    if (tl == tr) {
        ta[v] = min(a, ta[v] + val);
        return;
    }
    int tm = (tl + tr) / 2;
    update_a(v * 2, tl, tm, ind, val);
    update_a(v * 2 + 1, tm + 1, tr, ind, val);
    ta[v] = ta[v * 2] + ta[v * 2 + 1];
}
void update_b(int v, int tl, int tr, int ind, ll val) {
    if ((ind > tr) || (ind < tl))
        return;
    if (tl == tr) {
        tb[v] = min(b, tb[v] + val);
        return;
    }
    int tm = (tl + tr) / 2;
    update_b(v * 2, tl, tm, ind, val);
    update_b(v * 2 + 1, tm + 1, tr, ind, val);
    tb[v] = tb[v * 2] + tb[v * 2 + 1];
}

int main() {
    init();
    int n, k;

    cin >> n >> k >> a >> b;

    for (int i = 1; i < 4 * n; ++i)
        ta[i] = tb[i] = 0;

    int sh = 1;
    while (sh < MAXN)
        sh *= 2;
    --sh;

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int ai, di;
            cin >> di >> ai;
            --di;
            update_a(1, 0, sh, di, ai);
            update_b(1, 0, sh, di, ai);
        } else {
            int from;
            cin >> from;
            --from;
            int to = from + k;
            // dbg2(from - 1, to);
            // dbg2(get_b(1, 0, sh, 0, from - 1), get_a(1, 0, sh, to, n - 1));
            cout << get_b(1, 0, sh, 0, from - 1) + get_a(1, 0, sh, to, n - 1) << '\n';
        }
    }


    // update(1, 0, sh, ind, val);        
    // int num = get(1, 0, sh, from, to);

    
    return 0;
}