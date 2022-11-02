#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#undef NDEBUG
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define len(s) sz(s)
#define fs first
#define sc second
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
#define prev huprev
#define next hunext
#define link hulink
#define hash huhash
#define rank hurank
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef long double ldouble;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 222;
const int K = 1010;
const int MOD = int(1e9) + 7;

int n, k;
int a[N], l[N][N], r[N][N];
int dp[N][K], ndp[N][K];

inline void add(int& a, int b) {
    if ((a += b) >= MOD) {
        a -= MOD;
    }
}

inline int get(int i, int j, int z) {
    if (j < 0 || j > i || j > n - i) {
        return 0;
    }
    if (l[i][j] <= z && z <= r[i][j]) {
        return dp[j][z - l[i][j]];
    }
    return 0;
}

inline void gen() {
    freopen("input.txt", "w", stdout);
    cout << 200 << " " << 1000 << endl;
    for (int i = 0; i < 200; ++i) {
        cout << 1 + rand() % 500 << " ";
    }
    cout << endl;
    exit(0);
}

int main() {
    //gen();
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + n + 1);
    dp[0][0] = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i && j <= n - i; ++j) {
            l[i][j] = -a[i] * j;
            r[i][j] = k - a[i] * j;
            assert(r[i][j] - l[i][j] == k);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i && j <= n - i; ++j) {
            for (int z = l[i][j]; z <= r[i][j]; ++z) {
                ndp[j][z - l[i][j]] = 0;
                add(ndp[j][z - l[i][j]], (1LL * get(i - 1, j, z) * (j + 1)) % MOD);
                add(ndp[j][z - l[i][j]], (1LL * get(i - 1, j + 1, z - a[i]) * (j + 1)) % MOD);
                add(ndp[j][z - l[i][j]], get(i - 1, j - 1, z + a[i]));
            }
        }
        for (int j = 0; j <= i && j <= n - i; ++j) {
            for (int z = l[i][j]; z <= r[i][j]; ++z) {
                dp[j][z - l[i][j]] = ndp[j][z - l[i][j]];
            }
        }
    }
    int ans = 0;
    for (int i = l[n][0]; i <= r[n][0]; ++i) {
        if (i <= k) {
            //cerr << i << " " << dp[0][i - l[n][0]] << endl;
            add(ans, dp[0][i - l[n][0]]);
        }
    }
    cout << ans << endl;
    return 0;
}