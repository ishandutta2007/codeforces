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

const int INF = 2000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a[0];
    bool can = false;
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        if (a[i] >= a[i - 1]) {
            can = true;
        }
    }

    if (can) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }

    return 0;
}