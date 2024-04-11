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

    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> post(3);
    for (int i = 1; i <= 3; ++i) {
        post[i % 3] += (r - i + 3) / 3;
        post[i % 3] -= (l - i + 2) / 3;
    }

    vector<vector<ll>> poss(n + 1, vector<ll>(3, 0));
    poss[0] = { 1, 0, 0 };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int d = 0; d < 3; ++d) {
                poss[i + 1][(j + d) % 3] = (poss[i + 1][(j + d) % 3] + poss[i][j] * post[d]) % MOD;
            }
        }
    }

    cout << poss[n][0] << "\n";

    return 0;
}