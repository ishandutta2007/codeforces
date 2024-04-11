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
typedef long double ld;

const ll INF = 1e18;
const ld PI = acos(-1);
const ld EPS = 1e-13;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    ll mans = 0 - INF;
    for (int lef = 0; lef < 5; lef += 2) {
        ll ca = 1LL;
        for (int i = 0; i < 5 - lef; ++i) {
            ca *= a[n - i - 1];
        }
        for (int i = 0; i < lef; ++i) {
            ca *= a[i];
        }
        mans = max(mans, ca);
    }

    cout << mans << "\n";
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