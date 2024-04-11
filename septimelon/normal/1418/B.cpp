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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> fi;
    for (int i = 0; i < n; ++i) {
        int cur;
        cin >> cur;
        if (cur == 0) {
            fi.push_back(i);
        }
    }

    vector<int> free;
    for (int i = 0; i < fi.size(); ++i) {
        free.push_back(a[fi[i]]);
    }
    sort(free.begin(), free.end());
    reverse(free.begin(), free.end());

    for (int i = 0; i < free.size(); ++i) {
        a[fi[i]] = free[i];
    }

    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
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