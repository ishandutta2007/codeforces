#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
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

const int INF = 2000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;
const ll MOD = 998244353;

vector<ll> fact, rfact;

void mul(ll& a, ll b) {
    a = (a * b) % MOD;
}

void add(ll& a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

ll todeg(ll x, ll d) {
    if (d < 0) {
        d += (MOD - 1);
    }
    if (d == 0) {
        return 1LL;
    }
    ll ans = todeg(x, d / 2);
    mul(ans, ans);
    if (d % 2 == 1) {
        mul(ans, x);
    }
    return ans;
}

void prep() {
    fact.resize(1000000);
    rfact.resize(1000000);
    fact[0] = 1LL;
    for (int i = 1; i < 1000000; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
    }
    rfact.back() = todeg(fact.back(), -1);
    for (int i = 999999; i > 0; --i) {
        rfact[i - 1] = rfact[i];
        mul(rfact[i - 1], i);
    }
}

ll C(int n, int k) {
    k = max(0, min(n, k));
    ll ans = fact[n];
    mul(ans, rfact[k]);
    mul(ans, rfact[n - k]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    prep();

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> b;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        b.push_back({ l, 0 });
        b.push_back({ r, 1 });
    }
    sort(b.begin(), b.end());

    int co = 0;
    ll ans = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (b[i].second == 0) {
            ++co;
            if (co >= k) {
                //cout << co - 1 << " " << k - 1 << " " << C(co - 1, k - 1) << "\n";
                add(ans, C(co - 1, k - 1));
            }
        }
        else {
            --co;
        }
    }

    cout << ans << "\n";

    return 0;
}