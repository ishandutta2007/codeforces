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
const ll INFL = 2e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void add(ll& a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

void mul(ll& a, ll b) {
    a = (a * b) % MOD;
}

ll todeg(ll x, ll d) {
    if (d < 0) {
        d += MOD - 1;
    }
    if (d == 0) {
        return 1;
    }
    ll ans{ todeg(x, d / 2) };
    mul(ans, ans);
    if (d & 1) {
        mul(ans, x);
    }
    return ans;
}

void calcCycle(int i, vector<bool>& incyc, const vector<int>& a, const vector<int>& b, const vector<int>& reva) {
    int j = i;
    while (!incyc[j]) {
        incyc[j] = true;
        int newa = b[j];
        j = reva[newa];
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), reva(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        reva[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }

    vector<bool> incyc(n, false);
    int cyc_count{ 0 };
    for (int i = 0; i < n; ++i) {
        if (!incyc[i]) {
            ++cyc_count;
            calcCycle(i, incyc, a, b, reva);
        }
    }

    cout << todeg(2, cyc_count) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}