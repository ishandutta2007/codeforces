#include <algorithm>
#include <cmath>
#include <ctime>
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
typedef long double ld;

const ll INFL = 1e18 + 5LL;
const int INF = 1000000007;
const ld PI = acos(-1);
const ld EPS = 1e-13;
const ll MOD = INFL;

void add(ll& a, ll b) {
    a += b;
    while (a >= MOD) {
        a -= MOD;
    }
}

void mul(ll& a, ll b) {
    a = (a * b) % MOD;
}

ll todeg(ll x, ll d) {
    if (d < 0LL) {
        d += MOD - 1;
    }
    if (d == 0LL) {
        return 1LL;
    }
    ll ans = todeg(x, d / 2LL);
    mul(ans, ans);
    if (d % 2 == 1) {
        mul(ans, x);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> minf(n + 2, INF), minu(n + 2, INF);
    minf[0] = 0;
    for (int i = 0; i < n; ++i) {
        minu[i + 1] = min(minu[i + 1], minf[i] + a[i]);
        minu[i + 2] = min(minu[i + 2], minf[i] + a[i] + a[i + 1]);
        minf[i + 1] = min(minf[i + 1], minu[i]);
        minf[i + 2] = min(minf[i + 2], minu[i]);
    }

    cout << min(minf[n], minu[n]) << "\n";
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

    return 0;
}