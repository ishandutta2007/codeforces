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
const ll INFL = 2e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

//mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(123876);

double ReadDouble() {
    string s;
    cin >> s;
    return stol(s);
}

void Solve() {
    ll n, k;
    string s;
    cin >> n >> k >> s;

    int cn = n;
    vector<ll> totc(n + 1, 0);
    vector<vector<ll>> without(n + 1, vector<ll>(26, 0));
    for (int i = 0; i < 26; ++i) {
        without[0][i] = 1;
    }
    totc[0] = 1;

    for (char c : s) {
        int cs = c - 'a';
        for (int i = cn; i > 0; --i) {
            ll del = without[i - 1][cs];
            without[i - 1][cs] = 0;
            
            totc[i] = min(k, totc[i] + del);
            for (int j = 0; j < 26; ++j) {
                without[i][j] = min(k, without[i][j] + del);
            }
        }
    }

    ll incl{ 0 }, cost{ 0 };
    for (ll i = 0; i <= cn; ++i) {
        cost += min(totc[cn - i], k) * i;
        k -= min(totc[cn - i], k);
    }

    if (k > 0LL) {
        cost = -1;
    }

    cout << cost << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    for (int q = 1; q <= 1; ++q) {
        Solve();
    }

    return 0;
}