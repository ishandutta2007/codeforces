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

vector<int> CalcLCP(vector<int> vals, int maxv) {
    int n = vals.size();
    int alph = maxv + 1;

    // phase 0
    vector<int> p(n, 0), cnt(alph, 0);
    vector<vector<int>> c(25, vector<int>(n));

    for (int i = 0; i < n; ++i)
        ++cnt[vals[i]];

    for (int i = 1; i < alph; ++i)
        cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; ++i)
        p[--cnt[vals[i]]] = i;

    c[0][p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; ++i) {
        if (vals[p[i]] != vals[p[i - 1]])  ++classes;
        c[0][p[i]] = classes - 1;
    }

    // phase 1
    vector<int> pn(n), cn(n);
    int log_n{ 0 };
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; ++i) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)  pn[i] += n;
        }
        cnt.assign(classes, 0);
        for (int i = 0; i < n; ++i)
            ++cnt[c[h][pn[i]]];
        for (int i = 1; i < classes; ++i)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i)
            p[--cnt[c[h][pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; ++i) {
            int mid1 = (p[i] + (1 << h)) % n, mid2 = (p[i - 1] + (1 << h)) % n;
            if (c[h][p[i]] != c[h][p[i - 1]] || c[h][mid1] != c[h][mid2])
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c[h + 1] = cn;
        log_n = h + 1;
    }

    // lcp
    vector<int> lcp(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        lcp[i] = 0;
        int ci{ p[i] }, cj{ p[i + 1] };
        for (int k = log_n; k >= 0; --k) {
            if (c[k][ci] == c[k][cj]) {
                lcp[i] += (1 << k);
                ci += (1 << k);
                while (ci >= n) {
                    ci -= n;
                }
                cj += (1 << k);
                while (cj >= n) {
                    cj -= n;
                }
            }
        }
    }

    return lcp;
}

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> hto(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (a > b) {
            swap(a, b);
        }
        hto[a].push_back(b - a);
        hto[b].push_back(n + a - b);
    }

    int fi{ 0 };
    while (hto[fi].empty()) {
        hto.emplace_back();
        ++fi;
    }

    vector<int> val;
    int last = -1;
    for (int i = 0; i < n; ++i) {
        int ci = fi + i;
        if (hto[ci].empty()) {
            continue;
        }
        sort(hto[ci].begin(), hto[ci].end());
        for (int del : hto[ci]) {
            if (last >= 0) {
                val.push_back((i - last) * 2);
            }
            last = i;
            val.push_back(del * 2 + 1);
        }
    }
    val.push_back((n - last) * 2);

    vector<int> lcp = CalcLCP(val, 200010);
    for (int clcp : lcp) {
        if (clcp >= val.size()) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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