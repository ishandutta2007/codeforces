#include<bits/stdc++.h>
#define N 1111

using namespace std;
int x[N], y[N];
bool vis[N];
struct dat{
    int x, y;
    dat(int x = 0, int y = 0) :x(x), y(y){}
}sto[N];
int main(){
   // freopen("B.in","r",stdin);
    int hh, r, n;
    scanf("%d%d%d", &n, &hh, &r);
    for(int i = 0; i < n; i ++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    int h = hh;
    bool fg = 1;
    int sum = 0;
    int T = 0;
    int cnt = 0;
    while(1) {
        int po = -1;
        int mx = 0;
        if(h <= 0) break;
       // printf("%d %d %d\n", h, sum, r);
        for(int i = 0; i < n; i ++) if(!vis[i]){
            if(h * 100 <= hh * x[i]) {
                mx = max(mx, y[i]);
                if(mx == y[i])po = i;
            }
        }
       // printf("%d\n", y[po]);
        if(po == -1 && r >= sum) { T ++, fg = 0; break;}
        if(po == -1) {
            h -= sum - r;
            T ++;
            if(h <= 0) break;
            h = min(hh, h);
            continue;
        }
        vis[po] = 1;
        sto[cnt ++] = dat(T, po + 1);
        sum += y[po];
        h -= sum - r;
        T ++;
        if(h <= 0) break;
       // h += r;
        h = min(hh, h);
    }
    if(!fg){puts("NO"); return 0;}
puts("YES");
    printf("%d %d\n" , T, cnt);
    for(int i = 0; i < cnt; i ++) {
        printf("%d %d\n", sto[i].x, sto[i].y);
    }
    return 0;
}