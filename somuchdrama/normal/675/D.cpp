#include <algorithm>
#include <assert.h>
#include <chrono>
#include <functional>
#include <numeric>
#include <math.h>
#include <memory.h>
#include <stdint.h>
#include <time.h>
#include <utility>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdio.h>

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
#define countbits __builtin_popcountll
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
    cin.tie(0);
    std::iostream::sync_with_stdio(0);
    cout << std::fixed << std::setprecision(10);
    cerr << std::fixed << std::setprecision(10);
    srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
}

const int MAXN = 1e5 + 15;
int arr[MAXN];
int l[MAXN], r[MAXN], p[MAXN];
map<int, int> code;
int decode[MAXN];
int main() {
    init();

    int n;
    cin >> n;
    set<int> all;
    for (int i = 0; i < n; ++i) {cin >> arr[i]; all.insert(arr[i]);}
    for (auto j : all) {
        int sz = code.size() + 1;
        code[j] = sz;
        decode[sz] = j;
    }
    for (int i = 0; i < n; ++i) arr[i] = code[arr[i]];
    set<int> fg;
    set<int, std::greater<int>> fl;
    fg.insert(arr[0]);
    fl.insert(arr[0]);
    for (int i = 1; i <= n; ++i) l[i] = r[i] = p[i] = -1;
    for (int i = 1; i < n; ++i) {
        int cur = arr[i];
        auto rit = fg.upper_bound(cur);
        auto lit = fl.upper_bound(cur);
        int lval = -1, rval = -1;
        if (lit != fl.end()) lval = *lit;
        if (rit != fl.end()) rval = *rit;

        if (lval != -1 && r[lval] == -1) {
            r[lval] = cur;
            p[cur] = lval;
        } else {
            l[rval] = cur;
            p[cur] = rval;
        }

        cout << decode[p[cur]] << ' ';

        fl.insert(cur);
        fg.insert(cur);
    }

    cout << '\n';


    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}