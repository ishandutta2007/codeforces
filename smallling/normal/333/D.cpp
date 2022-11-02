#include<cstdio>
#include<cstring>
#include<algorithm>

#define N 1010

using namespace std;

int n,m,l,r,ans;
int a[N][N],flag[N][N],q[N];

int check(int x)
{
    memset(flag,0,sizeof(flag));
    for(int i=1;i<=n;i++)
    {
        q[0]=0;
        for(int j=1;j<=m;j++)
            if(a[i][j]>=x)q[++q[0]]=j;
        for(int j=1;j<q[0];j++)
            for(int k=j+1;k<=q[0];k++)
                if(flag[q[j]][q[k]])return 1;
                else flag[q[j]][q[k]]=1;
    }
    return 0;
}

int main()
{
    scanf("%d%d",&n,&m);
    r=0;l=0x7f7f7f7f;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]),l=min(l,a[i][j]),r=max(r,a[i][j]);
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",ans);
}