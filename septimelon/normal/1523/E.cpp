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
const ld EPS = 1e-9;
const ll INFL = 2e18;
const int INF = 1e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);
const int WIDE = 100000;

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
    ll ans = todeg(x, d / 2);
    mul(ans, ans);
    if (d & 1) {
        mul(ans, x);
    }
    return ans;
}

vector<ll> fact, rfact;

void prep() {
    fact.assign(100001, 1);
    for (int i = 1; i <= 100000; ++i) {
        fact[i] = i;
        mul(fact[i], fact[i - 1]);
    }
    rfact.assign(100001, fact.back());
    rfact.back() = todeg(fact.back(), -1);
    for (int i = 99999; i >= 0; --i) {
        rfact[i] = i + 1;
        mul(rfact[i], rfact[i + 1]);
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    for (int a = 1; n - (k - 1) * (a - 1) >= a; ++a) {
        ll cd = fact[n - (k - 1) * (a - 1)];
        mul(cd, fact[n - a]);
        mul(cd, rfact[n - (k - 1) * (a - 1) - a]);
        mul(cd, rfact[n]);
        add(ans, cd);
        //cout << ans << " ";
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    prep();

    int q;
    cin >> q;
    for (int t = 0; t < q; ++t) {
        solve();
    }

    return 0;
}