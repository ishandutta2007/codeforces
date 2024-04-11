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
const ll INFL = 2e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void add(ll& a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

void mul(ll& a, ll b) {
    a = (a * b) % MOD;
}

ll todeg(ll x, ll d) {
    if (d < 0) {
        d += MOD - 1;
    }
    if (d == 0) {
        return 1;
    }
    ll ans{ todeg(x, d / 2) };
    mul(ans, ans);
    if (d & 1) {
        mul(ans, x);
    }
    return ans;
}

void fill(int i, int j, char s, vector<string>& data) {
    if (i < 0 || j < 0 || i >= data.size() || j >= data[0].size()) {
        return;
    }
    if (data[i][j] != '.') {
        return;
    }
    data[i][j] = s;
    if (s == 'R') {
        s = 'W';
    }
    else {
        s = 'R';
    }
    fill(i - 1, j, s, data);
    fill(i + 1, j, s, data);
    fill(i, j - 1, s, data);
    fill(i, j + 1, s, data);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (data[i][j] != '.') {
                char s = data[i][j];
                data[i][j] = '.';
                fill(i, j, s, data);
            }
        }
    }

    if (data[0][0] == '.') {
        fill(0, 0, 'R', data);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            if (data[i][j] == data[i][j + 1]) {
                cout << "NO\n";
                return;
            }
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (data[i][j] == data[i + 1][j]) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << data[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}