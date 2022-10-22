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

void Solve() {
    string s;
    cin >> s;
    int n = s.size();
    
    vector<int> pr{ Prefix(s) };
    vector<int> cnt(n + 1, 1);
    for (int i = n - 1; i > 0; --i) {
        cnt[pr[i]] += cnt[i + 1];
    }

    vector<int> len;
    for (int i = n - 1; i >= 0; i = pr[i] - 1) {
        len.push_back(i + 1);
    }
    reverse(len.begin(), len.end());

    cout << len.size() << "\n";
    for (int cl : len) {
        cout << cl << " " << cnt[cl] << "\n";
    }
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