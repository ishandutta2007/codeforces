#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
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
    int n, k;
    cin >> n >> k;
    int da = 1;
    int la;
    cin >> la;
    for (int i = 1; i < n; ++i) {
        int ca;
        cin >> ca;
        if (ca != la) {
            la = ca;
            ++da;
        }
    }

    if (k == 1) {
        if (da == 1) {
            cout << "1\n";
        }
        else {
            cout << "-1\n";
        }
        return;
    }

    int ans = 1;
    da -= k;
    while (da > 0) {
        ++ans;
        da -= k - 1;
    }

    cout << ans << "\n";
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