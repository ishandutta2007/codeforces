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
const int MAXN = 50001, MAXT = 1e6 + 1;
vector<int> g[MAXN];
vector<int> possible[MAXN];
int team[MAXN];
int c[MAXT];

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        int l;
        cin >> l;
        possible[i].resize(l);
        for (int & j : possible[i]) {
            cin >> j;
            mx = max(mx, j);
        }
    }
    while (true) {
        set<int> used;
        for (int i = 1; i <= n; ++i) {
            team[i] = possible[i][rand() % possible[i].size()];
            used.insert(team[i]);
        }
        for (int t : used)
            c[t] = rand() & 1;

        int ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int to : g[i])
                if (c[team[i]] != c[team[to]])
                    ++ans;
        
        if (ans >= e)
        {
            for (int i = 1; i <= n; ++i)
                cout << team[i] << ' ';
            cout << '\n';
            for (int i = 1; i <= mx; ++i)
                cout << c[i]+1 << ' ';
            cout << '\n';
            return 0;
        }
    }

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}