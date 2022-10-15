#include <algorithm>
#include <assert.h>
#include <chrono>
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

const int INF = 1e9, MAXA = 301;

int main() {
    init();

    int n, T;
    cin >> n >> T;
    vector<int> st(n);

    for (int i = 0; i < n; ++i) cin >> st[i];

    if (T >= n + n) {
        vector<int> cnt(MAXA, 0), endson(MAXA, 0), beginson(MAXA, 0);
        vector<int> arr(n * n);
        for (int i = 0; i < n * n; ++i)
            arr[i] = st[i % n];
        for (int i = 0; i < n; ++i)
            ++cnt[arr[i]];
        vector<int> dp(n * n, 1);
        for (int i = 1; i < n * n; ++i)
            for (int j = 0; j < i; ++j) {
                if (arr[i] >= arr[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        for (int i = 0; i < n * n; ++i)
            endson[arr[i]] = max(endson[arr[i]], dp[i]);
        dp.assign(n * n, 1);
        for (int i = n * n - 1; i >= 0; --i) {
            for (int j = n * n - 1; j > i; --j) {
                if (arr[i] <= arr[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        for (int i = 0; i < n * n; ++i)
            beginson[arr[i]] = max(beginson[arr[i]], dp[i]);
        int btw = T - n - n;
        int ans = 0;
        for (int i = 0; i < MAXA; ++i) {
            ans = max(ans, beginson[i] + btw * cnt[i] + endson[i]);
        }
        cout << ans << '\n';
    } else {
        vector<int> arr(n * T);
        for (int i = 0; i < n * T; ++i)
            arr[i] = st[i % n];
        
        vector<int> dp(n * T, 1);
        dp[0] = 1;
        for (int i = 1; i < n * T; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] >= arr[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        cout << *(max_element(dp.begin(), dp.end())) << '\n';
    }




    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}