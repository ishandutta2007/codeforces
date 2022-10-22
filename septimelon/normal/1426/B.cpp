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

const int INF = 1000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> tl(n), tr(n), dl(n), dr(n);
    for (int i = 0; i < n; ++i) {
        cin >> tl[i] >> tr[i] >> dl[i] >> dr[i];
    }

    if (m % 2 == 1) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (dl[i] == tr[i]) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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