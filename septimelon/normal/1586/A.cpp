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

bool isp(int x) {
    for (int y = 2; y * y <= x; ++y) {
        if (x % y == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    int oddp{ 0 };
    int sum{ 0 };
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        sum += a;
        if (a & 1) {
            oddp = i + 1;
        }
    }

    if (!isp(sum)) {
        oddp = 0;
    }

    if (oddp) {
        cout << n - 1 << "\n";
    }
    else {
        cout << n << "\n";
    }

    for (int i = 1; i <= n; ++i) {
        if (i != oddp) {
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}