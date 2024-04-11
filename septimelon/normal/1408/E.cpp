#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = 1000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;
const ll MOD = 998244353;

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

bool fuse(int v, int u, vector<int>& root) {
    v = getroot(v, root);
    u = getroot(u, root);
    if (u == v) {
        return false;
    }
    root[v] = u;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<pair<int, int>> a(m);
    vector<int> b(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    vector<vector<int>> av(m);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        av[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> av[i][j];
        }
    }

    vector<int> ra, rb;
    vector<pair<int, int>> rc;
    vector<int> maxm(n + 1, -1);
    ll totc = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < av[a[i].second].size(); ++j) {
            if (maxm[av[a[i].second][j]] == -1) {
                maxm[av[a[i].second][j]] = i;
            }
            else {
                ra.push_back(i);
                rb.push_back(maxm[av[a[i].second][j]]);
                rc.push_back({ a[i].first + b[av[a[i].second][j]], rc.size() });
                totc += 0LL + rc.back().first;
            }
        }
    }
    sort(rc.begin(), rc.end());
    reverse(rc.begin(), rc.end());

    vector<int> root(m);
    for (int i = 0; i < m; ++i) {
        root[i] = i;
    }

    for (int i = 0; i < rc.size(); ++i) {
        if (fuse(ra[rc[i].second], rb[rc[i].second], root)) {
            totc -= 0LL + rc[i].first;
        }
    }

    cout << totc << "\n";

    return 0;
}