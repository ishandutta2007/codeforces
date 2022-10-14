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
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int c = n - 1;
    int ans = 0;
    int sx = 0, sxx = 0, sy = 0, syy = 0;
    while (n--) {
        int x, y;
        cin >> x >> y;
        sx += x;
        sy += y;
        sxx += x * x;
        syy += y * y;
        ans += x * x * c;
        ans += y * y * c;
    }
    ans -= sx * sx - sxx;
    ans -= sy * sy - syy;
    cout << ans << '\n';
}