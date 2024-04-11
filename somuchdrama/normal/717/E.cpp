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

const int MAXN = 2e5;

bool used[MAXN];
vector<int> g[MAXN];
int col[MAXN];
vector<int> ans;
bool stop =  false;
void dfs(int v, int p = -1, bool last = false) {
    ans.pb(v);
    used[v] = true;
    if (p != -1)
        col[v] = -col[v];
    for (uint i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to]) {
            dfs(to, v, p == -1 && i + 1 == g[v].size());
            if (stop) return;
            col[v] = -col[v];
            ans.pb(v);
        }
    }
    if (stop) return;
    if (col[v] == -1) {
        if (p == -1) { // root;
            ans.pb(g[v].back());
            ans.pb(v);
            ans.pb(g[v].back());
        } else {
            ans.pb(p);
            ans.pb(v);
            col[p] = -col[p];
        }
    }
    if (last && col[p] == 1) {
        stop = true;
    }
}


int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) 
        cin >> col[i];

    if (std::count(col + 1, col + n + 1, 1) == n) {
        cout << "1\n";
        return 0;
    }

    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(1);

    for (int i : ans)
        cout << i << ' ';
    cout << '\n';

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}