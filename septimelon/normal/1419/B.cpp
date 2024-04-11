#include <algorithm>
#include <cmath>
#include <ctime>
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

const int INF = 1000000009;

void solve() {
    ll x;
    cin >> x;

    ll ans = 0;
    ll tots = 0;
    for (ll i = 1; tots + i * (i + 1) / 2 <= x; i = i * 2 + 1) {
        tots += i * (i + 1) / 2;
        ++ans;
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