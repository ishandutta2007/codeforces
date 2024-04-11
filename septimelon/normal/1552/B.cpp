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

const ll MOD = 998244353;
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

vector<ll> fact, rfact;

void prep() {
    fact.assign(200001, 1);
    for (int i = 1; i < 200001; ++i) {
        fact[i] = i;
        mul(fact[i], fact[i - 1]);
    }
    rfact.assign(200001, 1);
    rfact.back() = todeg(fact.back(), -1);
    for (int i = 200000; i > 0; --i) {
        rfact[i - 1] = i;
        mul(rfact[i - 1], rfact[i]);
    }
}

ll C(int n, int k) {
    if (n < 0 || k < 0 || n < k) {
        return 0;
    }
    ll ans = fact[n];
    mul(ans, rfact[k]);
    mul(ans, rfact[n - k]);
    return ans;
}

bool isFirstBetter(vector<int>& p1, vector<int>& p2) {
    int cou{ 0 };
    for (int i = 0; i < 5; ++i) {
        if (p1[i] < p2[i]) {
            ++cou;
        }
    }
    return (cou >= 3);
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> r(n, vector<int>(5));
    vector<pair<int, int>> sp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> r[i][j];
        }
    }

    int best{ 0 };
    for (int i = 1; i < n; ++i) {
        if (isFirstBetter(r[i], r[best])) {
            best = i;
        }
    }

    bool good{ true };
    for (int i = 0; i < n; ++i) {
        if (i != best) {
            if (isFirstBetter(r[i], r[best])) {
                good = false;
                break;
            }
        }
    }

    if (good) {
        cout << best + 1 << "\n";
    }
    else {
        cout << "-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    //prep();

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}