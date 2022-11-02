#include <bits/stdc++.h>
using namespace std;
#define MAXN (1 << 20)
#define N 20
#define M 100100
typedef long long ll;
inline void chkmin(int& x, ll y) {if (x > y) x = y;}
ll f[MAXN], g[MAXN];
void fwtxor(ll x[], int r, int n) {
    int i, j, m, h; ll tmp;
    for (h = 1; m = h * 2, h < n; h = m)
        for (i = 0; i < n; i += m)
            for (j = 0; j < h; j ++)
                tmp = x[i+j] - x[i+j+h], x[i+j] = x[i+j] + x[i+j+h], x[i+j+h] = tmp;
    if (r < 0)
        for (i = 0; i < n; i ++)
            x[i] /= n;
}
void mulxorpoly(int n) {
    fwtxor(f, 1, n);
    fwtxor(g, 1, n);
    for (int i = 0; i < n; i++)
        f[i] *= g[i];
    fwtxor(f, -1, n);
}
int n, m;
char s[N][M];
int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i ++) gets(s[i]);
    for (int i = 0; i < m; i ++) {
        int x = 0;
        for (int j = 0; j < n; j ++) {
            x = 2 * x + s[j][i] - 48;
        }
        f[x] ++;
    }
    m = (1 << n);
    for (int i = 0; i < m; i ++)
        g[i] = min(__builtin_popcount(i), n - __builtin_popcount(i));
    mulxorpoly(m); n = N * M;
    for (int i = 0; i < m; i ++) chkmin(n, f[i]);
    printf("%d\n", n);
    return 0;
}