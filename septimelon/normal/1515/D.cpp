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

#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ld MEPS = EPS * 1e2;
const ll INFL = 1e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> c(n + 1, 0);

    for (int i = 0; i < l; ++i) {
        int cc;
        cin >> cc;
        ++c[cc];
    }
    for (int i = 0; i < r; ++i) {
        int cc;
        cin >> cc;
        --c[cc];
    }

    vector<int> evenl, oddl, evenr, oddr;
    int discol = 0;
    for (int i = 0; i <= n; ++i) {
        if (c[i] == 0) {
            continue;
        }
        if (c[i] > 0) {
            if (c[i] % 2 == 0) {
                evenl.push_back(c[i]);
            }
            else {
                oddl.push_back(c[i]);
            }
        }
        else {
            if ((0 - c[i]) % 2 == 0) {
                evenr.push_back(0 - c[i]);
            }
            else {
                oddr.push_back(0 - c[i]);
            }
        }
        discol += abs(c[i]);
    }

    discol /= 2;

    /*for (int ci : oddl) {
        cout << ci << " ";
    } cout << endl;
    for (int ci : evenl) {
        cout << ci << " ";
    } cout << endl;
    for (int ci : oddr) {
        cout << ci << " ";
    } cout << endl;
    for (int ci : evenr) {
        cout << ci << " ";
    } cout << endl;*/

    while (!oddl.empty() && !oddr.empty()) {
        --oddl.back();
        --oddr.back();
        if (oddl.back() > 0)
            evenl.push_back(oddl.back());
        oddl.pop_back();
        if (oddr.back() > 0)
            evenr.push_back(oddr.back());
        oddr.pop_back();
    }

    while (!oddl.empty() && !evenr.empty()) {
        oddl.pop_back();
        oddl.pop_back();
        evenr.back() -= 2;
        if (evenr.back() == 0) {
            evenr.pop_back();
        }
    }

    while (!oddr.empty() && !evenl.empty()) {
        oddr.pop_back();
        oddr.pop_back();
        evenl.back() -= 2;
        if (evenl.back() == 0) {
            evenl.pop_back();
        }
    }

    discol += (oddl.size() + oddr.size()) / 2;

    cout << discol << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}