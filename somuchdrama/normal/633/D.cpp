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


int main() {
    init();

    int n;
    cin >> n;
    // n = 1e3;

    vector<ll> arr(n);
    map<ll, ll> m;
    vector<pll> fib(100);
    fib[0] = {1, 0};
    fib[1] = {0, 1};
    for (int i = 2; i < 100; ++i)
        fib[i] = {(fib[i - 1].ff + fib[i - 2].ff), (fib[i - 1].ss + fib[i - 2].ss)};
    // dbg2(fib[91].ff, fib[91].ss);
    int cntz = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        // arr[i] = rand() - 1e9;
        // arr[i] = fib[rand() % 100].ss;
        // if (rand() % 2)
            // arr[i] = -arr[i];
        ++m[arr[i]];
        cntz += int(arr[i] == 0);
    }
    int ans = 2;
    for (int i = 0; i < n; ++i) {
        --m[arr[i]];
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            if (arr[i] == 0 && arr[j] == 0)
                continue;
            --m[arr[j]];
            for (int k = 2; k < 100; ++k) {
                ll cur = fib[k].ff * arr[i] + fib[k].ss * arr[j];
                // dbg5(arr[i], arr[j], k, cur, m.find(cur) != m.end() && m[cur] != 0);
                if (abs(cur) <= 1e9 && m.find(cur) != m.end() && m[cur] != 0) {
                    ans = max(ans, k + 1);
                    --m[cur];
                } else {
                    for (int l = k - 1; l >= 2; --l) {
                        ll cur2 = fib[l].ff * arr[i] + fib[l].ss * arr[j];
                        ++m[cur2];
                    }
                    break;
                }
            }
            // for (auto k : m)
                // cout << k.ff << ' ' << k.ss << ", ";
            ++m[arr[j]];
            // cout << '\n';
        }
        ++m[arr[i]];;
    }

    ans = max(ans, cntz);

    cout << ans << '\n';


    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}