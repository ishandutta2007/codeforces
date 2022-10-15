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

int main() {
    const ll MNOGO = 1e18; 
    int n; 
    cin >> n;
    vector<ll> cost(n);
    for (ll & i : cost) cin >> i;
    vector<pll> dp(n, {MNOGO, MNOGO});
    vector<pair<string, string>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].ff;
        reverse(a[i].ff.begin(), a[i].ff.end());
        a[i].ss = a[i].ff;
        reverse(a[i].ff.begin(), a[i].ff.end());
    }

    dp[0] = {0, cost[0]};
    for (int i = 1; i < n; ++i) {
        if (a[i].ff >= a[i - 1].ff) dp[i].ff = min(dp[i].ff, dp[i - 1].ff);
        if (a[i].ff >= a[i - 1].ss) dp[i].ff = min(dp[i].ff, dp[i - 1].ss);
        if (a[i].ss >= a[i - 1].ff) dp[i].ss = min(dp[i].ss, dp[i - 1].ff + cost[i]);
        if (a[i].ss >= a[i - 1].ss) dp[i].ss = min(dp[i].ss, dp[i - 1].ss + cost[i]);
    }

    ll ans = min(dp[n - 1].ff, dp[n - 1].ss);
    cout << (ans == MNOGO ? -1 : ans) << '\n';

    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}