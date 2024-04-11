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

const int MAXN = 3e5 + 1;
vector<int> graph[MAXN];
int cnt[MAXN];
int centroid[MAXN];
int maxson[MAXN];
int p[MAXN];

void dfs(int v) {
    // dbg(v);
    cnt[v] = 1;
    maxson[v] = 0;
    for (const int to : graph[v]) {
        dfs(to);
        cnt[v] += cnt[to];
        maxson[v] = max(maxson[v], cnt[to]);
    }
    int which = -1;
    for (const int to : graph[v]) {
        if (cnt[to] + cnt[to] > cnt[v]) {
            which = to;
            break;
        }
    }
    if (which == -1)
        centroid[v] = v;
    else {
        int cur = centroid[which];
        while (maxson[p[cur]] + maxson[p[cur]] <= cnt[v] && cur != v) {
            cur = p[cur];
        }
        centroid[v] = cur;
    }
    // dbg2(v, centroid[v]);
}

int main() {

    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
        // dbg2(p[i], i);
        graph[p[i]].pb(i);
    }
    maxson[0] = n + n;
    p[1] = 0;
    dfs(1);

    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        cout << centroid[x] << '\n';
    }

    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}