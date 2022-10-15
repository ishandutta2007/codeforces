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
#define dbg5(a, b, c, d, e) cerr << #a

using namespace std;

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

const ll INF = 1e9 + 7;
ll n;

struct edge {
    ll to, f, c, w;
    edge(ll _to, ll _f, ll _c, ll _w): to(_to), f(_f), c(_c), w(_w) {}
};

vector <edge> edges;
vector <vector <ll> > g;
vector <ll> pot;

vector<int> dijkstra_of(int start) {
    vector<int> dist(n, INF);
    dist[start] = 0;
    set<pii> s;
    s.insert({0, start});
    while (s.size()) {
        auto p = *(s.begin());
        s.erase(s.begin());
        for (int i : g[p.ss]) {
            edge e = edges[i];
            if (e.f < e.c && dist[e.to] > dist[p.ss] + e.w) {
                s.erase({dist[e.to], e.to});
                dist[e.to] = dist[p.ss] + e.w;
                s.insert({dist[e.to], e.to});
            }
        }
    }
    return dist;
}

vector<int> phi;

vector<int> jonson(int start, int t) {
    vector<int> dist(n, INF), last_e(n, -1), last_v(n, -1);
    dist[start] = 0;
    set<pii> s;
    s.insert({0, start});
    while (s.size()) {
        auto p = *(s.begin());
        s.erase(s.begin());
        if (dist[p.ss] != p.ff) continue;
        for (int i = 0; i < g[p.ss].size(); ++i) {
            edge e = edges[g[p.ss][i]];
            if (e.f < e.c && dist[e.to] > dist[p.ss] + phi[p.ss] + e.w - phi[e.to]) {
                dist[e.to] = dist[p.ss] + phi[p.ss] + e.w - phi[e.to];
                s.insert({dist[e.to], e.to});
                last_e[e.to] = g[p.ss][i];
                last_v[e.to] = p.ss;
            }
        }
    }
    vector<int> ans;
    if (dist[t] == INF) return ans;
    for (int i = 0; i < n; ++i)
        phi[i] += dist[i];
    while (t != start) {
        ans.pb(last_e[t]);
        t = last_v[t];
    }
    phi[start] += dist[start];
    return ans;
}

// set <ll> get_path() {
//     vector <ll> dist(n, INF);
//     vector <bool> used(n, false);
//     vector <ll> last_e(n, -1), last_v(n, -1);
//     dist[0] = 0;
//     ll p = 0;
//     while (p != -1) {
//         used[p] = true;
//         for (ll i : g[p]) {
//             if (edges[i].f < edges[i].c && dist[edges[i].to] > dist[p] + edges[i].w + pot[p] - pot[edges[i].to]) {
//                 dist[edges[i].to] = dist[p] + edges[i].w + pot[p] - pot[edges[i].to];
//                 last_e[edges[i].to] = i;
//                 last_v[edges[i].to] = p;
//             }
//         }
//         p = -1;
//         for (ll i = 0; i < n; ++i)
//             if (!used[i] && dist[i] != INF && (p == -1 || dist[p] > dist[i]))
//                 p = i;
//     }
//     for (ll i = 0; i < n; ++i)
//         pot[i] += dist[i];

//     set <ll> ans;
//     if (dist[n - 1] == INF)
//         return std::move(ans);
//     ll prev = n - 1, psz = 0;
//     while (prev > 0) {
//         ans.insert(last_e[prev]);
//         if (psz == ans.size()) 
//             break;
//         psz = ans.size();
//         // if (ans.size() > n + 100) 
//         //     break;
//         // assert(ans.size() <= edges.size());
//         prev = last_v[prev];
//     }
//     return std::move(ans);
// }

int32_t main() {
    string s;
    ll x, m;
    cin >> n >> s >> m;
    n += 2;
    g.resize(n);
    for (ll i = 1; i <= m; ++i) {
        string t;
        ll w;
        cin >> t >> w;
        if (t.length() <= n - 2) {
            for (ll j = 0; j < n - 2; ++j) {
                string tt;
                for (ll k = j; k < min(n - 2, j + ll(t.length())); ++k)
                    tt.pb(s[k]);
                if (tt == t) {
                    ll sz = edges.size();
                    edges.push_back(edge(j + 1 + t.length(), 0, 1, -w));
                    edges.push_back(edge(j + 1, 0, 0, w));
                    g[j + 1].push_back(sz);
                    g[j + 1 + t.length()].push_back(sz + 1);
                }
            }
        }
    }
    cin >> x;
    for (ll i = 0; i < n - 1; ++i) {
        ll sz = edges.size();
        edges.push_back(edge(i + 1, 0, x, 0));
        edges.push_back(edge(i, 0, 0, 0));
        g[i].push_back(sz);
        g[i + 1].push_back(sz + 1);   
    }   


    phi = dijkstra_of(0);
    for (ll it = 0; it < x; ++it) {
        vector <int> cnt = jonson(0, n - 1);
        for (ll i: cnt) {
            edges[i].f++;
            edges[i ^ 1].f--;
        }
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (auto j : g[i]) {
            if (edges[j].f > 0)
                ans += edges[j].w;
        }
    }
    cout << -ans << "\n";
}