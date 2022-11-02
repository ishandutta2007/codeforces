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

int n, ans, h[N], x[N], y[N];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d", &n); y[n+1] = n + 1;
    for (int i = 1; i <= n; i ++) scanf("%d", &h[i]);
    for (int i = 1; i <= n; i ++) x[i] = min(h[i] - i, x[i-1]);
    for (int i = n; i > 0; i --) y[i] = min(h[i] + i, y[i+1]);
    for (int i = 1; i <= n; i ++)
        chkmax(ans, min(x[i] + i, y[i] - i));
    printf("%d\n", ans);

    return 0;
}