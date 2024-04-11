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

const ll MOD = 998244353;
const ld EPS = 1e-11;
const ll INFL = 2e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mina = INF, maxa = -INF;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mina = min(mina, a[i]);
        maxa = max(maxa, a[i]);
    }

    if (mina < 0) {
        cout << "NO\n";
        return;
    }
    else {
        cout << "YES\n101\n";
        for (int i = 0; i < 101; ++i) {
            cout << i << " ";
        }
        cout << "\n";
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
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}