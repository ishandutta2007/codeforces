#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 998244353;
const ll INF = 1000000000000000000LL;

ll sum(ll a, ll b) {
    ll ans = a + b;
    while (ans > MOD) {
        ans -= MOD;
    }
    return ans;
}

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    for (int i = 1; i <= y - x; ++i) {
        if ((y - x) % i != 0) {
            continue;
        }
        if (x + i * (n - 1) < y) {
            continue;
        }
        int first = y - i * (n - 1);
        while (first <= 0) {
            first += i;
        }

        for (int j = 0; j < n; ++j) {
            cout << first + i * j << " ";
        }
        cout << "\n";
        return;
    }
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