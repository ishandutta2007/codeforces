#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>

#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

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

const int MAXN = 2e5 + 1;
vector<int> g[MAXN];
int p[MAXN];
// int comp[MAXN];
int c = 0;
int used[MAXN];
int cycle[MAXN];
void dfs(int v, int f = -1) {
    used[v] = c;
    for (const int to : g[v]) {
        if (!used[to])
            dfs(to, v);
        else if (to != f) cycle[c] = v;
    }
}

int main() {
    int n;
    cin >> n; vector<int> pet;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        if (i == p[i]) {
            pet.pb(i);
        } else {
            g[p[i]].pb(i);
            g[i].pb(p[i]);
        }
    }
    int wc = -1;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            ++c;
            dfs(i);
            if (wc == -1 && cycle[c]) wc = c;
        }
        // dbg2(i, used[i]);
    }

    int ans = 0;
    if (pet.empty()) {
        ++ans;
        p[cycle[wc]] = cycle[wc];
        pet.pb(wc);
    }

    int root = *pet.begin();
    set<int> joined;
    joined.insert(used[root]);

    for (int i = 1; i <= n; ++i) {
        if (joined.find(used[i]) == joined.end()) {
            if (cycle[used[i]]) {
                ++ans;
                p[cycle[used[i]]] = root;
                joined.insert(used[i]);
            }
        }
    }

    for (int i : pet) {
        if (i != root) {
            if (joined.find(used[i]) == joined.end()) {
                ++ans;
                p[i] = root;
                joined.insert(used[i]);
            }
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; ++i)
        cout << p[i] << ' ';
    cout << '\n';


    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}