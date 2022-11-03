/*
ID: Sfiction
OJ: CF
PROB: 337A
*/
#include <cstdio>
#include <cstdlib>
int Comp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int a[100];
    int i,n,m,ans;
    scanf("%d%d",&n,&m);
    for (i=0;i<m;++i) scanf("%d",&a[i]);
    qsort(a,m,sizeof(int),Comp);
    ans=1<<30;
    for (i=n;i<=m;++i)
        if (a[i-1]-a[i-n]<ans) ans=a[i-1]-a[i-n];
    printf("%d",ans);
    return 0;
}