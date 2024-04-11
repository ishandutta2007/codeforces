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
const ld MEPS = EPS * 1e2;
const ll INFL = 1e18;
const int INF = 1e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
        sort(b[i].begin(), b[i].end());
    }

    vector<int> li(n, 0);
    vector<pair<int, pair<int, int>>> minp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            minp.push_back({ b[i][j], { i, j } });
        }
    }
    sort(minp.begin(), minp.end());
    for (int i = 0; i < m; ++i) {
        ++li[minp[i].second.first];
    }
    
    vector<vector<int>> ans(n, vector<int>(m));
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (i == minp[j].second.first) {
                ans[i][j] = minp[j].first;
            }
            else {
                ans[i][j] = b[i][li[i]];
                ++li[i];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}