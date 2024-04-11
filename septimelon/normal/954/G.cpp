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
const ld EPS = 1e11;
const ll INFL = 1e16;
const int INF = 1e9 + 7;

void mul(ll& a, ll b) {
    a = (a * b) % MOD;
}

void add(ll& a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, r, k;
    cin >> n >> r >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> def(n + r * 3 + 5, 0);
    for (int i = 0; i < n; ++i) {
        def[max(0LL, i - r)] += a[i];
        def[i + r + 1] -= a[i];
    }

    ll left = 0, righ = 1e18 + 1e16;
    while (righ - left > 1LL) {
        ll mid = (left + righ) / 2;
        vector<ll> dif(def);
        ll csp = k;
        ll act = 0;
        for (int i = 0; i < n; ++i) {
            act += dif[i];
            if (act < mid) {
                csp -= (mid - act);
                dif[i + 2 * r + 1] -= mid - act;
                act = mid;
                if (csp < 0LL) {
                    break;
                }
            }
        }
        if (csp < 0) {
            righ = mid;
        }
        else {
            left = mid;
        }
    }

    cout << left << "\n";

    return 0;
}