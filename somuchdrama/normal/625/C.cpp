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
typedef pair<int, int> pii;
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

const int MAXN = 500;
int arr[MAXN][MAXN];


int main() {
    init();

    int n, k;
    cin >> n >> k;
    --k;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            arr[i][j] = ++cur;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = k; j < n; ++j)
            arr[i][j] = ++cur;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += arr[i][k];
    cout << ans << '\n';
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }



    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}