#include <bits/stdc++.h>
using namespace std;
#define M 300001

int p[M], l[M];
int f[20][M], g[20][M], cost[20][M], mx[20][M], Rit[20][M],  q[M];

int n;

int calc(int x, int y) {
    int res = 1, cur = 0;
    while(res <= y - x + 1) res *= 2, cur ++;
    cur --, res/= 2;
    return max(f[cur][x], f[cur][y - res + 1]);
}

int CALC(int x, int y) {
    if(x > y) return 0;
    if(g[0][x] >= y) return 0;
    int st = 0;
    while(g[st][x] < y) st ++;
    st --;
    return CALC(g[st][x] + 1, y) + cost[st][x] + (p[g[st][x] + 1]) - Rit[st][x];
}

int rmq(int x, int y) {
    int res = 1, cur = 0;
    while(res <= y - x + 1) res *= 2, cur ++;
    cur --, res/= 2;
    return max(mx[cur][x], mx[cur][y - res + 1]);
}

int main() {
    ///freopen("E.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d %d", &p[i], &l[i]);
    for(int i = 0; i < n; i ++) q[i] = p[i] + l[i];
    for(int i = 0; i < n; i ++) mx[0][i] = q[i];
    for(int i = 1; i < 20; i ++) {
        for(int j = 0; j < n; j ++) {
            int k = j + (1 << (i - 1));
            if(k >= n) continue;
            mx[i][j] = max(mx[i-1][j], mx[i-1][k]);
        }
    }
    for(int i = n - 1; i >= 0; i --) {
        int x = p[i] + l[i];
        int y = upper_bound(p , p + n , x) - p ;
        y --;
        if(y == i) f[0][i] = i;
        else f[0][i] = calc(i + 1, y);
        for(int j = 1; j <= 20; j ++) {
            int k = i + (1ll << (j - 1));
            if(k >= n) continue;
            f[j][i] = max(f[j-1][i], f[j-1][k]);
        }
    }
    for(int i = 0; i < n; i ++) g[0][i] = f[0][i], Rit[0][i] = rmq(i, f[0][i]), cost[0][i] = 0;
    for(int i = 1; i < 20; i ++) {
        for(int j = 0; j < n; j ++) {
            int x = g[i-1][j];
            x ++;
            if(x >= n) {
                g[i][j] = n;
                Rit[i][j] = Rit[i-1][j];
                cost[i][j] = cost[i-1][j];
                continue;
            }
            g[i][j] = g[i-1][x];
            Rit[i][j] = Rit[i-1][x];
            cost[i][j] = cost[i-1][j] + (p[x] - Rit[i-1][j]) + cost[i-1][x];
        }
    }
    int q;
    scanf("%d", &q);
    while(q --) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y --;
        printf("%d\n", CALC(x, y));
    }
}