#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e18 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct Edge {
    ll v, c, f, w, rev;
};

ll n, s, t;

vector <vector <Edge> > gr;

void addEdge(ll v, ll u, ll c, ll w) {
    gr[v].push_back({u, c, 0, w, (ll) gr[u].size()});
    gr[u].push_back({v, 0, 0, -w, (ll) gr[v].size() - 1});
}

vector <ll> pi;

void FordBellman() {
    pi.assign(n, INF);
    pi[s] = 0;
    for (ll i = 0; i < n; i++) {
        for (ll v = 0; v < n; v++) {
            for (auto &e : gr[v]) {
                if (e.c - e.f == 0) continue;
                pi[e.v] = min(pi[e.v], pi[v] + e.w);
            }
        }
    }
}

bool Dijkstra() {
    vector <ll> d(n, INF);
    vector <pair <int, int> > pr(n);
    d[s] = 0;
    set <pair <ll, ll> > q;
    q.insert({d[s], s});
    while (!q.empty()) {
        ll v = q.begin()->second;
        q.erase(q.begin());
        for (auto &e : gr[v]) {
            if (e.c - e.f == 0) continue;
            if (d[e.v] > d[v] + pi[v] - pi[e.v] + e.w) {
                q.erase({d[e.v], e.v});
                d[e.v] = d[v] + pi[v] - pi[e.v] + e.w;
                pr[e.v] = {e.v, e.rev};
                q.insert({d[e.v], e.v});
            }
        }
    }
    if (d[t] == INF) return false;
    for (ll i = 0; i < n; i++) {
        pi[i] += d[i];
    }
    ll sum = 0;
    ll now = t;
    while (now != s) {
        auto &e = gr[pr[now].first][pr[now].second];
        e.f--;
        gr[e.v][e.rev].f++;
        sum -= e.w;
        now = e.v;
    }
    //cout << sum << "\n";
    return true;
}

ll m;

ll MinCost() {
    FordBellman();
    while (Dijkstra()) {
        //cout << "kek\n";
    }
    ll res = 0;
    for (ll v = 0; v < n; v++) {
        for (auto e : gr[v]) {
            if (e.f < 0) continue;
            if (v == s && e.f != e.c) {
                cout << "-1\n";
                exit(0);
            }
            res += e.f * e.w;
        }
    }
    return res;
}

vector <ll> a;

vector <vector <ll> > ngr;

vector <ll> val;

vector <pair <ll, vector <ll> > > all;

ll dfs(ll v, ll p, vector <ll> &now) {
    ll sum = 0;
    now.push_back(v);
    for (ll u : ngr[v]) {
        if (u == p) continue;
        vector <ll> nxt;
        sum += dfs(u, v, nxt);
        if (now.size() < nxt.size()) swap(now, nxt);
        for (ll x : nxt) {
            now.push_back(x);
        }
    }
    if (val[v] == -1) {
        return sum;
    }
    if (val[v] - sum > now.size() || sum > val[v]) {
        cout << "-1\n";
        exit(0);
    }
    all.push_back({val[v] - sum, now});
    now.clear();
    return val[v];
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll cap[2];
    cin >> m >> cap[0] >> cap[1];
    a.resize(m, 0);
    cap[0]--, cap[1]--;
    s = 0, t = 1;
    n = 2 * m + 2;
    gr.resize(n);
    for (ll i = 0; i < m; i++) {
        cin >> a[i];
    }
    vector <pair <ll, ll> > edges[2];
    for (ll it = 0; it < 2; it++) {
        for (ll i = 1; i < m; i++) {
            ll v, u;
            cin >> v >> u;
            v--, u--;
            edges[it].push_back({v, u});
        }
    }
    for (ll i = 0; i < m; i++) {
        addEdge(i + 2, i + m + 2, 1, -a[i]);
    }
    vector <ll> data;
    for (ll it = 0; it < 2; it++) {
        //cout << "IT " << it << "\n";
        ngr.clear();
        ngr.resize(m);
        for (auto t : edges[it]) {
            ll v = t.first, u = t.second;
            ngr[v].push_back(u);
            ngr[u].push_back(v);
        }
        val.clear();
        val.resize(m, -1);
        ll q;
        cin >> q;
        for (ll i = 0; i < q; i++) {
            ll v, w;
            cin >> v >> w;
            v--;
            val[v] = w;
        }
        vector <ll> now;
        data.push_back(val[cap[it]]);
        dfs(cap[it], -1, now);
        for (auto elem : all) {
            ll x = elem.first;
            auto p = elem.second;
//            cout << x << "\n";
//            for (ll x : p) {
//                cout << x << " ";
//            }
//            cout << "\n";
            gr.push_back({});
            n++;
            if (!it) {
                addEdge(s, n - 1, x, 0);
            } else {
                addEdge(n - 1, t, x, 0);
            }
            for (ll x : p) {
                if (!it) {
                    addEdge(n - 1, x + 2, 1, 0);
                } else {
                    addEdge(x + m + 2, n - 1, 1, 0);
                }
            }
        }
        all.clear();
    }
    if (data[0] != data[1]) {
        cout << "-1\n";
        exit(0);
    }
//    cout << "GR\n";
//    for (int v = 0; v < n; v++) {
//        for (auto e : gr[v]) {
//            if (!e.c) continue;
//            cout << v << " " << e.v << " " << e.c << " " << e.w << "\n";
//        }
//    }
//    cout << "----\n";
    cout << -MinCost();
}