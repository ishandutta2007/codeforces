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

int n, m;
const int MAXN = 201;
struct edge{
    int to, num;
    bool my;
    edge(){}
    edge(int _to, int _num, bool _my) : to(_to), num(_num), my(_my) {}
};
vector<vector<edge>> g;
vector<char> used;
vector<char> eu;

vector<int> way;
void dfs(int v) {
    used[v] = true;
    way.pb(v);
    for (edge e : g[v]) 
        if (!used[e.to])
            dfs(e.to);
}

vector<pii> ans;
void euler(int v) {
    for (edge e : g[v])
        if (!eu[e.num]) {
            if (!e.my)
                ans.pb({v, e.to});
            eu[e.num] = true;
            euler(e.to);
        }
}

int main() {
    int t;
    scan(t);
    while (t--) {
        scan(n, m);
        used.assign(n + 1, false);
        g.assign(n + 1, vector<edge>());
        eu.assign(m + n, false);

        for (int i = 0; i < m; ++i) {
            int a, b;
            scan(a, b);
            g[a].pb(edge(b, i, false));
            g[b].pb(edge(a, i, false));
        }

        vector<vector<int>> comp;
        for (int i = 1; i <= n; ++i) 
            if (!used[i]) {
                way.clear();
                dfs(i);
                comp.pb(way);
            }
            
        int gans = 0;
        vector<vector<pii>> anses;
        for (auto & v : comp) {
            vector<int> odd;
            for (int i : v)
                if (g[i].size() & 1) 
                    odd.pb(i);
            for (uint i = 0; i < odd.size(); i += 2) {
                g[odd[i]].pb(edge(odd[i + 1], m + i / 2, true));
                g[odd[i + 1]].pb(edge(odd[i], m + i / 2, true));
            }
            ans.clear();
            euler(v[0]);
            for (uint i = 0; i < odd.size(); i += 2) {
                eu[g[odd[i]].back().num] = false;
                eu[g[odd[i + 1]].back().num] = false;
                g[odd[i]].pop_back();
                g[odd[i + 1]].pop_back();
            }
            vector<int> din(n + 1, 0), dout(n + 1, 0);
            for (pii p : ans) {
                ++din[p.ss];
                ++dout[p.ff];
            }
            int cnt = 0;
            for (int i : v)
                cnt += din[i] == dout[i];
            gans += cnt;
            anses.pb(ans);
        }
        print(gans);
        for (auto & v : anses)
            for (pii p : v)
                print(p.ff, p.ss);
    }

    return 0;
}