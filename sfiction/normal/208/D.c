/*
ID: Sfiction
OJ: CF130 Div2
PROB: D
*/
#include <stdio.h>
int main()
{
    long long s,a[50],b[5],c[5];
    int N,i,j;
    scanf("%d",&N);
    for (i=0;i<N;++i) scanf("%I64d",&a[i]);
    for (j=0;j<5;j++)
    {
        scanf("%I64d",&b[j]);
        c[j]=0;
    }
    s=0;
    for (i=0;i<N;++i)
    {
        s+=a[i];
        for (j=4;j>=0;--j)
        {
            c[j]+=s/b[j];
            s-=(s/b[j])*b[j];
        }
    }
    printf("%I64d %I64d %I64d %I64d %I64d\n%I64d",c[0],c[1],c[2],c[3],c[4],s);
    return 0;
}