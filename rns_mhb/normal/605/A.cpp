#include <bits/stdc++.h>
using namespace std;
#define N 100100
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

int n, ans, p, num[N], dp[N];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &p); num[p] = i;
        if (!num[p-1]) dp[i] = 1;
        else dp[i] = dp[num[p-1]] + 1;
        chkmax(ans, dp[i]);
    }
    printf("%d\n", n - ans);

    return 0;
}