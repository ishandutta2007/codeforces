#include <algorithm>
#include <assert.h>
#include <chrono>
#include <cmath>
#include <functional>
#include <numeric>
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

const int MAXN = 1002;

const ll MOD = 1e9 + 7;

char arr[MAXN][MAXN];
int u[MAXN][MAXN]; int d[MAXN][MAXN]; int r[MAXN][MAXN]; int l[MAXN][MAXN]; int ul[MAXN][MAXN]; int ur[MAXN][MAXN]; int dl[MAXN][MAXN]; int dr[MAXN][MAXN];
int u2[MAXN][MAXN]; int d2[MAXN][MAXN]; int r2[MAXN][MAXN]; int l2[MAXN][MAXN]; int ul2[MAXN][MAXN]; int ur2[MAXN][MAXN]; int dl2[MAXN][MAXN]; int dr2[MAXN][MAXN];
int u3[MAXN][MAXN]; int d3[MAXN][MAXN]; int r3[MAXN][MAXN]; int l3[MAXN][MAXN]; int ul3[MAXN][MAXN]; int ur3[MAXN][MAXN]; int dl3[MAXN][MAXN]; int dr3[MAXN][MAXN];

double val[MAXN][MAXN];
int ans2[MAXN][MAXN], ans3[MAXN][MAXN];

int main() {

    int n;
    cin >> n;
    for (int i = 0; i <= n + 1; ++i) for (int j = 0; j <= n + 1; ++j) arr[i][j] = '0';

    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
        ul[i][j] = ur[i][j] = dl[i][j] = dr[i][j] = -1;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> arr[i][j];

    bool all_zero = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            all_zero &= (arr[i][j] == '0');

            l2[i][j] = l2[i][j - 1] + (arr[i][j] == '2');
            l3[i][j] = l3[i][j - 1] + (arr[i][j] == '3');
            l[i][j] = (arr[i][j] == '0' ? 0 : l[i][j - 1] + 1);
        }
        for (int j = n; j >= 1; --j) {
            r2[i][j] = r2[i][j + 1] + (arr[i][j] == '2');
            r3[i][j] = r3[i][j + 1] + (arr[i][j] == '3');
            r[i][j] = (arr[i][j] == '0' ? 0 : r[i][j + 1] + 1);
        }
    }

    if (all_zero)
    {
        puts("0");
        return 0;
    }

    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= n; ++i) {
            u2[i][j] = u2[i - 1][j] + (arr[i][j] == '2');
            u3[i][j] = u3[i - 1][j] + (arr[i][j] == '3');
            u[i][j] = (arr[i][j] == '0' ? 0 : u[i - 1][j] + 1);
        }
        for (int i = n; i >= 1; --i) {
            d2[i][j] = d2[i + 1][j] + (arr[i][j] == '2');
            d3[i][j] = d3[i + 1][j] + (arr[i][j] == '3');
            d[i][j] = (arr[i][j] == '0' ? 0 : d[i + 1][j] + 1);
        }
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            ul[i][j] = (arr[i][j] == '0' ? 0 : ul[i - 1][j - 1] + 1);
            ul2[i][j] = ul2[i - 1][j - 1] + (arr[i][j] == '2');
            ul3[i][j] = ul3[i - 1][j - 1] + (arr[i][j] == '3');
        }

    for (int i = 1; i <= n; ++i)
        for (int j = n; j >= 1; --j) {
            ur[i][j] = (arr[i][j] == '0' ? 0 : ur[i - 1][j + 1] + 1);
            ur2[i][j] = ur2[i - 1][j + 1] + (arr[i][j] == '2');
            ur3[i][j] = ur3[i - 1][j + 1] + (arr[i][j] == '3');            
        }

    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= n; ++j) {
            dl[i][j] = (arr[i][j] == '0' ? 0 : dl[i + 1][j - 1] + 1);
            dl2[i][j] = dl2[i + 1][j - 1] + (arr[i][j] == '2');
            dl3[i][j] = dl3[i + 1][j - 1] + (arr[i][j] == '3');            
        }

    for (int i = n; i >= 1; --i)
        for (int j = n; j >= 1; --j) {
            dr[i][j] = (arr[i][j] == '0' ? 0 : dr[i + 1][j + 1] + 1);
            dr2[i][j] = dr2[i + 1][j + 1] + (arr[i][j] == '2');
            dr3[i][j] = dr3[i + 1][j + 1] + (arr[i][j] == '3');              
        }

    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
        assert(ul[i][j] != -1);
        assert(ur[i][j] != -1);
        assert(dl[i][j] != -1);
        assert(dr[i][j] != -1);
    }

    const double two = log(2.0), three = log(3.0), one = log(1.0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            // dbg2(i, j);
            // dbg4(u[i][j], d[i][j], l[i][j], r[i][j]);
            // dbg4(ul[i][j], ur[i][j], dl[i][j], dr[i][j]);
            // dbg4(u2[i][j], d2[i][j], l2[i][j], r2[i][j]);
            // dbg4(ul2[i][j], ur2[i][j], dl2[i][j], dr2[i][j]);
            // dbg4(u3[i][j], d3[i][j], l3[i][j], r3[i][j]);
            // dbg4(ul3[i][j], ur3[i][j], dl3[i][j], dr3[i][j]);
            // straight
            {
                int sz = min(min(u[i][j], d[i][j]), min(l[i][j], r[i][j]));
                assert(i - sz >= 0);
                assert(j - sz >= 0);
                assert(i + sz <= n + 1);
                assert(j + sz <= n + 1);
                int cnt2 = u2[i][j] - u2[i - sz][j] + d2[i][j] - d2[i + sz][j] + 
                           r2[i][j] - r2[i][j + sz] + l2[i][j] - l2[i][j - sz] - 
                           (arr[i][j] == '2') * 3;
                int cnt3 = u3[i][j] - u3[i - sz][j] + d3[i][j] - d3[i + sz][j] + 
                           r3[i][j] - r3[i][j + sz] + l3[i][j] - l3[i][j - sz] - 
                           (arr[i][j] == '3') * 3;
                val[i][j] = two * cnt2 + three * cnt3;
                if (sz != 0 && cnt2 == 0 && cnt3 == 0) val[i][j] = one;
                ans2[i][j] = cnt2;
                ans3[i][j] = cnt3;
                // dbg4(sz, cnt2, cnt3, val[i][j]);
            }
            // diag
            {
                int sz = min(min(ul[i][j], ur[i][j]), min(dl[i][j], dr[i][j]));
                assert(i - sz >= 0);
                assert(j - sz >= 0);
                assert(i + sz <= n + 1);
                assert(j + sz <= n + 1);
                int cnt2 = ur2[i][j] - ur2[i - sz][j + sz] + ul2[i][j] - ul2[i - sz][j - sz] + 
                           dr2[i][j] - dr2[i + sz][j + sz] + dl2[i][j] - dl2[i + sz][j - sz] -
                           (arr[i][j] == '2') * 3;
                int cnt3 = ur3[i][j] - ur3[i - sz][j + sz] + ul3[i][j] - ul3[i - sz][j - sz] + 
                           dr3[i][j] - dr3[i + sz][j + sz] + dl3[i][j] - dl3[i + sz][j - sz] -
                           (arr[i][j] == '3') * 3;
                double pot = two * cnt2 + three * cnt3;
                if (sz != 0 && cnt2 == 0 && cnt3 == 0) pot = one;
                if (val[i][j] < pot) {
                    val[i][j] = pot;
                    ans2[i][j] = cnt2;
                    ans3[i][j] = cnt3;
                }
                // dbg4(sz, cnt2, cnt3, pot);
            }
        }
    }

    double ans = -1; int wx, wy;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (ans < val[i][j]) {
                ans = val[i][j];
                wx = i;
                wy = j;
            }

    ll last_ans = 1;
    for (int i = 0; i < ans2[wx][wy]; ++i) {
        last_ans *= 2;
        last_ans %= MOD;
    }
    for (int i = 0; i < ans3[wx][wy]; ++i) {
        last_ans *= 3;
        last_ans %= MOD;
    }

    cout << last_ans << '\n';

    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}