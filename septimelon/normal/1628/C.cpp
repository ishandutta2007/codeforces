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

int GetXor(int n, vector<vector<int>>& a) {
    int x{ 0 };
    int cx = 0, cy = 0;
    while (cy < n) {
        if (cx < n - 1) {
            ++cx;
        }
        else {
            ++cy;
        }
        if (((cx + cy) & 3) == 2) {
            for (int nx = cx, ny = cy; nx >= 0 && ny < n; nx -= 2, ny += 2) {
                //cout << nx << " " << ny << "\n";
                x ^= a[nx][ny];
            }
        }
    }
    return x;
}

void Solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (vector<int>& v : a) {
        for (int& i : v) {
            cin >> i;
        }
    }

    int x{ 0 };
    x ^= GetXor(n, a);
    for (vector<int>& v : a) {
        reverse(v.begin(), v.end());
    }
    x ^= GetXor(n, a);
    cout << x << "\n";
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