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

const ll MOD = 998244353;
const ld EPS = 1e-11;
const ll INFL = 2e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int gcd(int a, int b) {
    if (a == 0 || b == 0) {
        return a + b;
    }
    return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ck = 0, cd = 0;
    map<pair<int, int>, int> rate;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'K') {
            ++ck;
        }
        else {
            ++cd;
        }
        if (min(cd, ck) == 0) {
            cout << i + 1 << " ";
        }
        else {
            int c_gcd = gcd(ck, cd);
            int cck = ck / c_gcd;
            int ccd = cd / c_gcd;
            if (rate.count({ cck, ccd }) == 0) {
                cout << "1 ";
                rate[{cck, ccd}] = 1;
            }
            else {
                ++rate[{cck, ccd}];
                cout << rate[{cck, ccd}] << " ";
            }
        }
    }

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}