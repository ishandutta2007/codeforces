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

void Solve() {
    string s, srev;
    cin >> s;
    srev = s;
    reverse(s.begin(), s.end());
    int n = s.size();
    
    string ss = s + string(1, 'z' + 1) + srev;
    
    vector<int> pr{ Prefix(ss) };
    int maxpr{ 0 };
    for (int i = n + 1; i < n * 2 + 1; ++i) {
        if (i - pr[i] == n) {
            maxpr = pr[i];
        }
        else {
            break;
        }
    }
    if (maxpr * 2 + 1 >= n) {
        cout << s << "\n";
        return;
    }

    string short_s = s.substr(maxpr, n - maxpr * 2);
    string short_srev{ short_s };
    reverse(short_srev.begin(), short_srev.end());

    ss = short_s + string(1, 'z' + 1) + short_srev;
    pr = Prefix(ss);
    int maxl = pr.back();

    ss = short_srev + string(1, 'z' + 1) + short_s;
    pr = Prefix(ss);
    int maxr = pr.back();

    string ans;
    if (maxl >= maxr) {
        ans = s.substr(0, maxpr) + short_s.substr(0, maxl) + s.substr(n - maxpr, maxpr);
    } else {
        ans = s.substr(0, maxpr) + short_srev.substr(0, maxr) + s.substr(n - maxpr, maxpr);
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        Solve();
    }

    return 0;
}