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
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> c(60, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < 60; ++j) {
            if ((a[i] >> j) & 1) {
                ++c[j];
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll lefc = 0;
        ll rigc = 0;
        for (int j = 0; j < 60; ++j) {
            if ((a[i] >> j) & 1) {
                lefc += (((1LL << j) % MOD) * c[j]) % MOD;
                rigc += (((1LL << j) % MOD) * n) % MOD;
            }
            else {
                rigc += (((1LL << j) % MOD) * c[j]) % MOD;
            }
            lefc %= MOD;
            rigc %= MOD;
        }
        ans = (ans + (lefc * rigc) % MOD) % MOD;
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
}