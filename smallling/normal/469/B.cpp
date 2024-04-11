#include<stdio.h>
#include<algorithm>

using namespace std;

int n,m,o,a[110],b[110],c[110],d[110],e[110],f[110],l,r,bo,boo,ans;

int main()
{
    scanf("%d%d%d%d",&n,&m,&l,&r);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i],&b[i]);
    for(int i=1;i<=m;i++)
        scanf("%d %d",&c[i],&d[i]);
    for(int i=l;i<=r;i++)
    {
        for(int j=1;j<=m;j++)
            e[j]=c[j]+i,f[j]=d[j]+i;
        bo=0;
        for(int j=1;j<=m;j++)
        {
            boo=0;
            for(int k=1;k<=n;k++)
                if(a[k]>=e[j]&&f[j]>=a[k]||e[j]>=a[k]&&e[j]<=b[k])
                {
                    boo=1;
                    break;
                }
            bo|=boo;
        }
        ans+=bo;
    }
    printf("%d",ans);
}