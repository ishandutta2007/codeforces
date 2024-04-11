#include <algorithm>
#include <assert.h>
#include <chrono>
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
    srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
}

const int MAXN = 1e5+1;

pll arr[MAXN];
ll suf[MAXN];

int main() {
    init();

    ll n, maxa, full, worst, m;
    cin >> n >> maxa >> full >> worst >> m;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        arr[i] = {x, i};
    }
    
    sort(arr, arr + n);
    std::reverse(arr, arr + n);
    
    suf[n] = 0;
    for (int i = n - 1; i >= 0; --i)
        suf[i] = suf[i + 1] + arr[i].ff;

    ll pref = 0;
    ll ans = 0;
    ll cntfull = 0, wv = 0;
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        ll curm = m - pref;
        if (curm < 0)
            break;
        pos = max(pos, i);
        ll need = (n - pos) * arr[pos].ff - suf[pos];
        while (curm - need < 0) {
            ++pos;
            need = (n - pos) * arr[pos].ff - suf[pos];
            if (pos == n)
                break;
        }
        if (pos == n)
            break;
        ll free_money = curm - need;
        ll worst_val = min(arr[pos].ff + (free_money / (n - pos)), maxa);
        ll attempt = full * i + worst * worst_val;
        if (ans < attempt) {
            ans = attempt;
            cntfull = i;
            wv = worst_val;
        }
        pref += (maxa - arr[i].ff);
    }

    if (m >= maxa * n - suf[0]) {
        if (full * n + worst * maxa > ans) {
            ans = full * n + worst * maxa;
            cntfull = n;
            wv = maxa;
        }
    }

    for (int i = 0; i < cntfull; ++i)
        arr[i].ff = maxa;
    for (int i = 0; i < n; ++i)
        arr[i].ff = max(arr[i].ff, wv);
    for (int i = 0; i < n; ++i)
        swap(arr[i].ff, arr[i].ss);

    sort(arr, arr + n);
    cout << ans << '\n';
    for (int i = 0; i < n; ++i)
        cout << arr[i].ss << ' ';
    cout << '\n';


    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}