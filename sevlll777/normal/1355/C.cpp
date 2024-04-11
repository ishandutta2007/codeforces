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

using namespace std;
#define pb push_back
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    for (int x = a; x <= b; x++) {
        int x1 = b, y1 = c;
        int x2 = c - x + 1, y2 = d - x + 1;
        if (x1 < x2) {
            x1 = x2;
        }
        if (y1 > y2) {
            ans += (y1 - max(x1-1, y2)) * (y2 - x2 + 1);
            y1 = y2;
        }
        if (y1 >= x1 && y2 >= x2) {
            ans += y1 * (y1 + 1) / 2;
            ans -= (x1 - 1) * x1 / 2;
            ans -= x2 * (y1 - x1 + 1);
            ans += (y1 - x1 + 1);
        }
    }
    cout << ans;

}