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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cc(100001, 0), cn(100001, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i & 1) {
            ++cn[a[i]];
        }
        else {
            ++cc[a[i]];
        }
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            --cn[a[i]];
        }
        else {
            --cc[a[i]];
        }
    }

    bool isnz{ false };
    for (int ca : cc) {
        if (ca != 0) {
            isnz = true;
        }
    }
    for (int ca : cn) {
        if (ca != 0) {
            isnz = true;
        }
    }

    if (isnz) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
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