#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[333][333],b[333][333],c[333];bool v[333];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)scanf("%d",&a[i][j]),b[i][a[i][j]]=j;
    for(int i=1;i<=n;i++)c[i]=n;
    for(int j=1;j<=n;j++)scanf("%d",&a[0][j]);
    for(int i=1;i<=n;i++)
    {
        v[i]=1;
        for(int j=1;j<=n;j++)
        {
            bool F=0;
            for(int k=1;k<=n&&!F;k++)
                if(v[a[0][k]])if(a[0][k]!=j||j>i)c[j]=min(c[j],b[j][a[0][k]]),F=1;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d%c",a[i][c[i]],i==n?'\n':' ');
    return 0;
}