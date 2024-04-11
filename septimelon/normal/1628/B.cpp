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

int c_to_n(char c) {
    return c - 'a';
}

int cc_to_n(char c1, char c2) {
    return (c_to_n(c1) + 1) * ('z' - 'a' + 1) + c_to_n(c2);
}

vector<vector<int>> en_with2(cc_to_n('z', 'z') + 1);

void ClearEN(int n, vector<string>& s) {
    for (int i = 0; i < n; ++i) {
        if (s[i].size() > 1) {
            en_with2[cc_to_n(s[i].back(), s[i][s[i].size() - 2])].clear();
        }
    }
}

bool IsGood(int n, vector<string>& s) {
    for (int i = 0; i < n; ++i) {
        if (s[i].size() > 1) {
            en_with2[cc_to_n(s[i].back(), s[i][s[i].size() - 2])].push_back(i);
        }
    }

    set<string> expl_l;

    for (int lpos = 0; lpos < n; ++lpos) {
        string cs = s[lpos];
        if (expl_l.count(cs) > 0) {
            continue;
        }
        expl_l.insert(cs);
        if (cs.size() == 1) {
            return true;
        }
        else if (cs.size() == 2) {
            if (cs[0] == cs[1]) {
                return true;
            }
            if (!en_with2[cc_to_n(cs[0], cs[1])].empty()) {
                int lr = en_with2[cc_to_n(cs[0], cs[1])].back();
                if (lr > lpos) {
                    return true;
                }
            }
        }
        else if (cs.size() == 3) {
            if (cs[0] == cs[2]) {
                return true;
            }
            int eni = cc_to_n(cs[0], cs[1]);
            for (int j = en_with2[eni].size() - 1; j >= 0 && en_with2[eni][j] > lpos; --j) {
                int rpos = en_with2[eni][j];
                if (s[rpos].size() == 2 || s[rpos][0] == cs[2]) {
                    return true;
                }
            }
        }
    }

    return false;
}

void Solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    if (IsGood(n, s)) {
        ClearEN(n, s);
        cout << "YES\n";
        return;
    }
    ClearEN(n, s);
    cout << "NO\n";
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
    for (vector<int>& v : en_with2) {
        v.clear();
    }
    for (int q = 0; q < t; ++q) {
        Solve();
    }

    return 0;
}