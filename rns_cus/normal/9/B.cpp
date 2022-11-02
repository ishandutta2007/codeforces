// _
#include<stdio.h>
#include<math.h>
#define ep 1e-6
int x[111];
int main(){
    int n, a, b;
    int xx, yy;
    while(scanf("%d%d%d", &n, &a, &b) ==3){
        for(int i = 1; i <= n; i ++)scanf("%d", &x[i]);
        scanf("%d%d", &xx, &yy);
        int po = -1;
        double ans = 1000000000.;
        for(int i = 2; i <= n; i ++){
            double dis = 1. * x[i] / a;
            int dx = xx - x[i], dy = yy ;
            dis += 1. *sqrt(1ll * dx * dx + 1ll * dy * dy) / b;
            if(ans + ep > dis)ans = dis, po = i;
        }
        printf("%d\n", po);
    }
    return 0;

}