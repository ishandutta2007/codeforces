#include<stdio.h>
#define N 111111
int n, xx, yy;
long long id;
int x[N], y[N], px[N], py[N];
int main(){
   // freopen("C.in","r",stdin);
    scanf("%d%I64d", &n, &id);
    scanf("%d%d", &xx, &yy);
    if(id == 0) {printf("%d %d\n", xx, yy); return 0;}
    id --;
    for(int i = 0; i < n; i ++) scanf("%d%d", &x[i], &y[i]);
    for(int i = n - 1; i >= 0; i --) {
        if(i % 2 == 0) px[i] = px[i+1] + 2 * x[i], py[i] = py[i+1] + 2 * y[i];
        else px[i] = px[i+1] - 2 * x[i], py[i] = py[i+1] - 2 * y[i];
    }
    id = id % (2 * n);
    if(id >= n) {
        int ansx = px[id-n+1], ansy = py[id-n+1];
        if(id & 1) ansx = -ansx + xx, ansy = -ansy + yy;
        else ansx = ansx - xx, ansy = ansy - yy;
        printf("%d %d\n", ansx, ansy);
    }
    else {
        int ansx = px[0] - px[id + 1], ansy = py[0] - py[id + 1];
        if(id & 1) ansx = -ansx + xx, ansy = -ansy + yy;
        else ansx -= xx, ansy -= yy;
        printf("%d %d\n", ansx, ansy);
    }
}