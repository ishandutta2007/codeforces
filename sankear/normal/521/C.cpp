#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <complex>

#define pb push_back
#define pbk pop_back
#define sz(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int MOD = int(1e9) + 7;
const int N = int(1e5) + 100;

char s[N];
int sum[N], f[N], rf[N], pw[N], sum_c[N], sum_c10[N];

inline int calc(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2 != 0) {
            res = (1LL * res * a) % MOD;
        }
        a = (1LL * a * a) % MOD;
        b /= 2;
    }
    return res;
}

inline int cnk(int n, int k) {
    assert(k >= 0 && k <= n);
    int res = (1LL * f[n] * rf[k]) % MOD;
    res = (1LL * res * rf[n - k]) % MOD;
    return res;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    scanf("%d %d %s", &n, &k, s);
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        f[i] = (1LL * f[i - 1] * i) % MOD;
    }
    for (int i = 0; i <= n; ++i) {
        rf[i] = calc(f[i], MOD - 2);
    }
    for (int i = 0; i < n; ++i) {
        sum[i] = ((i > 0 ? sum[i - 1] : 0) * 10LL + (s[i] - '0')) % MOD;
    }
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = (10LL * pw[i - 1]) % MOD;
    }
    int ans = 0;
    if (k >= 2) {
        for (int i = 1; i <= n - 2; ++i) {
            if (n - 2 - i < k - 2) {
                break;
            }
            sum_c[i] = ((i > 0 ? sum_c[i - 1] : 0) + cnk(n - 2 - i, k - 2)) % MOD;
            sum_c10[i] = ((i > 0 ? sum_c10[i - 1] : 0) + 1LL * cnk(n - 2 - i, k - 2) * pw[i]) % MOD;
        }
        for (int i = 0; i < n - 1; ++i) {
            int j = max(0, i - (n - k));
            ans = (ans + 1LL * sum[i] * sum_c[i - j]) % MOD;
        }
        for (int i = 0; i < n - 1; ++i) {
            int j = min(n - 2, i + (n - k));
            ans = (ans - 1LL * sum[i] * sum_c10[j - i]) % MOD;
            ans = (ans + MOD) % MOD;
        }
    }
    if (k >= 1) {
    for (int i = 0; i < n - 1; ++i) {
        if (n - 2 - i >= k - 1) {
            ans = (ans + 1LL * sum[i] * cnk(n - 2 - i, k - 1)) % MOD;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        if (i >= k - 1) {
            int val = (sum[n - 1] - 1LL * sum[i] * pw[n - 1 - i]) % MOD;
            val = (val + MOD) % MOD;
            ans = (ans + 1LL * val * cnk(i, k - 1)) % MOD;
        }
    }
    }
    if (k == 0) {
        ans = (ans + sum[n - 1]) % MOD;
    }
    cout << ans << endl;
    return 0;
}