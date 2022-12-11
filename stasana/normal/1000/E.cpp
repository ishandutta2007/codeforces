#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

template<class T>
T input() {
    T value;
    cin >> value;
    return value;
}

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int n, m;
vector<vector<int>> graph;
set<pair<int, int>> bridges;
vector<vector<int>> tree;
vector<int> colors;
vector<int> used;
vector<int> tin;
vector<int> tup;
int time_ = 0;

pair<int, int> getEdge(int v, int u) {
    return make_pair(min(v, u), max(v, u));
}

void dfs1(int v, int p = -1) {
    tin[v] = tup[v] = ++time_;
    used[v] = 1;
    for (auto i : graph[v]) {
        if (i == p) {
            continue;
        }
        if (used[i] == 1) {
            tup[v] = min(tup[v], tin[i]);
        }
        else {
            dfs1(i, v);
            tup[v] = min(tup[v], tup[i]);
            if (tin[v] < tup[i]) {
                bridges.insert(getEdge(i, v));
            }
        }
    }
}

void dfs2(int v, int color) {
    colors[v] = color;
    for (auto i : graph[v]) {
        if (colors[i] != -1) {
            continue;
        }
        if (bridges.find(getEdge(v, i)) != bridges.end()) {
            continue;
        }
        dfs2(i, color);
    }
}

int result = 0;

int dfs(int v, int p = -1) {
    int h1 = 0, h2 = 0;
    for (auto i : tree[v]) {
        if (i == p) {
            continue;
        }
        int newH = dfs(i, v);
        if (newH > h1) {
            h2 = h1;
            h1 = newH;
            continue;
        }
        if (newH > h2) {
            h2 = newH;
        }
    }
    result = max(result, h1 + h2);
    return h1 + 1;
}

int main() {
    start();
    cin >> n >> m;
    colors.resize(n, -1);
    graph.resize(n);
    used.resize(n);
    tin.resize(n);
    tup.resize(n);
    for (int i = 0; i < m; ++i) {
        int v = input<int>() - 1;
        int u = input<int>() - 1;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            dfs1(i);
        }
    }
    time_ = 0;
    for (int i = 0; i < n; ++i) {
        if (colors[i] == -1) {
            dfs2(i, time_++);
        }
    }
    tree.resize(time_);
    for (auto i : bridges) {
        tree[colors[i.first]].emplace_back(colors[i.second]);
        tree[colors[i.second]].emplace_back(colors[i.first]);
    }
    dfs(0);
    cout << result << endl;
    return 0;
}