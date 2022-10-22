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
const ll INFL = 1e18;
const ll INF = 1e9 + 7;
const ld PI = acos(-1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        int n, k;
        cin >> n >> k;
        vector<int> h(n), a(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
            a[i] = h[i] + k - 1;
        }
        a[0] = h[0];
        for (int i = 1; i < n; ++i) {
            a[i] = min(a[i], a[i - 1] + k - 1);
        }
        a[n - 1] = h[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            a[i] = min(a[i], a[i + 1] + k - 1);
        }
        bool tru = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] < h[i]) {
                tru = false;
                cout << "NO\n";
                break;
            }
        }
        if (tru) {
            for (int i = 1; i < n; ++i) {
                if (abs(a[i] - a[i - 1]) > k - 1) {
                    tru = false;
                    cout << "NO\n";
                    break;
                }
            }
        }
        if (tru) {
            cout << "YES\n";
        }
    }
}