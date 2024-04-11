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

const ll MOD = 1000000007;
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

void sub(ll& a, ll b) {
    add(a, MOD - b);
}

void mul(ll& a, ll b) {
    a = (a * b) % MOD;
}

ll to_deg(ll x, ll d) {
    if (d < 0) {
        d += MOD - 1;
    }
    if (d == 0) {
        return 1;
    }
    ll ans = to_deg(x, d / 2);
    mul(ans, ans);
    if (d & 1) {
        mul(ans, x);
    }
    return ans;
}

void dfs(int vi, int cval, vector<int>& u, vector<int>& v, vector<vector<int>>& r, vector<int>& val) {
    int ni = -1;
    for (int i = 0; i < r[vi].size(); ++i) {
        int ri = r[vi][i];
        if (val[ri] == 0) {
            val[ri] = cval;
            if (u[ri] == vi) {
                ni = v[ri];
            }
            else {
                ni = u[ri];
            }
            break;
        }
    }

    if (ni >= 0) {
        dfs(ni, 5 - cval, u, v, r, val);
    }
}

void Solve() {
    int n;
    cin >> n;
    vector<int> u(n - 1), v(n - 1);
    vector<vector<int>> r(n);
    bool bad = false;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u[i] >> v[i];
        --u[i];
        --v[i];
        r[u[i]].push_back(i);
        r[v[i]].push_back(i);
        if (r[u[i]].size() > 2 || r[v[i]].size() > 2) {
            bad = true;
        }
    }

    if (bad) {
        cout << "-1\n";
        return;
    }

    vector<int> val(n - 1, 0);
    for (int i = 0; i < n; ++i) {
        if (r[i].size() == 1) {
            dfs(i, 2, u, v, r, val);
            break;
        }
    }

    for (int a : val) {
        cout << a << " ";
    }
    cout << "\n";
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