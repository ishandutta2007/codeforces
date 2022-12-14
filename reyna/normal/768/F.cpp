// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 1e9 + 7;
int pw(int a, int b) { return b != 0? pw(a * a % mod, b >> 1) * (b & 1? a: 1) % mod: 1; }
int f[N], inv[N];
void sadd(int &x, int y) {
    x += y;
    x %= mod;
}
int mul(int x, int y) { return x * y % mod; }
int comb(int n, int r) {
    if (n == r) return 1;
    if (n < 0 || r < 0 || n - r < 0) return 0;
    return f[n] * inv[r] % mod * inv[n - r] % mod;
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    f[0] = inv[0] = 1;
    for (int j = 1; j < N; ++j)
        f[j] = f[j - 1] * j % mod, inv[j] = pw(f[j], mod - 2);
    int f, w, h;
    cin >> f >> w >> h;
    int all = 0, ans = 0;
    for (int st = 0; st < 2; ++st) {
        for (int sz = 1; sz <= f + w; ++sz) {
            int fs = sz / 2, ws = sz / 2;
            if (sz % 2 == 1) {
                if (st == 0) fs++;
                else ws++;
            }
            if (!f && fs) continue;
            if (!w && ws) continue;
            if (f && !fs) continue;
            if (w && !ws) continue;
            int ways = comb(f - 1, fs - 1);
            sadd(all, mul(ways, comb(w - 1, ws - 1)));
            sadd(ans, mul(ways, comb(w - 1 - h * ws, ws - 1)));
         //   cout << st << ' ' << sz << ' ' << fs << ' ' << ws << ' ' << ways << ' ' << comb(w - 1, ws - 1) << ' ' << comb(w - 1 - h * ws, ws - 1) << endl;
        }
    }
    cout << ans * pw(all, mod - 2) % mod;
}