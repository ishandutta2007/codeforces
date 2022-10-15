#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <utility>
#include <stdint.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <queue>
#include <deque>
#include <bitset>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))
#define dbg(a)        cerr << #a << " = " << (a) << '\n'
#define dbg2(a, b)    cerr << #a << " = " << (a) << " " << #b << " = " << (b) << '\n'
#define dbg3(a, b, c) cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << '\n'

using std::cin;
using std::cout;
using std::cerr;

using std::pair;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::unordered_set;
using std::queue;
using std::deque;
using std::bitset;

using std::max;
using std::min;
using std::abs;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void init() {
    std::iostream::sync_with_stdio(0);
    srand(time(NULL));
    cout << std::fixed;
    cout.precision(10);
    cerr << std::fixed;
    cerr.precision(10);
}

const int MAXN = 5e3 + 5;
const ll P = 13, Q = 1e9 + 9, MOD = 1e9 + 7;

char arr[MAXN];
ll pw[MAXN], dp[MAXN][MAXN], pref[MAXN][MAXN], hs[MAXN];

ll get(int l, int r) {
    return (hs[r] - hs[l - 1] + Q) % Q;
}

bool eq(int a, int b, int c, int d) {
    if (a > c) {
        std::swap(a, c);
        std::swap(b, d);
    }
    return get(c, d) == (get(a, b) * pw[c - a]) % Q;
}

bool more(int a, int b, int len) {
    if (eq(a, a + len - 1, b, b + len - 1))
        return false;
    if (arr[a] != arr[b])
        return arr[a] > arr[b];
    int l = -1, r = len;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (eq(a, a + m, b, b + m))
            l = m;
        else
            r = m;
    }
    // dbg(r);
    return arr[a + r] > arr[b + r];
}

int main()
{
    init();

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    
    pw[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        pw[i] = (pw[i - 1] * P) % Q;

    hs[0] = 0;
    for (int i = 1; i <= n; ++i)
        hs[i] = (hs[i - 1] + pw[i] * (arr[i] - '0' + 1)) % Q;

    for (int i = 1; i <= n; ++i) {
        for (int len = 1; len < i; ++len) {
            int st = i - len + 1;
            if (arr[st] == '0')
                continue;
            dp[i][len] = pref[st - 1][len - 1];
            if (st > len && more(st, st - len, len)) {
                dp[i][len] += dp[st - 1][len];
                dp[i][len] %= MOD;
            }
        }
        dp[i][i] = 1;
        for (int len = 1; len <= i; ++len)
            pref[i][len] = (pref[i][len - 1] + dp[i][len]) % MOD;
        for (int len = i + 1; len <= n; ++len)
            pref[i][len] = pref[i][i];
    }
/*
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j)
            cerr << pref[i][j] << ' ';
        cerr << '\n';
    }*/

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dp[n][i];
        ans %= MOD;
    }

    cout << ans << '\n';

    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}