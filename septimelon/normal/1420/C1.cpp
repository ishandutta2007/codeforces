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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> maxp(n + 1, 0 - INFL), maxn(n + 1, 0 - INFL);
    maxp[0] = 0;
    for (int i = 0; i < n; ++i) {
        maxn[i + 1] = max(maxn[i], maxp[i] + a[i]);
        maxp[i + 1] = max(maxp[i], maxn[i] - a[i]);
    }

    cout << max(maxp[n], maxn[n]) << "\n";
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