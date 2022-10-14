// #define _GLIBCXX_DEBUG
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
#define int long long
#define str string
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        string ans = "Yes\n";
        if (x == x2 && x == x1 && (a > 0 || b > 0)) {
            ans = "No\n";
        }
        if ((x + (b - a) > x2) || (x + (b - a) < x1)) {
            ans = "No\n";
        }
        if (y == y2 && y == y1 && (c > 0 || d > 0)) {
            ans = "No\n";
        }
        if ((y + d - c > y2) || (y + d - c < y1)) {
            ans = "No\n";
        }
        cout << ans;

    }
}