#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 2101;
const int N = 111;
int a[N], b[N];
int color[M][M], w[M][M];
int vis[M];
ll val[M];
ll W[N][N][M];
int sto[M];
bool on[M];
int K;

void update(int x, int y, int sign, ll &ans) {
    for(int i = 1; i <= K; i ++) {
        if(on[i]) {
            ans += W[x][y][i] * sign;
        }
    }
}

int main() {
    ///freopen("EE.in", "r", stdin);
    int n, m;
    scanf("%d %d %d", &n, &m, &K);
    for(int i = 1; i <= K; i ++) {
        int l;
        scanf("%d", &l);
        for(int j = 0; j < l; j ++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            color[x][y] = i;
            w[x][y] = z;
        }
    }
    int nn = min(20, n), mm = min(20, m);
    int num1 = 0, num2 = 0;
    for(int i = 1; i <= n; i ++) if(i % nn == 0 || i == n) a[++num1] = i; a[num1 + 1] = 10000;
    for(int i = 1; i <= m; i ++) if(i % mm == 0 || i == m) b[++num2] = i; b[num2 + 1] = 10000;
    int TT = 0;
    for(int i = 1; i <= num1; i ++) {
        for(int j = 1; j <= num2; j ++) {
            for(int k = 1; k <= K; k ++) W[i][j][k] = 0;
            for(int k = a[i-1] + 1; k <= a[i]; k ++) {
                for(int r = b[j-1] + 1; r <= b[j]; r ++) {
                    W[i][j][color[k][r]] += w[k][r];
                }
            }
        }
    }
    for(int i = 1; i <= num1; i ++) {
        for(int j = 1; j <= num2; j ++) {
            for(int k = 1; k <= K; k ++) {
                W[i][j][k] = W[i][j][k] - W[i-1][j-1][k] + W[i][j-1][k] + W[i-1][j][k];
            }
        }
    }
    for(int i = 1; i <= K; i ++) on[i] = 1;
    int Q;
    scanf("%d", &Q);
    while(Q --) {
        char s[101];
        scanf("%s", s);
        if(s[0] == 'S') {
            int x;
            scanf("%d", &x);
            on[x] = 1 - on[x];
        }
        else {
            int x, y, xx, yy;
            scanf("%d %d %d %d", &x, &y, &xx, &yy);
            if(xx - x < nn * 2 || yy - y < mm * 2) {
                ll ans = 0;
                for(int i = x; i <= xx; i ++) {
                    for(int j = y; j <= yy; j ++) {
                        if(on[color[i][j]]) ans += w[i][j];
                    }
                }
                printf("%I64d\n", ans);
            }
            else {
                int X = lower_bound(a, a + num1 + 1, x - 1) - a + 1;
                int Y = lower_bound(b, b + num2 + 1, y - 1) - b + 1;
                int XX = upper_bound(a, a + num1 + 1, xx) - a - 1;
                int YY = upper_bound(b, b + num2 + 1, yy) - b - 1;
                long long ans = 0;
                update(XX, YY, 1, ans);
                update(X - 1, Y - 1, 1, ans);
                update(XX, Y - 1, -1, ans);
                update(X - 1, YY, -1, ans);
                for(int i = x; i <= a[X - 1]; i ++) for(int j = y; j <= yy; j ++) ans += on[color[i][j]] * w[i][j];
                for(int i = a[XX] + 1; i <= xx; i ++) for(int j = y; j <= yy; j ++) ans += on[color[i][j]] * w[i][j];
                for(int i = a[X-1] + 1; i <= a[XX]; i ++) for(int j = y; j <= b[Y-1]; j ++) ans += on[color[i][j]] * w[i][j];
                for(int i = a[X-1] + 1; i <= a[XX]; i ++) for(int j = b[YY] + 1; j <= yy; j ++) ans += on[color[i][j]] * w[i][j];
                printf("%I64d\n", ans);
            }
        }
    }
}