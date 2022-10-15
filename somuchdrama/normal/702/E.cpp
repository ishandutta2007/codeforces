#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>

#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
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
using std::tuple;
using std::vector;
using std::unordered_map;
using std::unordered_set;

using std::abs;
using std::max;
using std::min;
using std::swap;
using std::make_tuple;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pul;

struct init{
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(10);
        srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()); 
    }
} init;

const int MAXN = 1e5, LOGK = 35;

int to[LOGK][MAXN];
pll jump[LOGK][MAXN];
int w[MAXN];

pll merge(pll a, pll b) {
    return {a.ff + b.ff, min(a.ss, b.ss)};
}

pll get(int i, ll k) {
    pll ans = {0, 2000000000000000000};
    for (int j = LOGK - 1; j >= 0; --j)
        if ((1LL << j) < k) {
            ans = merge(ans, jump[j][i]);
            i = to[j][i];
            k -= (1LL << j);
        }
    return merge(ans, jump[0][i]);
}

int main() {
    int n; ll k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> to[0][i];
    for (int i = 0; i < n; ++i) cin >> w[i];
    for (int i = 0; i < n; ++i) jump[0][i] = {w[i], w[i]};

    for (int j = 1; j < LOGK; ++j)
        for (int i = 0; i < n; ++i) {
            to[j][i] = to[j - 1][to[j - 1][i]];
            jump[j][i] = merge(jump[j - 1][i], jump[j - 1][to[j - 1][i]]);
        }

    for (int i = 0; i < n; ++i) {
        auto ans = get(i, k);
        cout << ans.ff << ' ' << ans.ss << '\n';
    }

    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}