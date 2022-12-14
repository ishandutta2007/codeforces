#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define ep 1e-6
#define N 1111
struct dat{
    double x, y;

}p[N];
bool cmp(dat a, dat b) {
    return a.x < b.x;
}
int main(){
    int n, t, x, a;
  //  freopen("A.in","r",stdin);
    while(scanf("%d%d", &n, &t) == 2) {
        for(int i = 0; i < n; i ++) {
            scanf("%d%d", &x, &a);
            p[i].x = 1. * x - 1. * a / 2.;
            p[i].y = 1. * x + 1. * a / 2.;
        }
        sort(p, p + n, cmp);
        int ans = 2;
        for(int i = 0; i < n - 1; i ++) {
            if(p[i+1].x - p[i].y < t) continue;
            if(p[i+1].x - p[i].y > t) ans +=2;
            if(fabs(p[i+1].x - p[i].y - t) < ep) ans ++;
        }
        printf("%d\n", ans);
    }
}