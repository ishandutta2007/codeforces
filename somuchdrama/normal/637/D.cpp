#include <algorithm>
#include <assert.h>
#include <chrono>
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
    cout << std::fixed << std::setprecision(10);
    cerr << std::fixed << std::setprecision(10);
    srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
}

const int MAXN = 2e5 + 2;
int arr[MAXN];

int main() {
    init();

    int n, m, s, d;
    cin >> n >> m >> s >> d;
    arr[0] = -1;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    sort(arr, arr + n + 1);

    vector<pii> ans;
    int pos = 0, last = 0;
    while (pos != m) {
        // dbg2(pos, last);
        int cl = arr[last];
        if (last == n) {
            ans.pb({0, m - cl - 1});
            break;
        }
        int nx = last + 1;
        int cn = arr[nx];
        if (cn - cl - 2 >= s) {
            int to = nx;
            bool found = false;
            while (true) {
                int ct = arr[to];
                if ((ct + 1) - (cn - 1) > d)
                    break;
                if (to == n) {
                    found = true;
                    break;
                }
                int tto = to + 1;
                int ctt = arr[tto];
                if ((ctt - 1) - (ct + 1) >= s) {
                    found = true;
                    break;
                }
                ++to;
            }
            if (found) {
                ans.pb({0, cn - cl - 2});
                ans.pb({1, (arr[to] + 1) - (cn - 1)});
                last = to;
                pos = arr[to] + 1;
            } else {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        } else {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for (auto i : ans) {
        cout << (i.ff ? "JUMP " : "RUN ") << i.ss << '\n';
    }


    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}