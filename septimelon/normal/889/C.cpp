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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e16;
const int INF = 2e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void add(ll& a, ll b) {
    a += b;
    while (a >= MOD) {
        a -= MOD;
    }
}

void sub(ll& a, ll b) {
    add(a, MOD - b);
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
    if (d % 2 == 1) {
        mul(ans, x);
    }
    return ans;
}

vector<ll> fact, rfact;

void prep(ll high) {
    fact.assign(high + 1, 1);
    rfact.resize(high + 1);
    for (int i = 1; i <= high; ++i) {
        fact[i] = i;
        mul(fact[i], fact[i - 1]);
    }
    rfact[high] = todeg(fact[high], -1);
    for (int i = high; i > 0; --i) {
        rfact[i - 1] = rfact[i];
        mul(rfact[i - 1], i);
    }
}

ll C(int n, int k) {
    ll ans = fact[n];
    mul(ans, rfact[k]);
    mul(ans, rfact[n - k]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    prep(n + 5);

    vector<ll> sposs(n, 1);
    for (int i = 1; i < n; ++i) {
        if (i <= k) {
            sposs[i] = fact[i];
            continue;
        }
        sposs[i] = sposs[i - 1];
        mul(sposs[i], i);
        ll del = sposs[i - k - 1];
        mul(del, fact[i - 1]);
        mul(del, rfact[i - k - 1]);
        sub(sposs[i], del);
    }

    ll ans = fact[n];
    for (int i = 0; i < n; ++i) {
        ll cv = C(n - 1, i);
        mul(cv, sposs[i]);
        mul(cv, fact[n - i - 1]);
        sub(ans, cv);
    }

    cout << ans << "\n";

    return 0;
}