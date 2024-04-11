#include <bits/stdc++.h>
using namespace std;
#define N 33
#define K 55
#define gc getchar
#define pc putchar
#define pb push_back
#define X first
#define Y second
#define Mod(x) (((x) % mod + mod) % mod)
#define all(x) x.begin(), x.end()

const int inf = 1e9 + 7;
const double eps = 1e-7;
const double pi = 3.14159265358979323846264338327950288L;

typedef pair <int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int t, n, m, k, dp[N][N][K];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    memset(dp, 1, sizeof dp);
    for (n = 1; n < N; n ++) {
        for (m = 1; m < N; m ++) {
            dp[n][m][0] = 0;
            for (k = 1; k < K; k ++) {
                if (k >= m * n) break;
                for (int kk = 0; kk <= k; kk ++) {
                    for (int i = 1; i <= n - 1; i ++) chkmin(dp[n][m][k], m * m + dp[i][m][kk] + dp[n-i][m][k-kk]);
                    for (int i = 1; i <= m - 1; i ++) chkmin(dp[n][m][k], n * n + dp[n][i][kk] + dp[n][m-i][k-kk]);
                }
            }
            if (k < K) dp[n][m][k] = 0;
        }
    }
    scanf("%d", &t);
    while (t --) {
        scanf("%d %d %d", &n, &m, &k);
        printf("%d\n", dp[n][m][k]);
    }

    return 0;
}