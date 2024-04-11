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

const int INF = 1000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;
const ll MOD = 998244353;

ll sum(ll a, ll b) {
    ll ans = a + b;
    while (ans >= MOD) {
        ans -= MOD;
    }
    return ans;
}

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;

    ll ans = 0;
    ll awai = 1;
    for (int i = 0; i < n; ++i) {
        awai *= 2;
        if (s[i] == 'b') {
            --awai;
        }
        if (t[i] == 'a') {
            --awai;
        }
        ans += min(k, awai);
        awai = min(k + 10LL, awai);
    }

    cout << ans << "\n";

    return 0;
}