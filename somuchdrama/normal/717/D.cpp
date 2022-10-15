#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>

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

typedef unsigned int uint;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct init{
    init() {
        cin.tie(0);
        cout.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(10);
        srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()); 
    }
} init;


map<int, double> dp[128];
double p[128];

int X;

double calc(int n, int x) {
    // dbg2(n, x);
    if (dp[x].find(n) != dp[x].end()) {
        // print("found");
        // dbg(dp[x][n]);
        return dp[x][n];
    }
    dp[x][n] = 0;
    if (n & 1) {
        for (int k = 0; k < 128; ++k) 
            if (k <= X && (x ^ k) < 128)
                dp[x][n] += calc(n - 1, x ^ k) * p[k];
    }
    else {
        for (int k = 0; k < 128; ++k)
            if ((x ^ k) < 128)
                dp[x][n] += calc(n >> 1, x ^ k) * calc(n >> 1, k);
    }
    // dbg3(n, x, dp[x][n]);
    return dp[x][n];
}

int main() {

    int n;
    cin >> n >> X;
    for (int i = 0; i <= X; ++i) {
        cin >> p[i];
        dp[i][1] = p[i];
    }

    cout << 1.0 - calc(n, 0) << '\n';

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}