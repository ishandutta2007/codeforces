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

const ll MAXF = 2000500;

//mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(643896);

double ReadDouble() {
    string s;
    cin >> s;
    return stol(s);
}

void Print(vector<int>& a, vector<int>& b) {
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " " << b[i] << "\n";
    }
}

void Solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n / 2), b(n / 2);
    for (int i = 0; i < n / 2; ++i) {
        a[i] = i;
        b[i] = n - i - 1;
    }

    if (k > 0) {
        if (k < n - 1) {
            if (k < n / 2) {
                swap(b[0], b[k]);
            }
            else {
                swap(b[0], a[n - 1 - k]);
            }
        }
        else if (n > 4) {
            swap(b[0], a[1]);
            swap(b[0], b[3]);
        }
        else {
            cout << "-1\n";
            return;
        }
    }

    Print(a, b);
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