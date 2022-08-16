#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
// #include <atcoder/all>
// #include <bits/stdc++.h>
#include <cassert>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>

#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include <functional>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
// using namespace atcoder;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> p32;
typedef pair<ll, ll> p64;
typedef pair<p64, p64> pp64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<ll> v32;
typedef vector<vector<ll>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln '\n'
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// #define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
// #define zero ll(0)
#define set_bits(x) __builtin_popcountll(x)
// #define mll modll998244353

ll mpow(ll a, ll b)
{
    if (a == 0)
        return 0;
    if (b == 0)
        return 1;
    ll t1 = mpow(a, b / 2);
    t1 *= t1;
    t1 %= MOD;
    if (b % 2)
        t1 *= a;
    t1 %= MOD;
    return t1;
}

ll mpow(ll a, ll b, ll p)
{
    if (a == 0)
        return 0;
    if (b == 0)
        return 1;
    ll t1 = mpow(a, b / 2, p);
    t1 *= t1;
    t1 %= p;
    if (b % 2)
        t1 *= a;
    t1 %= p;
    return t1;
}

ll modinverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

ll range(ll l, ll r)
{
    return l + mt() % (r - l + 1);
}

ll rev(ll v)
{
    return mpow(v, MOD - 2);
}

ll ceil(ll p, ll q)
{
    return (p + q - 1) / q;
}

#define F first
#define S second
const int INF = 2e9 + 5;
// vertices are 0-indexed
struct graph
{
    typedef int flow_type; // **** flow type ****
    typedef int cost_type; // **** cost type ****
    struct edge
    {
        int src, dst;
        flow_type capacity, flow;
        cost_type cost;
        size_t rev;
    };
    vector<edge> edges;
    void add_edge(int src, int dst, flow_type cap, cost_type cost)
    {
        adj[src].push_back({src, dst, cap, 0, cost, adj[dst].size()});
        adj[dst].push_back({dst, src, 0, 0, -cost, adj[src].size() - 1});
    }
    int n;
    vector<vector<edge>> adj;
    graph(int n) : n(n), adj(n) {}

    pair<flow_type, cost_type> min_cost_max_flow(int s, int t)
    {
        flow_type flow = 0;
        cost_type cost = 0;

        for (int u = 0; u < n; ++u) // initialize
            for (auto &e : adj[u])
                e.flow = 0;

        vector<cost_type> p(n, 0);

        auto rcost = [&](edge e) { return e.cost + p[e.src] - p[e.dst]; };
        for (int iter = 0;; ++iter)
        {
            vector<int> prev(n, -1);
            prev[s] = 0;
            vector<cost_type> dist(n, INF);
            dist[s] = 0;
            if (iter == 0)
            { // use Bellman-Ford to remove negative cost edges
                vector<int> count(n);
                count[s] = 1;
                queue<int> que;
                for (que.push(s); !que.empty();)
                {
                    int u = que.front();
                    que.pop();
                    count[u] = -count[u];
                    for (auto &e : adj[u])
                    {
                        if (e.capacity > e.flow && dist[e.dst] > dist[e.src] + rcost(e))
                        {
                            dist[e.dst] = dist[e.src] + rcost(e);
                            prev[e.dst] = e.rev;
                            if (count[e.dst] <= 0)
                            {
                                count[e.dst] = -count[e.dst] + 1;
                                que.push(e.dst);
                            }
                        }
                    }
                }
                for (int i = 0; i < n; i++)
                    p[i] = dist[i]; // added it
                continue;
            }
            else
            { // use Dijkstra
                typedef pair<cost_type, int> node;
                priority_queue<node, vector<node>, greater<node>> que;
                que.push({0, s});
                while (!que.empty())
                {
                    node a = que.top();
                    que.pop();
                    if (a.S == t)
                        break;
                    if (dist[a.S] > a.F)
                        continue;
                    for (auto e : adj[a.S])
                    {
                        if (e.capacity > e.flow && dist[e.dst] > a.F + rcost(e))
                        {
                            dist[e.dst] = dist[e.src] + rcost(e);
                            prev[e.dst] = e.rev;
                            que.push({dist[e.dst], e.dst});
                        }
                    }
                }
            }
            if (prev[t] == -1)
                break;

            for (int u = 0; u < n; ++u)
                if (dist[u] < dist[t])
                    p[u] += dist[u] - dist[t];

            function<flow_type(int, flow_type)> augment = [&](int u, flow_type cur) {
                if (u == s)
                    return cur;
                edge &r = adj[u][prev[u]], &e = adj[r.dst][r.rev];
                flow_type f = augment(e.src, min(e.capacity - e.flow, cur));
                e.flow += f;
                r.flow -= f;
                return f;
            };
            flow_type f = augment(t, INF);
            flow += f;
            cost += f * (p[t] - p[s]);
        }
        return {flow, cost};
    }
};

int d, n;
void out(int s, int t)
{
    for (int i = 0; i < d; i++)
    {
        if (((t & 1 << i) != 0) && ((s & 1 << i) == 0))
            cout << i << " ";
    }
}

void solve()
{
    cin >> d >> n;
    v64 nodes(1, 0);
    int maxi = (1 << d);
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int num = 0;
        for (int j = 0; j < d; j++)
        {
            if (s[j] == '1')
                num += (1 << j);
        }
        nodes.push_back(num);
    }
    // cout << sz(nodes) << endl;
    graph g(2 * maxi + 2);
    for (int i = 0; i < sz(nodes); i++)
    {
        for (int j = 0; j < sz(nodes); j++)
        {
            if (nodes[j] != nodes[i])
            {
                if ((nodes[i] & nodes[j]) == nodes[j])
                {
                    int cap = 1;
                    int cost = set_bits(nodes[i]) - set_bits(nodes[j]);
                    if (nodes[j] == 0)
                        cost++;
                    // cout << nodes[i] << " " << nodes[j] << endl;
                    g.add_edge(nodes[i] + 1, nodes[j] + maxi + 1, cap, cost);
                }
            }
        }
    }
    for (int i = 0; i < maxi; i++)
    {
        g.add_edge(0, i + 1, 1, 0);
        int cap = 1;
        if (i == 0)
            cap = n;
        g.add_edge(maxi + i + 1, 2 * maxi + 1, cap, 0);
    }
    p32 ans = g.min_cost_max_flow(0, 2 * maxi + 1);
    // cout << "a" << ans.fi << " " << g.n << endl;
    v64 starts;
    v64 next(maxi + 10, -1);
    for (int i = 1; i < maxi; i++)
    {
        for (int j = 0; j < sz(g.adj[i + 1]); j++)
        {
            if (g.adj[i + 1][j].flow > 0)
            {
                if (g.adj[i + 1][j].dst == maxi + 1)
                {
                    starts.push_back(i);
                }
                else
                {
                    // cout << i << "c" << g.adj[i + 1][j].dst - maxi - 1 << endl;
                    next[g.adj[i + 1][j].dst - maxi - 1] = i;
                }
            }
        }
    }
    // cout << next[1] << "b" << endl;
    cout << ans.se - 1 << endl;
    for (int i = 0; i < sz(starts); i++)
    {
        if (i > 0)
            cout << "R ";
        out(0, starts[i]);
        int cur = starts[i];
        while (next[cur] != -1)
        {
            out(cur, next[cur]);
            cur = next[cur];
        }
    }
}

int main()
{
    fast_cin();
    ll t = 1;
    // cin >> t;
    forn(i, t)
    {
        // cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}