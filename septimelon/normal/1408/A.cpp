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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(3, vector<int>(n));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<int> ans(n);
    ans[0] = a[0][0];
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < 3; ++i) {
            if (a[i][j] != ans[j - 1]) {
                ans[j] = a[i][j];
                break;
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (a[i][n - 1] != ans[n - 2] && a[i][n - 1] != ans[0]) {
            ans[n - 1] = a[i][n - 1];
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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