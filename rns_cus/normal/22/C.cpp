//yunpok_C
#include<bits/stdc++.h>
using namespace std;
#define N 111111
bool vis[N];
int p[N];
int main(){
   // freopen("C.in","r",stdin);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int l = -1, r = -1;
    if(m < n - 1) {puts("-1");return 0;}
    for(int i = 1; i < n - 1; i ++) {
        int x = i, y = n - 1 - x;
        if(x * (x+1) / 2 + y * (y+1) / 2 < m) continue;
        l = x, r = y;
    }
    if(l == -1) {
        if(n == 2 && m == 1) {
            printf("%d %d\n", 1, 2);
        }
        else {
            puts("-1");
        }
    }
    else {
        vis[k] = 1;
        int cnt = 0;
        int CNT = 0;
        for(int i = 1; i <= n; i ++) if(!vis[i] && cnt < l) vis[i] = 1, p[cnt ++] = i;
        p[cnt ++] = k;
        for(int i = 0; i < cnt - 1; i ++) {
            printf("%d %d\n", p[i], p[i + 1]);
            CNT ++;
        }
        bool fg = 0;
        int M = min(l * (l + 1) / 2, m - r);
        for(int i = 0; i < cnt; i ++) {
            for(int j = i + 2; j < cnt; j ++) {
                if(CNT >= M) {fg = 1;break;}
                printf("%d %d\n", p[i], p[j]);
                CNT ++;
            }
            if(fg) break;
        }
        cnt = 0;
        p[cnt ++] = k;
        for(int i = 1; i <= n; i ++) if(!vis[i]) p[cnt ++] = i;
        for(int i = 0; i < cnt - 1; i ++) {
            printf("%d %d\n", p[i], p[i + 1]);
            CNT ++;
        }
        fg = 0;
        for(int i = 0; i < cnt; i ++) {
            for(int j = i + 2; j < cnt; j ++){
                if(CNT >= m)  {fg = 1; break;}
                CNT ++;
                printf("%d %d\n", p[i], p[j]);
            }
            if(fg) break;
        }
    }
}