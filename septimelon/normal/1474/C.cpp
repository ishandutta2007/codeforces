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
    n *= 2;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    for (int fi = 1; fi < n; ++fi) {
        int x = a[0] + a[fi];
        vector<int> ord;
        multiset<int> els;
        for (int i = 0; i < n; ++i) {
            els.insert(a[i]);
        }

        while (els.size() > 0) {
            int ma = *els.rbegin();
            els.erase(els.lower_bound(ma));
            ord.push_back(ma);
            if (els.count(x - ma) == 0) {
                break;
            }
            els.erase(els.lower_bound(x - ma));
            ord.push_back(x - ma);
            x = ma;
        }

        if (els.size() == 0) {
            cout << "YES\n" << a[0] + a[fi] << "\n";
            for (int i = 0; i < n; i += 2) {
                cout << ord[i] << " " << ord[i + 1] << "\n";
            }
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
    for (int q = 0; q < t; ++q) {
        solve();
    }
}