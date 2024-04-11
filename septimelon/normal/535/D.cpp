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

vector<int> Prefix(string s) {
    int n = s.length();
    vector<int> pr(n);
    for (int i = 1; i < n; i++) {
        int j = pr[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pr[j - 1];
        if (s[i] == s[j])
            j++;
        pr[i] = j;
    }
    return pr;
}

vector<int> Prefix(vector<int> s) {
    int n = s.size();
    vector<int> pr(n);
    for (int i = 1; i < n; i++) {
        int j = pr[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pr[j - 1];
        if (s[i] == s[j])
            j++;
        pr[i] = j;
    }
    return pr;
}

void Add(ll& a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

void Mul(ll& a, ll b) {
    a = (a * b) % MOD;
}

ll ToDeg(ll x, ll d) {
    if (d == 0) {
        return 1;
    }
    ll v = ToDeg(x, d / 2);
    Mul(v, v);
    if (d & 1) {
        Mul(v, x);
    }
    return v;
}

void Solve() {
    int n, m;
    cin >> n >> m;
    string s(n, '.');
    string p;
    cin >> p;
    int pl = p.size();
    vector<int> x(m);
    for (int i = 0; i < m; ++i) {
        cin >> x[i];
        --x[i];
    }
    x.push_back(INF);

    // Fill data
    int li = -INF;
    int nx{ 0 };
    for (int i = 0; i < n; ++i) {
        if (i == x[nx]) {
            li = x[nx];
            ++nx;
        }
        if (li + pl > i) {
            s[i] = p[i - li];
        }
    }

    // Check
    string ns = p + "," + s;
    vector<int> pr{ Prefix(ns) };
    //cout << ns << endl;
    for (int i = 0; i < x.size() - 1; ++i) {
        //cout << pl + 1 + cx + pl - 1 << endl;
        if (pr[pl + 1 + x[i] + pl - 1] != pl) {
            cout << "0\n";
            return;
        }
    }

    // Ans
    int cz{ 0 };
    for (char c : s) {
        if (c == '.') {
            ++cz;
        }
    }
    cout << ToDeg(26, cz) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL

    int t = 1;
    //cin >> t;
    for (int q = 0; q < t; ++q) {
        Solve();
    }

    return 0;
}