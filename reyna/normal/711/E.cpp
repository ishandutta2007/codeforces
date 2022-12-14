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

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
#define int long long
const int N = 0, mod = (int) 1e6 + 3;
int pw(int a, int b) { return b != 0? pw(a * a % mod, b >> 1) * (b & 1? a: 1) % mod: 1; }
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    if (n < 62 && (1LL << n) < k) {
        cout << 1 << ' ' << 1;
        return 0;
    }
    int cnt = 0;
    cnt += n; cnt %= mod - 1;
    for (int j = 1; j < 62; ++j)
        cnt += ((k - 1) / (1ll << j)), cnt %= mod - 1;
    int s = pw(2, n % (mod - 1) * (k % (mod - 1)) % (mod - 1)) * pw(pw(2, mod - 2), cnt) % mod;
    if (k > 2 * mod) {
        cout << s << ' ' << s;
        return 0;
    }
    long long res = 1;
    for (int i = 0; i < k; ++i) {
        res = res * 1ll * ((pw(2, n) - (i % mod) + 3 * mod) % mod) % mod;
    }
    int g = pw(pw(2, mod - 2), cnt);
    cout << (s - (res * g % mod) + mod) % mod << ' ' << s % mod;



}