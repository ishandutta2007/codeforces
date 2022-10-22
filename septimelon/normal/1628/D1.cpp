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

const ll MOD = 1000000007;
const ll HALF = (MOD + 1LL) / 2LL;
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

void add(ll& a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

void mul(ll& a, ll b) {
    a = (a * b) % MOD;
}

ll CalsAns(int a, int b, vector<vector<ll>>& ans) {
    if (ans[a][b] == -1) {
        ans[a][b] = CalsAns(a - 1, b, ans);
        add(ans[a][b], CalsAns(a, b - 1, ans));
        mul(ans[a][b], HALF);
    }
    return ans[a][b];
}

void Solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> ans(n + 1, vector<ll>(n + 1, -1));
    for (int i = 0; i <= n; ++i) {
        ans[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        ans[i][0] = k;
        add(ans[i][0], ans[i - 1][0]);
    }

    cout << CalsAns(m, n - m, ans) << "\n";
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