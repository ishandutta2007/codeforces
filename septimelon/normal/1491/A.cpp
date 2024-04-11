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
const int INF = 1e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    int c1 = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            ++c1;
        }
    }

    for (int j = 0; j < q; ++j) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            --x;
            if (a[x] == 1) {
                --c1;
            }
            else {
                ++c1;
            }
            a[x] = 1 - a[x];
        }
        else {
            if (c1 >= x) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
    }

    return 0;
}