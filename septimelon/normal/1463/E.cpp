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

//#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e18;
const ll INF = 1e9 + 7;
const ld PI = acos(-1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int getr(int v, vector<int>& root, vector<int>& rood) {
    //cout << "ge";
    vector<int> path;
    while (root[v] != v) {
        path.push_back(v);
        v = root[v];
    }
    while (!path.empty()) {
        rood[path.back()] += rood[root[path.back()]];
        root[path.back()] = v;
        path.pop_back();
    }
    //cout << "t\n";
    return v;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> next(n, -1), prer(n, -1);
    vector<int> root(n), rood(n, 0);
    for (int i = 0; i < n; ++i) {
        root[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> prer[i];
        --prer[i];
    }
    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        next[u] = v;
        if (getr(u, root, rood) == v) {
            cout << "0\n";
            return;
        }
        root[v] = u;
        rood[v] = 1;
    }

    vector<vector<int>> ope(n);
    vector<int> need(n, 0);
    for (int i = 0; i < n; ++i) {
        if (prer[i] == -1) {
            continue;
        }
        int ru = getr(i, root, rood);
        int rv = getr(prer[i], root, rood);
        if (ru == rv) {
            if (rood[i] < rood[prer[i]]) {
                cout << "0\n";
                return;
            }
            continue;
        }
        ope[rv].push_back(ru);
        ++need[ru];
    }

    vector<int> order;
    queue<int> que;
    for (int i = 0; i < n; ++i) {
        if (need[i] == 0 && rood[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int ci = que.front();
        que.pop();
        order.push_back(ci);
        for (int i = 0; i < ope[ci].size(); ++i) {
            --need[ope[ci][i]];
            if (need[ope[ci][i]] == 0) {
                que.push(ope[ci][i]);
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < order.size(); ++i) {
        ans.push_back(order[i]);
        for (int v = order[i]; next[v] != -1; v = next[v]) {
            ans.push_back(next[v]);
        }
    }

    if (ans.size() != n) {
        cout << "0\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }
}