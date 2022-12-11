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

typedef int_fast64_t ll;
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

vector<vector<int>> rgo;
vector<int> used;
vector<int> cost;
vector<int> go;

int dfs(int v) {
    if (used[v] == 2) {
        return v;
    }
    ++used[v];
    int u = dfs(go[v]);
    if (used[v] == 1) {
        return u;
    }
    if (cost[v] < cost[u]) {
        return v;
    }
    else {
        return u;
    }
}

void dfsSet(int v) {
    if (used[v] == 3) {
        return;
    }
    used[v] = 3;
    for (auto i : rgo[v]) {
        dfsSet(i);
    }
}

int main() {
    start();

    int n;
    cin >> n;
    cost.resize(n);
    used.resize(n);
    rgo.resize(n);
    go.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> go[i];
        rgo[--go[i]].push_back(i);
    }
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        if (go[i] == i) {
            res += cost[i];
            dfsSet(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            int v = dfs(i);
            res += cost[v];
            dfsSet(v);
        }
    }
    cout << res;
    return 0;
}