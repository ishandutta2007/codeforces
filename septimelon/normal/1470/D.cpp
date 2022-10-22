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

void vis(int u, int ct, vector<int>& ivis, vector<int>& fc, const vector<vector<int>>& r) {
    if (ivis[u] != ct) {
        return;
    }
    int lfc = fc[u];
    if (ct == 1) {
        while (fc[u] < r[u].size()) {
            ivis[r[u][fc[u]]] = -1;
            ++fc[u];
        }
        while (lfc < r[u].size()) {
            vis(r[u][lfc], -1, ivis, fc, r);
            ++lfc;
        }
    }
    else {
        while (fc[u] < r[u].size()) {
            if (ivis[r[u][fc[u]]] == 0) {
                ivis[r[u][fc[u]]] = 1;
                vis(r[u][fc[u]], 1, ivis, fc, r);
            }
            ++fc[u];
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> ivis(n, 0);
    vector<int> fc(n, 0);
    vector<vector<int>> r(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        r[u].push_back(v);
        r[v].push_back(u);
    }

    ivis[0] = 1;
    vis(0, 1, ivis, fc, r);

    vector<int> prep;
    for (int i = 0; i < n; ++i) {
        if (ivis[i] == 0) {
            cout << "NO\n";
            return;
        }
        if (ivis[i] == 1) {
            prep.push_back(i + 1);
        }
    }

    cout << "YES\n";
    cout << prep.size() << "\n";
    for (int i = 0; i < prep.size(); ++i) {
        cout << prep[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }
}