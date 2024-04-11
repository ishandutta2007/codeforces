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

int ask(int cp) {
    cout << "? " << cp + 1 << endl;
    cin >> cp;
    return cp - 1;
}

void Solve() {
    int n;
    cin >> n;

    vector<int> p(n, -1);

    for (int cp = 0; cp < n; ++cp) {
        if (p[cp] != -1) {
            continue;
        }
        vector<int> path;
        path.push_back(ask(cp));
        int a = -1;
        while (a != path[0]) {
            a = ask(cp);
            path.push_back(a);
        }
        for (int i = 0; i < path.size() - 1; ++i) {
            p[path[i]] = path[i + 1];
        }
    }

    cout << "!";
    for (int i : p) {
        cout << " " << i + 1;
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // LOCAL

    int t = 1;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        Solve();
    }

    return 0;
}