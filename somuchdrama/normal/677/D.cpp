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

struct init{
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(10);
        srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()); 
    }
} init;

const int MAXN = 300, INF = 1e9;
int arr[MAXN][MAXN];
vector<pii> w[MAXN * MAXN + 1];
vector<int> ver[MAXN];
int dp[MAXN][MAXN];

int main() {

    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            w[arr[i][j]].pb({i, j});
            dp[i][j] = (arr[i][j] == 1 ? i + j : INF);
        }

    for (int c = 1; c < p; ++c) {
        for (int i = 0; i < MAXN; ++i) ver[i].clear();
        for (pii pp : w[c + 1]) ver[pp.ss].pb(pp.ff);
        vector<char> used(n, 0);
        for (pii pp : w[c])
            used[pp.ff] = true;
        // dbg(c);
        // for (int i : used) cerr << i << ' ';
        // print("");
        // for (int j = 0; j < m; ++j)
        // {
        //     dbg(j);
        //     for (int i : ver[j]) cerr << i << ' ';
        //     print("");
        // }
        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                int mn = INF;
                for (int j = 0; j < m; ++j) {
                    ++mn;
                    if (arr[i][j] == c) 
                        mn = min(mn, dp[i][j]);
                    for (int to : ver[j])
                        dp[to][j] = min(dp[to][j], mn + abs(to - i));
                }
                mn = INF;
                for (int j = m - 1; j >= 0; --j) {
                    ++mn;
                    if (arr[i][j] == c)
                        mn = min(mn, dp[i][j]);
                    for (int to : ver[j])
                        dp[to][j] = min(dp[to][j], mn + abs(to - i));
                }
            }
        }
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < m; ++j) {
        //         if (dp[i][j] == INF)
        //             cerr << "- ";
        //         else 
        //             cerr << dp[i][j] << ' ';
        //     }
        //     cerr << '\n';
        // }
    }

    cout << dp[w[p][0].ff][w[p][0].ss] << '\n';

    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}