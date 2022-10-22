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

int hind(int a) {
    int ans = 0;
    while (a > 0) {
        a /= 2;
        ++ans;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> cou(35, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cou[hind(a[i])];
    }

    ll ans = 0;
    for (int i = 0; i < 35; ++i) {
        ans += cou[i] * (cou[i] - 1) / 2;
    }

    cout << ans << "\n";
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