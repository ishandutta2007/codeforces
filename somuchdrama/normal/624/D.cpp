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
#define dbg(a)        cerr << #a << " = " << (a) << '\n'
#define dbg2(a, b)    cerr << #a << " = " << (a) << " " << #b << " = " << (b) << '\n'
#define dbg3(a, b, c) cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << '\n'

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
typedef unsigned short ushort;
typedef pair<int, int> pii;
typedef pair<short, short> pss;
typedef pair<ushort, ushort> pus;
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

const int MAXN = 1e6+1;
ll arr[MAXN];
ll dp[MAXN][3];
int n;
ll a, b;
const ll INF = 1e18;
vector<int> fact(int x) {
    vector<int> res;
    int k = x;
    for (int i = 2; i * i <= k; ++i) 
        if (!(x % i)) {
            x /= i;
            res.pb(i);
        }
    if (x > 1) 
        res.pb(x);
    return res;
}

ll solve(int p) {
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j < 3; ++j)
            dp[i][j] = INF;
    for (int i = 0; i < 3; ++i) dp[0][i] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + a;
        if (arr[i] % p == 0) {
            dp[i][0] = dp[i - 1][0];
            dp[i][2] = min(dp[i - 1][2], dp[i - 1][1]);
        } else if ((arr[i] + 1) % p == 0 || (arr[i] - 1) % p == 0) {
            dp[i][0] = dp[i - 1][0] + b;
            dp[i][2] = min(dp[i - 1][2], dp[i - 1][1]) + b;
        }
        // dbg3(dp[i][0], dp[i][1], dp[i][2]);
    }
    ll ans = INF;
    for (int i = 0; i < 3; ++i)
        ans = min(ans, dp[n][i]);
    // dbg(ans);
    return ans;
}

int main() {
    init();

    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    set<int> ma;
    for (int i = -1; i <= 1; ++i) {
        vector<int> tmp;
        tmp = fact(arr[1] + i);
        for (auto j : tmp) 
            ma.insert(j);
        tmp = fact(arr[n] + i);
        for (auto j : tmp) 
            ma.insert(j);
    }
    ll ans = INF;
    for (auto i : ma)
        ans = min(ans, solve(i));
    cout << ans << '\n';


    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}