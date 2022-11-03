/*
ID: Sfiction
OJ: CF
PROB: 334A
*/
#include <cstdio>
int main()
{
    int i,j,m,n,t;
    scanf("%d",&n);
    t=n/2;
    m=n*n;
    for (i=0;i<n;++i)
    {
        if (i) printf("\n");
        printf("%d",i*t+1);
        for (j=i*t+2;j<=(i+1)*t;++j) printf(" %d",j);
        for (j=m-i*t;j>m-(i+1)*t;--j) printf(" %d",j);
    }
    return 0;
}