#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 100000

int a[N], n, x1, y1, x2, y2;
int r[N][2], v[N][2];

int main() {
    scanf("%d %d %d %d %d",&n,&x1,&y1,&x2,&y2);
    for(int i=0;i<n;i++)
        scanf("%d %d %d %d",&r[i][0],&r[i][1],&v[i][0],&v[i][1]);
    double lo=0.0, hi=1e18;
    for(int i=0;i<n;i++) {
        for(int j=0;j<2;j++) {
            double t1, t2;
            if(j==0) { t1=x1; t2=x2; }
            else { t1=y1; t2=y2; }
            if(v[i][j]==0) {
                if(r[i][j]<=t1 || r[i][j]>=t2) {
                    puts("-1");
                    return 0;
                } else continue;
            }
            double a=(1.0*t1-r[i][j])/v[i][j], b=(1.0*t2-r[i][j])/v[i][j];
            if(a>b) swap(a,b);
            lo=max(lo,a);
            hi=min(hi,b);
        }
    }
    if(lo>=hi) {
        puts("-1");
        return 0;
    }
    printf("%.10f\n",lo+1e-11);
    return 0;
}