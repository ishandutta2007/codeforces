#include <algorithm>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>
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
#define print(a)      cerr << (a) << '\n'
#define dbg(a)        cerr << #a << " = " << (a) << '\n'
#define dbg2(a, b)    cerr << #a << " = " << (a) << " " << #b << " = " << (b) << '\n'
#define dbg3(a, b, c) cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << '\n'
#define PI 3.1415926535897932384626433

using std::cerr;
using std::cin;
using std::cout;

using std::bitset;
using std::deque;
using std::map;
using std::pair;
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

const int MAXN = 1e5;
pll arr[MAXN];
ll dp[MAXN] = {0};
ll tree[4*MAXN] = {0};
int sh = 1;
void build(int n) {
    while (sh < n)
        sh *= 2;
}

void change(int v, int tl, int tr, int pos) {
    if ((pos > tr) || (pos < tl))
        return;
    if (tl == tr) {
        tree[v] = dp[pos];
        return;
    }
    int tm = (tl + tr) / 2;
    change(v * 2, tl, tm, pos);
    change(v * 2 + 1, tm + 1, tr, pos);
    tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
}

ll get(int v, int tl, int tr, int l, int r) {
    if ((l > tr) || (r < tl))
        return 0;
    if ((l <= tl) && (tr <= r))
        return tree[v];
    int tm = (tl + tr) / 2;
    return max(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm + 1, tr, l, r));
}

int main() {
    init();

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll r, h;
        cin >> r >> h;
        arr[i] = {r * r * h, -i};
    }

    sort(arr, arr + n);
    for (int i = 0; i < n; ++i)
        arr[i].ss = -arr[i].ss;
    build(n);
    for (int i = 0; i < n; ++i) {
        dp[arr[i].ss] = get(1, 0, sh - 1, 0, arr[i].ss) + arr[i].ff;
        change(1, 0, sh - 1, arr[i].ss);
    }
    cout << (PI * ld(get(1, 0, sh - 1, 0, n - 1))) << '\n';


    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}