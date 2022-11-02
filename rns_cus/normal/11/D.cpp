#include<bits/stdc++.h>
using namespace std;
#define N 19
#define clr(x) memset(x, 0, sizeof(x))
typedef __int64 ll;
bool fg[N][N];
ll f[1<<N + 1][N];
int p[N];
int main() {
    int n, m;
    //freopen("D.in","r",stdin);
    while(scanf("%d%d", &n, &m) == 2) {
        clr(f), clr(fg);
        while(m --) {
            int x, y;
            scanf("%d%d", &x, &y);
            x --, y --;
            fg[x][y] = fg[y][x] = 1;
        }
        ll ans = 0;
        for(int i = 0; i < n; i ++) f[1<<i][i] = 1;
        for(int i = 0; i < (1<<n); i ++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) if((1<<j) & i)
                p[cnt ++] = j;
            int x = p[cnt - 1];
            for(int j = 0; j < cnt - 1; j ++) {
                int y = p[j];
                int ii = i - (1<<y);
                for(int k = 0; k < n; k ++) if(k != y && ii & (1<<k) && fg[y][k])
                    f[i][y] += f[ii][k];
                if(fg[x][y] && ii > (1<<x)) ans += f[i][y];
            }
        }
        printf("%I64d\n", ans / 2);
    }
    return 0;
}