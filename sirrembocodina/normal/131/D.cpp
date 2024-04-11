#include <bits/stdc++.h>

using namespace std;
#define int long long

vector<vector<int>> g;
vector<bool> used;
vector<bool> on_cycle;
int start;

void check_on_cycle(int v, int p) {
    used[v] = true;
    for (int to: g[v]) {
        if (to == p) {
            continue;
        }
        if (!used[to]) {
            check_on_cycle(to, v);
        } else if (to == start) {
            on_cycle[start] = true;
        }
    }
}

vector<int> dist;

void find_dist(int v) {
    used[v] = true;
    for (int to: g[v]) {
        if (!used[to]) {
            dist[to] = dist[v] + 1;
            find_dist(to);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    g.resize(n);
    used.resize(n);
    on_cycle.resize(n);
    dist.resize(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        used.assign(n, false);
        start = i;
        check_on_cycle(i, -1);
    }
    used.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (on_cycle[i]) {
            used[i] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (on_cycle[i]) {
            find_dist(i);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
}