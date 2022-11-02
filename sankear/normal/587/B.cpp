#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <complex>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define len(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#define cerr if (0) cerr
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define next _next
#define prev _prev
#define link _link
#define rank _rank
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(1e6) + 100;
const int MOD = int(1e9) + 7;

int dp[N], ndp[N], a[N];
pii b[N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    ll l;
    cin >> n >> l >> k;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        b[i] = mp(a[i], i);
    }
    sort(b, b + n);
    if ((l + n - 1) / n < k) {
        k = (int) ((l + n - 1) / n);
    }
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            ndp[j] = 0;
        }
        if (i == 0) {
            for (int j = 0; j < n && 1LL * i * n + j < l; ++j) {
                ndp[j] = 1;
            }
        } else {
            int j = 0, cur = 0;
            while (j < n) {
                int z = j;
                while (z + 1 < n && b[j].fs == b[z + 1].fs) {
                    ++z;
                }
                for (int x = j; x <= z; ++x) {
                    cur += dp[b[x].sc];
                    if (cur >= MOD) {
                        cur -= MOD;
                    }
                }
                for (int x = j; x <= z; ++x) {
                    if (1LL * i * n + b[x].sc < l) {
                        ndp[b[x].sc] = cur;
                        if (ndp[b[x].sc] >= MOD) {
                            ndp[b[x].sc] -= MOD;
                        }
                    }
                }
                j = z + 1;
            }
        }
        for (int j = 0; j < n; ++j) {
            dp[j] = ndp[j];
            int mul = (l / n) % MOD;
            if (j < l % n) {
                mul = (mul + 1) % MOD;
            }
            mul = (mul - (i + 1) + 1 + MOD) % MOD;
            ans = (ans + 1LL *  dp[j] * mul) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}