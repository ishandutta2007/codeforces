#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int MAXN = 1e6 + 10;
int a[MAXN], rep[MAXN], sz[MAXN];
vector<int> adj[MAXN], bya[MAXN];
ll curS = 0;

ll paths(ll x) {
    return x * (x + 1) / 2;
}

int find(int u) {
    return rep[u] ? rep[u] = find(rep[u]) : u;
}

void join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v)
        return;
    curS -= paths(sz[u]);
    curS -= paths(sz[v]);
    rep[v] = u;
    sz[u] += sz[v];
    curS += paths(sz[u]);
}

void add(int u) {
    sz[u] = 1;
    curS++;
    for(auto v : adj[u]) {
        if(sz[v])
            join(u, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        bya[a[i]].push_back(i);
    }
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll sum_max = 0;
    for(int w = 1; w <= 1'000'000; w++) {
        for(auto u : bya[w - 1])
            add(u);
        sum_max += paths(n) - curS;
        //if(w <= 3)
        //    cout << w << " " << sum_max << '\n';
    }
    fill(rep, rep + MAXN, 0);
    fill(sz, sz + MAXN, 0);
    ll sum_min = 0;
    curS = 0;
    for(int w = 1'000'000; w >= 1; w--) {
        for(auto u : bya[w])
            add(u);
        sum_min += curS;
    }
    cout << sum_max - sum_min << '\n';
}