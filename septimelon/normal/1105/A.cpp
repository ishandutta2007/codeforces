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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-7;
const ll INFL = 1e16;
const int INF = 1e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int mina = INF, mint = 0;
    for (int t = 1; t < 100; ++t) {
        int ca = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > t) {
                ca += a[i] - t - 1;
            }
            else if (a[i] < t) {
                ca += t - a[i] - 1;
            }
        }
        if (ca < mina) {
            mina = ca;
            mint = t;
        }
    }

    cout << mint << " " << mina << "\n";

    return 0;
}