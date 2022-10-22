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
const ll INFL = 1e18;
const ll INF = 1e9 + 7;
const ld PI = acos(-1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int coupd = 0;
    vector<pair<int, int>> coup(n + 1, { 0, 0 });
    for (int i = 1; i < n; ++i) {
        coup[i].second = i;
        if (a[i] == a[i - 1]) {
            coup[a[i]].first += 2;
            ++coupd;
        }
    }
    coup[n].second = n;
    ++coup[a[0]].first;
    ++coup[a.back()].first;
    sort(coup.begin(), coup.end());
    reverse(coup.begin(), coup.end());

    if (coupd == 0) {
        cout << "0\n";
        return;
    }

    int coupe = 0;
    for (int i = 1; i < coup.size(); ++i) {
        coupe += coup[i].first;
    }

    if (coupe >= coup[0].first - 2) {
        cout << (coup[0].first + coupe - 2) / 2 << "\n";
        return;
    }

    for (int i = 1; i < n; ++i) {
        if (coup[0].second != a[i - 1] && coup[0].second != a[i] && a[i] != a[i - 1]) {
            coupe += 2;
        }
        if (coupe >= coup[0].first - 2) {
            cout << (coup[0].first + coupe - 2) / 2 << "\n";
            return;
        }
    }

    cout << "-1\n";
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