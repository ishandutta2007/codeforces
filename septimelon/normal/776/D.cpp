#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-7;
const ll INFL = 1e16;
const int INF = 1e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int getroot(int v, vector<int>& root) {
    vector<int> path;
    while (root[v] != v) {
        path.push_back(v);
        v = root[v];
    }
    for (int i = 0; i < path.size(); ++i) {
        root[path[i]] = v;
    }
    return v;
}

void fuse(int u, int v, vector<int>& root) {
    u = getroot(u, root);
    v = getroot(v, root);
    root[u] = v;
}

bool dfs(int v, int c, vector<int>& type, const vector<vector<int>>& con) {
    if (type[v] == 1 - c) {
        return false;
    }
    if (type[v] != -1) {
        return true;
    }
    type[v] = c;
    bool succ = true;
    for (int i = 0; i < con[v].size(); ++i) {
        succ = (succ && dfs(con[v][i], 1 - c, type, con));
    }
    return succ;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> r(n), p1(n, -1), p2(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < x; ++j) {
            int ro;
            cin >> ro;
            --ro;
            if (p1[ro] == -1) {
                p1[ro] = i;
            }
            else {
                p2[ro] = i;
            }
        }
    }

    vector<int> root(m);
    for (int i = 0; i < m; ++i) {
        root[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        if (r[i] == 1) {
            fuse(p1[i], p2[i], root);
        }
    }

    vector<vector<int>> con(m);
    for (int i = 0; i < n; ++i) {
        if (r[i] == 1) {
            continue;
        }
        int u = getroot(p1[i], root);
        int v = getroot(p2[i], root);
        con[u].push_back(v);
        con[v].push_back(u);
    }

    vector<int> type(m, -1);
    for (int i = 0; i < m; ++i) {
        if (root[i] == i && type[i] == -1) {
            if (!dfs(i, 0, type, con)) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";

    return 0;
}