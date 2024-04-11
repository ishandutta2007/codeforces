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

bool iss(int i, vector<int>& a) {
    if (i <= 0 || i >= a.size() - 1) {
        return false;
    }
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
        return true;
    }
    if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
        return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int sca = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (iss(i, a)) {
            ++sca;
        }
    }

    int mind = sca;
    for (int i = 0; i < n - 1; ++i) {
        int del = a[i];
        int csc = sca;
        for (int del = -1; del < 2; ++del) {
            if (iss(i + del, a)) {
                --csc;
            }
        }
        a[i] = a[i + 1];
        for (int del = -1; del < 2; ++del) {
            if (iss(i + del, a)) {
                ++csc;
            }
        }
        a[i] = del;
        mind = min(mind, csc);
    }
    for (int i = 1; i < n; ++i) {
        int del = a[i];
        int csc = sca;
        for (int del = -1; del < 2; ++del) {
            if (iss(i + del, a)) {
                --csc;
            }
        }
        a[i] = a[i - 1];
        for (int del = -1; del < 2; ++del) {
            if (iss(i + del, a)) {
                ++csc;
            }
        }
        a[i] = del;
        mind = min(mind, csc);
    }

    cout << mind << "\n";
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