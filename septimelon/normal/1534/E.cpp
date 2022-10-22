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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    if (n % 2 == 1 && k % 2 == 0) {
        cout << "-1" << endl;
        return 0;
    }

    if (n % 2 == k % 2 || k * 2 <= n) {
        int sxor = 0;
        int left = n;
        int next = 1;
        while (left > 0 && (left >= 2 * k || left == k || left % 2 == 1 || left == n)) {
            left -= k;
            cout << "?";
            for (int i = 0; i < k; ++i) {
                cout << " " << next;
                ++next;
            }
            cout << endl;
            int cxor;
            cin >> cxor;
            sxor ^= cxor;
        }
        if (left > 0) {
            for (int it = 0; it < 2; ++it) {
                cout << "?";
                for (int i = 0; i < k - left / 2; ++i) {
                    cout << " " << i + 1;
                }
                for (int i = 0; i < left / 2; ++i) {
                    cout << " " << next;
                    ++next;
                }
                cout << endl;
                int cxor;
                cin >> cxor;
                sxor ^= cxor;
            }
        }

        cout << "! " << sxor << endl;

        return 0;
    }

    int sxor{ 0 };
    int delta = n - k;
    int first = 1;
    int last = delta;
    int left = n - first + 1;
    while (left > 0 && (left >= 2 * delta || left == delta || left % 2 == 1)) {
        cout << "?";
        for (int i = 1; i <= n; ++i) {
            if (i < first || i > last) {
                cout << " " << i;
            }
        }
        cout << endl;
        int cxor;
        cin >> cxor;
        sxor ^= cxor;
        first = last + 1;
        last = first + delta - 1;
        left = n - first + 1;
    }
    if (left > 0) {
        cout << "?";
        for (int i = delta - left / 2 + 1; i <= n; ++i) {
            if (i < first || i > n - left / 2) {
                cout << " " << i;
            }
        }
        cout << endl;
        int cxor;
        cin >> cxor;
        sxor ^= cxor;
        cout << "?";
        for (int i = delta - left / 2 + 1; i <= n - left / 2; ++i) {
            cout << " " << i;
        }
        cout << endl;
        cin >> cxor;
        sxor ^= cxor;
    }

    cout << "! " << sxor << endl;

    return 0;
}