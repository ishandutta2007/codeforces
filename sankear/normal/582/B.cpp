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

const int inf = 1e9 + 100;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 303;

int a[N];
int dp[N][N], ans[N][N], tmp[N][N];

inline void mult(int a[N][N], int b[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            tmp[i][j] = -inf;
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            for (int z = i; z <= j; ++z) {
                tmp[i][j] = max(tmp[i][j], a[i][z] + b[z][j]);
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = tmp[i][j];
        }
    }
}

inline void calc(int n) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i <= j) {
                ans[i][j] = 0;
            } else {
                ans[i][j] = -inf;
            }
        }
    }
    while (n > 0) {
        if (n % 2 != 0) {
            mult(ans, dp);
        }
        mult(dp, dp);
        n /= 2;
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j] = -inf;
        }
    }
    for (int i = 0; i < N; ++i) {
        dp[i][i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int z = a[i]; z >= j; --z) {
                dp[j][a[i]] = max(dp[j][a[i]], dp[j][z] + 1);
            }
        }
    }
    for (int i = N - 1; i >= 0; --i) {
        for (int j = i; j < N; ++j) {
            if (i > 0) {
                dp[i - 1][j] = max(dp[i - 1][j], dp[i][j]);
            }
            if (j + 1 < N) {
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
            }
        }
    }
    calc(t);
    int res = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            res = max(res, ans[i][j]);
        }
    }
    cout << res << endl;
    return 0;
}