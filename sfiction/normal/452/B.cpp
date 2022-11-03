/*
ID: Sfiction
OJ: CF
PROB: 452B
*/
#include <cstdio>
#include <cmath>

int main(){
    int n,m;
    double t1,t2;

    scanf("%d%d",&n,&m);
    if (n==0)
        printf("%d %d\n%d %d\n%d %d\n%d %d",0,1,0,m,0,0,0,m-1);
    else
        if (m==0)
            printf("%d %d\n%d %d\n%d %d\n%d %d",1,0,n,0,0,0,n-1,0);
        else
            if (n>=m){
                t1=sqrt((double)(n*n+m*m))+(double)n;
                t2=(double)2*sqrt((double)((m-1)*(m-1)+n*n));
                if (t1>t2)
                    printf("%d %d\n%d %d\n%d %d\n%d %d",0,0,n,m,0,m,n,0);
                else
                    printf("%d %d\n%d %d\n%d %d\n%d %d",n,m-1,0,0,n,m,0,1);
            }
            else{
                t1=sqrt((double)(n*n+m*m))+(double)m;
                t2=(double)2*sqrt((double)((n-1)*(n-1)+m*m));
                if (t1>t2)
                    printf("%d %d\n%d %d\n%d %d\n%d %d",0,0,n,m,n,0,0,m);
                else
                    printf("%d %d\n%d %d\n%d %d\n%d %d",n-1,m,0,0,n,m,1,0);
            }
    return 0;
}