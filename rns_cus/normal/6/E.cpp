//e
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define N 110000
#define inf 1000000000
int a[N];
int en[N];
int f[N][30], g[N][30];
int n, k;
int MIN(int st, int en){
    int log = log2(en - st +  + 0.5);
    return min(f[st][log], f[en - (1<<log) + 1][log]);
}
int MAX(int st, int en){
    int log = log2(en - st + 1 + 0.5);
    return max(g[st][log], g[en - (1<<log) + 1][log]);
}
int get_mx(int x){
    int st = x, en = n + 1;
    while(st + 1 < en){
        int mid = st + en >> 1;
        int mn = MIN(x, mid), mx = MAX(x,mid);
        if(mx - mn <= k)st = mid;
        else en = mid;
    }
    return st;
    return 0;
}
void RMQ(){
    int log = log2(n+0.5);
     for(int i = 1; i <= n; i ++)f[i][0] = g[i][0] = a[i];
     for(int i = 1; i <= log; i ++){
        for(int j = 1; j + (1<<i) - 1 <= n; j ++){
            f[j][i] = inf;
            f[j][i] = min(f[j][i-1], f[j+(1<<(i-1))][i-1]);
        }
    }
    for(int i = 1; i <= log; i ++){
        for(int j = 1; j + (1<<i) - 1 <= n; j ++){
            g[j][i] = 0;
            g[j][i] = max(g[j][i-1], g[j+(1<<(i-1))][i-1]);
        }
    }
    return ;
}
int main(){
    //freopen("E.in","r",stdin);
    while(scanf("%d%d", &n, & k) == 2){
        for(int i = 1; i <= n; i ++)scanf("%d", &a[i]);
        RMQ();
        int ans = 0;
        int m = 0;
        for(int i = 1; i <= n; i ++){
            en[i] = get_mx(i);
            if(ans == en[i] - i + 1) m ++;
            if(ans < en[i] - i + 1) m = 1, ans = en[i] - i + 1;
        }
        printf("%d %d\n", ans, m);
        for(int i = 1; i <= n; i ++)if(en[i] - i + 1 == ans)
            printf("%d %d\n", i, en[i]);
    }
    return 0;
}