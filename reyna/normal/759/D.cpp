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
const int N = (int) 5005, M = 1e5 + 5, mod = (int) 1e9 + 7;
int pw(int a, int b) { return b != 0? pw(a * a % mod, b >> 1) * (b & 1? a: 1) % mod: 1; }
int f[M], inv[M], dp[N][N], sum[N];
int add(int x, int y) { return (x + y) % mod; }
int sadd(int &x, int y) { return x = add(x, y); }

int comb(int n, int r) { 
    if (n < 0 ||  r< 0 || n - r < 0) return 0;
    return f[n] * inv[r] % mod * inv[n - r] % mod;
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    f[0] = inv[0] = 1;
    for (int j = 1; j < M; ++j)
        f[j] = f[j - 1] * j % mod, inv[j] = pw(f[j], mod - 2);
    int n;
    cin >> n;
    string s;
    cin >> s;
    sum[0] = 1;
    for (int j = 0; j < n; ++j) {
        int ch = s[j] - 'a';
        for (int len = n; len >= 0; --len) {
            sum[len + 1] = (sum[len + 1] - dp[len + 1][ch] + mod) % mod;
            dp[len + 1][ch] = (sum[len] - dp[len][ch] + mod) % mod;
            sadd(sum[len + 1], dp[len + 1][ch]);
        }
    }
    int res = 0;
    for (int j = 1; j <= n; ++j) {
        sadd(res, sum[j] * comb(n - 1, j - 1) % mod);
    }
    cout << res << endl;

}