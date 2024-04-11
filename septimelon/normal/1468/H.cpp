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
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(m);
    for (int j = 0; j < m; ++j) {
        cin >> a[j];
    }

    if ((n - m) % (k - 1) != 0) {
        cout << "no\n";
        return;
    }

    bool can = false;
    int cv = 0, cl = 0, cr = n - m;
    for (int i = 0; i < a.size(); ++i) {
        int delta = a[i] - cv - 1;
        cl += delta;
        cr -= delta;
        cv = a[i];
        if (cl >= k / 2 && cr >= k / 2) {
            cout << "yes\n";
            return;
        }
    }

    cout << "no\n";
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