#include<stdio.h>
#include<algorithm>

using namespace std;

int n,m,ans,a[200010],b[200010],c[200010],next[200010];

int main()
{
    scanf("%d%d",&n,&m);
    if(m==1)return printf("%d",n),0;
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<n;i++)
        a[i]=c[i+1]-c[i];
    n--;
    for(int i=1;i<=m;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<m;i++)
        b[i]=c[i+1]-c[i];
    m--;
    for(int i=2,j=0;i<=m;i++)
    {
        for(;j&&b[i]!=b[j+1];j=next[j]);
        if(b[i]==b[j+1])j++;
        next[i]=j;
    }
    for(int i=1,j=0;i<=n;i++)
    {
        for(;j&&a[i]!=b[j+1];j=next[j]);
        if(a[i]==b[j+1])
        {
            j++;
            if(j==m)
            {
                ans++;
                j=next[j];
            }
        }
        else j=next[j];
    }
    printf("%d",ans);
}