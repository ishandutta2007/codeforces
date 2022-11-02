#include <bits/stdc++.h>
using namespace std;
#define N 4444
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

int n, com[N][N], f[N], pw[N];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i <= n; i ++) {
        com[i][0] = 1;
        for (int j = 1; j <= i; j ++)
            com[i][j] = (com[i-1][j-1] + com[i-1][j]) % inf;
    }
    f[0] = pw[0] = 1;
    for (int i = 1; i <= n; i ++) pw[i] = 2 * pw[i-1] % inf;
    for (int i = 2; i <= n; i ++) {
        for (int j = 0; j < i - 1; j ++) f[i] = (f[i] + 1ll * com[i-1][j] * f[j]) % inf;
    }
    int ans = 0;
    for (int i = 0; i < n; i ++) ans = (ans + 1ll * (pw[n-i] - 1) * com[n][i] % inf * f[i]) % inf;
    printf("%d\n", ans);


    return 0;
}