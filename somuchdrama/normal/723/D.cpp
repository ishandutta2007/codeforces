#include <iomanip>
#include <iostream>
#include <sstream>

#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <ctime>
#include <functional>
#include <numeric>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))
#define nav(a) #a, '=', a

using std::cerr;
using std::cin;
using std::cout;

using std::bitset;
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
using std::min;
using std::max;

using std::swap;
using std::make_tuple;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename T> void scan(T&x) {cin >> x;}
template<typename T, typename...Ts> void scan(T&x, Ts&...xs) {
    scan(x);
    scan(xs...);
}

template<typename T> void print(T x) {cout << x << '\n';}
template<typename T, typename...Ts> void print(T x, Ts...xs) {
    cout << x << ' ';
    print(xs...);
}

template<typename T> void dbg(T x) {cerr << x << '\n';}
template<typename T, typename...Ts> void dbg(T x, Ts...xs) {
    cerr << x << ' ';
    dbg(xs...);
}

struct init{
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(10);
        using namespace std::chrono;
        srand(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count()); 
    }
    ~init() {
        dbg("Time elapsed:", 1.0 * clock() / CLOCKS_PER_SEC, "s.");
    }
} init;

const int MAXN = 52;
char f[MAXN][MAXN];
bool used[MAXN][MAXN];
vector<vector<pii>> lakes;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
bool ocean = false;
vector<pii> way;
int n, m, k;
void dfs(int x, int y) {
    used[x][y] = true;
    way.pb({x, y});
    if (x == 1 || x == n || y == 1 || y == m)
        ocean = true;
    for (int i = 0; i < 4; ++i) {
        int tox = x + dx[i], toy = y + dy[i];
        if (!used[tox][toy] && f[tox][toy] == '.')
            dfs(tox, toy);
    }
}

int main() {
    scan(n, m, k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scan(f[i][j]);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (!used[i][j] && f[i][j] == '.') {
                ocean = false;
                way.clear();
                dfs(i, j);
                if (!ocean)
                    lakes.pb(way);
            }

    sort(lakes.begin(), lakes.end(), [](const vector<pii> & a, const vector<pii> & b) {
        return a.size() < b.size();
    });

    int rem = lakes.size() - k;
    int ans = 0;
    for (int i = 0; i < rem; ++i)
        for (pii p : lakes[i]) {
            ++ans;
            f[p.ff][p.ss] = '*';
        }

    print(ans);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            cout << f[i][j];
        cout << '\n';
    }

    return 0;
}