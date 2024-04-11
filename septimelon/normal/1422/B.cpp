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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 998244353;
const ld EPS = 1e11;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    ll ans = 0;
    for (int i = 0; i * 2 < n - 1; ++i) {
        for (int j = 0; j * 2 < m - 1; ++j) {
            vector<ll> cas({ a[i][j], a[n - i - 1][j], a[i][m - j - 1], a[n - i - 1][m - j - 1] });
            sort(cas.begin(), cas.end());
            ans += cas[1] - cas[0] + cas[2] - cas[1] + cas[3] - cas[1];
        }
    }
    if (n % 2 == 1) {
        for (int j = 0; j * 2 < m; ++j) {
            ans += 0LL + abs(a[n / 2][j] - a[n / 2][m - j - 1]);
        }
    }
    if (m % 2 == 1) {
        for (int i = 0; i * 2 < n; ++i) {
            ans += 0LL + abs(a[i][m / 2] - a[n - i - 1][m / 2]);
        }
    }

    cout << ans << "\n";
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

    return 0;
}