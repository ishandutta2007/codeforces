#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <deque>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>

#define pb push_back
#define pbk pop_back
#define sz(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define mt make_tuple
#define fs first
#define sc second
#define next hunext
#define prev huprev
#define rank hurank
#define hash huhash

#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const ll linf = ll(1e18);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 1010;
const int D = 11;

int f[N];
int g[D];
int dp[D][D][N], ndp[D][D][N];
int rev[D];

inline int calc(int a, int b, int c) {
    int res = 1;
    while (b > 0) {
        if (b % 2 != 0) {
            res = (1LL * res * a) % c;
        }
        a = (1LL * a * a) % c;
        b /= 2;
    }
    return res;
}

inline void add(int& a, int b, int c) {
    if ((a += b) >= c) {
        a -= c;
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, d, mod;
    cin >> n >> d >> mod;
    if (n <= 2) {
        puts("1");
        return 0;
    }
    f[1] = 1;
    dp[0][0][0] = 1;
    for (int i = 1; i <= d; ++i) {
        rev[i] = calc(i, mod - 2, mod);
    }
    for (int l = 1; l <= n / 2; ++l) {
        for (int i = 0; i <= d; ++i) {
            for (int j = 0; j <= i; ++j) {
                for (int z = 0; z <= n; ++z) {
                    ndp[i][j][z] = 0;
                }
            }
        }
        g[0] = 1;
        for (int i = 1; i <= d; ++i) {
            g[i] = (1LL * g[i - 1] * (f[l] + i - 1)) % mod;
            g[i] = (1LL * g[i] * rev[i]) % mod;
        }
        for (int i = 0; i <= d; ++i) {
            for (int j = 0; j <= i; ++j) {
                for (int z = 0; z <= n; ++z) {
                    if (dp[i][j][z] == 0) {
                        continue;
                    }
                    add(ndp[i][0][z], (1LL * dp[i][j][z] * g[j]) % mod, mod);
                    if (z + l <= n && i + 1 <= d) {
                        add(dp[i + 1][j + 1][z + l], dp[i][j][z], mod);
                    }
                }
            }
        }
        f[l + 1] = ndp[d - 1][0][l];
        for (int i = 0; i <= d; ++i) {
            for (int j = 0; j <= i; ++j) {
                for (int z = j * l; z <= n; ++z) {
                    dp[i][j][z] = ndp[i][j][z];
                }
            }
        }
    }
    int ans = dp[d][0][n - 1];
    if (n % 2 == 0) {
        int tmp = (1LL * dp[d - 1][0][n / 2 - 1] * (dp[d - 1][0][n / 2 - 1] - 1 + mod)) % mod;
        tmp = (1LL * tmp * rev[2]) % mod;
        ans -= tmp;
        if (ans < 0) {
            ans += mod;
        }
    }
    cout << ans << endl;
    return 0;
}