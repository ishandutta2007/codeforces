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

const ll MOD = 1000000007;
const ld EPS = 1e11;
const ll INFL = 1e16;
const int INF = 1e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int r, n;
    cin >> r >> n;
    vector<int> x(n + r * 4 + 50, 0), y(n + r * 4 + 50, 0), t(n + r * 4 + 50, 0), maxvis(n + r * 4 + 50, 0), maxsuf(n + r * 4 + 50, 0);
    x[0] = 1;
    y[0] = 1;
    t[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> x[i] >> y[i];
    }

    for (int i = n; i >= 0; --i) {
        for (int j = 1; j < 2 * r + 20; ++j) {
            if (t[i + j] - t[i] >= abs(x[i] - x[i + j]) + abs(y[i] - y[i + j])) {
                maxvis[i] = max(maxvis[i], maxvis[i + j]);
            }
        }
        maxvis[i] = max(maxvis[i], maxsuf[i + 2 * r + 15]);
        ++maxvis[i];
        maxsuf[i] = max(maxsuf[i + 1], maxvis[i]);
    }

    /*for (int i = 1; i <= n; ++i) {
        cout << maxvis[i] << " ";
    }*/

    cout << maxvis[0] - 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}