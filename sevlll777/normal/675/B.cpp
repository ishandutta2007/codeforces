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
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int f = c - b, g = d - a;
    int ans = 0;
    for (int x1 = 1; x1 <= n; x1++) {
        int x2 = x1 - f;
        int x5 = x2 - g;
        int x4 = x5 + f;
        int xx1 = x4 + g;
        if (xx1 == x1 && min({x2, x4, x5}) >= 1 && max({x2, x4, x5}) <= n) ans += n;
    }
    cout << ans << '\n';
}