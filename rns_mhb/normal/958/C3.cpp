#include <bits/stdc++.h>
using namespace std;
#define N 500010
#define K 111
#define inf 1000000000
#define eps 1e-7
#define pi acos(-1)
#define gc getchar
#define pc putchar
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, k, p, a, dp[2][K], maxi[2][K];
ll s;
bool b;

int re(int i) {return i % 2;}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d %d %d", &n, &k, &p);
    for (int i = 1; i <= n; i ++, b ^= 1) {
        scanf("%d", &a), a %= p, s += a;
        dp[b][1] = maxi[b][1] = s % p;
        if (i <= k) dp[b][i] = s, maxi[b][i] = a;
        for (int j = 2; j <= k && j < i; j ++) {
            int s1 = dp[b^1][j-1], s2 = dp[b^1][j];
            if (s1 == s2) {
                if (maxi[b^1][j] + a < p) dp[b][j] = s2 + a, maxi[b][j] = a + maxi[b^1][j];
                else dp[b][j] = s2 + a - p, maxi[b][j] = a + maxi[b^1][j] - p;
            }
            else dp[b][j] = s1 + a, maxi[b][j] = a;
        }
    }
    printf("%d\n", dp[b^1][k]);

    return 0;
}