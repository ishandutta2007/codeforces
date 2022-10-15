#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
int main()
{
    int n,m,i,j,a[101][101],maxi,cnt[101],t;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
      for(j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
    memset(cnt,0,sizeof(cnt));
    for(i=1;i<=m;i++)
    {
      maxi=-1;
      t=0;
      for(j=1;j<=n;j++)
        if(a[i][j]>maxi)
        {
            maxi=a[i][j];
            t=j;
        }
    cnt[t]++;
    }
    maxi=-1;
    t=0;
    for(i=1;i<=n;i++)
    {
        if(cnt[i]>maxi)
        {
            maxi=cnt[i];
            t=i;
        }
    }
    printf("%d",t);
    return 0;
}