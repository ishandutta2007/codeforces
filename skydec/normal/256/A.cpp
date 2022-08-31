#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<map>
#define MAXN 4005
using namespace std;
int n;
int a[MAXN];
int mb[MAXN];
int tmp[MAXN];
map<int,int>ls;
int mu[MAXN];
int app[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)tmp[i]=a[i];
    sort(tmp+1,tmp+1+n);
    int tot=0;
    for(int i=1;i<=n;i++)if(i==1||tmp[i]!=tmp[i-1])ls[tmp[i]]=++tot;
    for(int i=1;i<=n;i++)a[i]=ls[a[i]];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
            mu[0]=0;
            for(int j=i;j<=n;j++)if(a[j]==a[i])mu[++mu[0]]=j;
            memset(mb,0,sizeof mb);
            memset(app,0,sizeof app);
            for(int j=1;j<=mu[0]-1;j++)
            for(int k=mu[j]+1;k<=mu[j+1]-1;k++)
            if(mb[a[k]]<j)
            {
                          app[a[k]]++;
                          mb[a[k]]=j;
                          }
            for(int j=mu[mu[0]]+1;j<=n;j++)
            {
                          mb[a[j]]=-1;
                          }
            int u=0;if(mu[0]>ans)ans=mu[0];
            for(int j=1;j<=tot;j++)
            {
                    u=2*app[j]+1;
                    if(mb[j]==-1)u++;
                    if(u>ans)ans=u;
                    }
                    }
    printf("%d\n",ans);
    return 0;
}