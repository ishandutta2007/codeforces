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

    int l, r;
    cin >> l >> r;

    int n = 32;
    int m = 0;
    vector<int> cl(n - 1, 0), cr(n - 1, 1);
    vector<int> r1, r2, r3;
    r1.push_back(1);
    r2.push_back(32);
    r3.push_back(l);
    ++m;
    ++l;
    for (int vi = 1; vi < 31 && r >= l; ++vi) {
        int clim = min((1 << (vi - 1)), r + 1 - l);
        cl[vi] = cr[vi - 1];
        cr[vi] = cl[vi];
        for (int j = vi - 1; j >= 0; --j) {
            if (cr[vi] + (cr[j] - cl[j]) <= cl[vi] + clim) {
                r1.push_back(j + 1);
                r2.push_back(vi + 1);
                r3.push_back(cr[vi] - cl[j]);
                ++m;
                cr[vi] += (cr[j] - cl[j]);
            }
        }
        r1.push_back(vi + 1);
        r2.push_back(32);
        r3.push_back(l - cl[vi]);
        ++m;
        l += clim;
    }

    cout << "YES\n32 " << m << "\n";
    for (int i = 0; i < r1.size(); ++i) {
        cout << r1[i] << " " << r2[i] << " " << r3[i] << "\n";
    }

    return 0;
}