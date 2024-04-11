#include <bits/stdc++.h>
using namespace std;
#define N 2020
#define inf 1000000007
#define eps 1e-7
#define pi acos(-1)
#define gc getchar
#define pc putchar
#define pb push_back

typedef pair <int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, t[N], c[N];
ll dp[N];

int main() {
    //freopen("1.in", "r", stdin);
//    freopen("11.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d %d", &t[i], &c[i]);
    memset(dp, 1, sizeof dp); dp[0] = 0;
    for (int i = 0; i < n; i ++)
        for (int j = n - 1; j >= 0; j --)
            chkmin(dp[min(j + 1 + t[i], n)], dp[j] + c[i]);
    printf("%I64d\n", dp[n]);

    return 0;
}