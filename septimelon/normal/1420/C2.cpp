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

void upd(int i, ll& sum, vector<bool>& inc, const vector<ll>& a) {
    if (inc[i]) {
        return;
    }
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
        inc[i] = true;
        sum += a[i];
    }
    if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
        inc[i] = true;
        sum -= a[i];
    }
}

void rem(int i, ll& sum, vector<bool>& inc, const vector<ll>& a) {
    if (!inc[i]) {
        return;
    }
    inc[i] = false;
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
        sum -= a[i];
    }
    if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
        sum += a[i];
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[0] = 0;
    a.push_back(0);

    vector<bool> inc(n + 1, false);
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        upd(i, sum, inc, a);
    }

    cout << sum << "\n";
    for (int it = 0; it < q; ++it) {
        int l, r;
        cin >> l >> r;
        for (int i = -1; i < 2; ++i) {
            if (l + i > 0 && l + i <= n) {
                rem(l + i, sum, inc, a);
            }
            if (r + i > 0 && r + i <= n) {
                rem(r + i, sum, inc, a);
            }
        }
        swap(a[l], a[r]);
        for (int i = -1; i < 2; ++i) {
            if (l + i > 0 && l + i <= n) {
                upd(l + i, sum, inc, a);
            }
            if (r + i > 0 && r + i <= n) {
                upd(r + i, sum, inc, a);
            }
        }
        cout << sum << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }

    return 0;
}