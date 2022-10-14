#pragma GCC optimize("Ofast,fast-math,unroll-loops,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
#define pii pair<int, int>
#define int long long
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, h1, a1, x1, y1, h2, a2, x2, y2;
    cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;

    int w1 = 0;
    while (h1 != a1) {
        h1 = (h1 * x1 + y1) % m;
        w1++;
        if (w1 > m + m) {
            cout << -1;
            exit(0);
        }
    }

    int w2 = 0;
    int hh2 = h2;
    while (hh2 != a2) {
        hh2 = (hh2 * x2 + y2) % m;
        w2++;
        if (w2 > m + m) {
            cout << -1;
            exit(0);
        }
    }

    if (w1 == w2) {
        cout << w1;
        exit(0);
    }

    int c1 = 1;
    h1 = (a1 * x1 + y1) % m;
    while (h1 != a1) {
        h1 = (h1 * x1 + y1) % m;
        c1++;
        if (c1 > m + m) {
            cout << -1;
            exit(0);
        }
    }

    int cc1 = c1;
    int c2 = 0, xx2 = 1, yy2 = 0;
    while (cc1--) {
        xx2 = (xx2 * x2) % m;
        yy2 = (yy2 * x2 + y2) % m;
    }

    int ww1 = w1;
    while (ww1--) {
        h2 = (h2 * x2 + y2) % m;
    }

    while (h2 != a2) {
        h2 = (h2 * xx2 + yy2) % m;
        c2++;
        if (c2 > m + m) {
            cout << -1;
            exit(0);
        }
    }

    cout << w1 + c1 * c2;
}