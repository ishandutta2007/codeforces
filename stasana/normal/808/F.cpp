#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef long double ld;

inline void start() {
#ifdef BOKU_NO_PICO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
#endif
}

struct Edge {
    ll v, f, c;

    Edge(ll v, ll f, ll c)
        : v(v), f(f), c(c) {}
};

const ll INF = (ll)1e17 + 666;
const ll N = 666;
const ll S = N - 2;
const ll T = N - 1;
vector<Edge> edges;
vector<ll> g[N];
ll dist[N];
ll ptr[N];

void add_edge(ll v, ll u, ll c) {
    g[v].emplace_back(edges.size());
    edges.emplace_back(u, 0, c);
    g[u].emplace_back(edges.size());
    edges.emplace_back(v, 0, 0);
}

bool bfs() {
    fill(dist, dist + N, INF);
    dist[S] = 0;
    queue<ll> q;
    q.push(S);
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (ll u : g[v]) {
            if (edges[u].c - edges[u].f < 1) {
                continue;
            }
            if (dist[edges[u].v] > dist[v] + 1) {
                dist[edges[u].v] = dist[v] + 1;
                q.push(edges[u].v);
            }
        }
    }
    return dist[T] != INF;
}

ll dfs(ll v, ll min_c) {
    if (v == T) {
        return min_c;
    }
    for (ll i = ptr[v]; i < g[v].size(); ++i) {
        ll u = g[v][i];
        ++ptr[v];
        if (edges[u].c - edges[u].f < 1) {
            continue;
        }
        if (dist[edges[u].v] != dist[v] + 1) {
            continue;
        }
        ll x = dfs(edges[u].v, min(min_c, edges[u].c - edges[u].f));
        if (x) {
            edges[u].f += x;
            edges[u ^ 1].f -= x;
            return x;
        }
    }
    return 0;
}

struct Card {
    ll a, b, c;

    Card(ll a = 0, ll b = 0, ll c = 0)
        : a(a), b(b), c(c) {}

    bool operator< (Card other) {
        return c < other.c;
    }
};

inline void solve() {
    ll n, k;
    cin >> n >> k;
    vector<Card> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i].a >> a[i].b >> a[i].c;
    }
    bitset<200'000> prime;
    for (ll i = 2; i * i <= 100'000; ++i) {
        if (prime[i] == 0) {
            for (ll j = i * i; j <= 100'000; j += i) {
                prime[j] = 1;
            }
        }
    }
    sort(a.begin(), a.end());
    ll left = 0;
    ll right = n + 1;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        edges.clear();
        for (ll i = 0; i < N; ++i) {
            g[i].clear();
        }
        ll one = 0;
        ll sum = 0;
        for (ll i = 0; i < n; ++i) {
            if (a[i].c > mid) {
                break;
            }
            if (a[i].b == 1) {
                one = max(one, a[i].a);
            }
            else {
                sum += a[i].a;
                if (a[i].b & 1) {
                    add_edge(S, i, a[i].a);
                    for (ll j = 0; j < i; ++j) {
                        if (prime[a[i].b + a[j].b] == 0) {
                            add_edge(i, j + N / 2, INF);
                        }
                    }
                }
                else {
                    add_edge(i + N / 2, T, a[i].a);
                    for (ll j = 0; j < i; ++j) {
                        if (prime[a[i].b + a[j].b] == 0) {
                            add_edge(j, i + N / 2, INF);
                        }
                    }
                }
            }
        }
        if (one) {
            sum += one;
            add_edge(S, N / 2 - 1, one);
            for (ll i = 0; i < n; ++i) {
                if (a[i].b == 1) {
                    continue;
                }
                if (prime[1 + a[i].b] == 0) {
                    add_edge(N / 2 - 1, N / 2 + i, INF);
                }
            }
        }
        while (bfs()) {
            fill(ptr, ptr + N, 0);
            while (dfs(S, INF));
        }
        for (ll u : g[S]) {
            sum -= edges[u].f;
        }
        if (sum < k) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    if (left == n) {
        cout << -1 << endl;
    }
    else {
        cout << right << endl;
    }
}

int32_t main() {
    start();
    solve();
    return 0;
}