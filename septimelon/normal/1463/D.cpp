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
    vector<int> inc(2 * n, 0-1);
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        inc[b - 1] = 1;
    }

    int mdpr = 0, mdsu = 0;
    int cd = 0;
    for (int i = 0; i < 2 * n; ++i) {
        cd += inc[i];
        mdpr = max(mdpr, cd);
    }
    cd = 0;
    for (int i = 2 * n - 1; i >= 0; --i) {
        cd += inc[i];
        mdsu = max(mdsu, cd);
    }
    //cout << mdpr << " " << mdsu << "\n";

    cout << n + 1 - mdpr - mdsu << "\n";
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