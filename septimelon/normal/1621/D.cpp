#pragma GCC optimize("O3")

#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

const ll MOD = 998244353;
const ld EPS = 1e-11;
const ld INFLD = 1e20;
const ll INFL = 4e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

//mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(643896);

double ReadDouble() {
    string s;
    cin >> s;
    return stol(s);
}

vector<int> dx{ 0, -1, 0, 1 };
vector<int> dy{ 1, 0, -1, 0 };

ll GetMP(int n, vector<vector<ll>> data) {
    vector<vector<ll>> minl(data), minr(data), minu(data), mind(data);

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            minl[i][j] += minl[i][j - 1];
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            minu[i][j] += minu[i - 1][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = n - 2; j >= 0; --j) {
            minr[i][j] += minr[i][j + 1];
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            mind[i][j] += mind[i + 1][j];
        }
    }

    ll mina = INFL;

    for (int i = 0; i < n; i += max(n - 1, 1)) {
        for (int j = 0; j < n; j += max(n - 1, 1)) {
            mina = min(mina, min(minl[i][j], minr[i][j]) + min(minu[i][j], mind[i][j]) - data[i][j]);
        }
    }

    return mina;
}

void Solve() {
    int n;
    cin >> n;

    vector<vector<ll>> c(2 * n, vector<ll>(2 * n));
    for (auto& cc : c) {
        for (ll& ccc : cc) {
            cin >> ccc;
        }
    }

    ll ans{ 0 };
    for (int i = n; i < 2 * n; ++i) {
        for (int j = n; j < 2 * n; ++j) {
            ans += c[i][j];
            c[i][j] = 0;
        }
    }

    vector<vector<ll>> datald(n, vector<ll>(n));
    vector<vector<ll>> dataru(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            datald[i][j] = c[i + n][j];
            dataru[i][j] = c[i][j + n];
        }
    }

    ans += min(GetMP(n, datald), GetMP(n, dataru));

    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // LOCAL

    int t = 1;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        Solve();
    }

    return 0;
}