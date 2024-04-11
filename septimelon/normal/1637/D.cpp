#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
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
const ld EPS = 1e-9;
const ld INFLD = 1e20;
const ll INFL = 1e17;
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

vector<vector<ll>> minc(101, vector<ll>(20001, INF));

void Solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 20000; ++j) {
            minc[i][j] = INF;
        }
    }
    minc[0][0] = 0;
    ll prefs = 0;
    for (int i = 0; i < n; ++i) {
        for (int cs = 0; cs <= prefs; ++cs) {
            minc[i + 1][cs + a[i]] = min(minc[i + 1][cs + a[i]], minc[i][cs] + cs * a[i] + (prefs - cs) * b[i]);
            minc[i + 1][cs + b[i]] = min(minc[i + 1][cs + b[i]], minc[i][cs] + cs * b[i] + (prefs - cs) * a[i]);
        }
        prefs += a[i] + b[i];
    }

    ll mintc = minc[n][0];
    for (int i = 1; i <= prefs; ++i) {
        mintc = min(mintc, minc[n][i]);
    }
    mintc *= 2;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            mintc += a[i] * a[i] + b[i] * b[i];
            mintc += a[j] * a[j] + b[j] * b[j];
        }
    }

    cout << mintc << "\n";
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