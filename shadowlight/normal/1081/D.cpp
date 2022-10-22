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

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct Edge {
    int v, u, w;
};

bool operator<(Edge a, Edge b) {
    return a.w < b.w;
}

vector <bool> good;

struct Dsu {
    int n;
    vector <int> r, p;
    vector <int> cnt;
    vector <int> cost;
    Dsu(int n) : n(n), r(n, 0), p(n, 0), cnt(n, 0), cost(n, 0) {
        for (int i = 0; i < n; i++) {
            cnt[i] = good[i];
            p[i] = i;
        }
    }
    int get(int v) {
        if (p[v] == v) {
            return v;
        }
        return p[v] = get(p[v]);
    }
    void uni(int v, int u, int w) {
        v = get(v);
        u = get(u);
        if (v == u) return;
        int cnow = max(cost[v], cost[u]);
        if (cnt[v] && cnt[u]) {
            cnow = w;
        }
        if (r[v] == r[u]) r[u]++;
        if (r[v] > r[u]) swap(v, u);
        p[v] = u;
        cost[u] = cnow;
        cnt[u] += cnt[v];
    }
};

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
    int n, m, k;
    cin >> n >> m >> k;
    vector <Edge> edges;
    good.resize(n, false);
    vector <int> x(k);
    for (int i = 0; i < k; i++) {
        int v;
        cin >> v;
        v--;
        x[i] = v;
        good[v] = true;
    }
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        edges.push_back({v, u, w});
    }
    sort(edges.begin(), edges.end());
    Dsu d(n);
    for (auto e : edges) {
        d.uni(e.v, e.u, e.w);
    }
    for (int i = 0; i < k; i++) {
        cout << d.cost[(d.get(x[i]))] << " ";
    }
}