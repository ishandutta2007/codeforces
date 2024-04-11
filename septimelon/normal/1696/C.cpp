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
#include <unordered_set>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-9;
const ld INFLD = 1e20;
const ll INFL = 1e17;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

//mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rnd(643896);

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

ll ToDeg(ll x, ll d) {
    if (d < 0) {
        d += MOD - 1;
    }
    if (d == 0) {
        return 1;
    }
    ll ans = ToDeg(x, d / 2);
    mul(ans, ans);
    if (d & 1) {
        mul(ans, x);
    }
    return ans;
}

vector<pair<ll, ll>> Divide(vector<ll>& x, ll m) {
    vector<pair<ll, ll>> sp;
    for (ll& v : x) {
        ll count{ 1 };
        while (v % m == 0) {
            v /= m;
            count *= m;
        }
        if (!sp.empty() && sp.back().first == v) {
            sp.back().second += count;
        }
        else {
            sp.emplace_back(v, count);
        }
    }
    return sp;
}

void Solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll& v : a) {
        cin >> v;
    }
    int c;
    cin >> c;
    vector<ll> b(c);
    for (ll& v : b) {
        cin >> v;
    }

    auto da(Divide(a, m)), db(Divide(b, m));

    //cout << da[0].first << " " << db[0].first << "\n";

    if (da == db) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
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
    for (int i = 0; i < t; ++i) {
        Solve();
    }

    return 0;
}