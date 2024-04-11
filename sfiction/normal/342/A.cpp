/*
ID: Sfiction
OJ: CF
PROB: 342A
*/
#include <cstdio>
int a[8];
int main()
{
    int n,i,t,p;
    scanf("%d",&n);
    p=0;
    for (i=0;i<n;++i)
    {
        scanf("%d",&t);
        ++a[t];
    }
    if (n%3||a[5]||a[7]) ++p;
    if (a[4]>a[2]||a[4]>a[1]) ++p;
    else
    {
        a[2]-=a[4];
        a[1]-=a[4];
    }
    if (a[1]!=a[6]||a[1]!=a[2]+a[3]) ++p;
    if (p) printf("-1");
    else
    {
        for (i=0;i<a[2];++i) printf("1 2 6\n");
        for (i=0;i<a[3];++i) printf("1 3 6\n");
        for (i=0;i<a[4];++i) printf("1 2 4\n");
    }
    return 0;
}