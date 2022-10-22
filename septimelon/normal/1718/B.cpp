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
#include <memory>
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

const ll MOD = 998244353;
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

vector<ll> fact, rfact;

void Prep(int n) {
    fact.assign(n, 1);
    rfact.assign(n, 1);
    for (int i = 1; i < n; ++i) {
        fact[i] = i;
        mul(fact[i], fact[i - 1]);
    }
    rfact[n - 1] = ToDeg(fact[n - 1], -1);
    for (int i = n - 1; i > 0; --i) {
        rfact[i - 1] = i;
        mul(rfact[i - 1], rfact[i]);
    }
}

ll C(ll n, ll k) {
    ll x = fact[n];
    if (k < 0 || k > n) {
        return 0;
    }
    mul(x, rfact[k]);
    mul(x, rfact[n - k]);
    //cout << "C[" << n << "," << k << "] = " << x << endl;
    return x;
}

void Solve() {
    int n;
    set<pair<ll, int>> els;
    ll total_sum{ 0 };
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        ll v;
        cin >> v;
        els.insert({ v, i });
        total_sum += v;
    }

    if (total_sum <= 1) {
        cout << "YES\n";
        return;
    }

    vector<ll> fib(2, 1);
    ll fibs{ 2 };
    while (fibs < total_sum) {
        fib.push_back(fib[fib.size() - 2] + fib.back());
        fibs += fib.back();
    }

    if (fibs != total_sum) {
        cout << "NO\n";
        return;
    }

    int li{ -1 };
    while (!els.empty()) {
        auto iter = els.rbegin();
        if (iter->second == li) {
            ++iter;
        }
        if (iter == els.rend() || iter->first < fib.back()) {
            cout << "NO\n";
            return;
        }
        ll nv = iter->first - fib.back();
        fib.pop_back();
        li = iter->second;
        els.erase({ iter->first, iter->second });
        if (nv > 0) {
            els.insert({ nv, li });
        }
    }

    cout << "YES\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // LOCAL

    //Prep(7000);

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        Solve();
    }

    return 0;
}