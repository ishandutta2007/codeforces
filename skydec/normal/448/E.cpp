#include<stdio.h>
#include<map>
#include<algorithm>
#define MAXN 20000000
using namespace std;
typedef long long LL;
LL ys[9000];int tot=0;int tt2=0;
int tail[9000];int head[9000];
int aft[MAXN];LL p[MAXN];
LL n,k;
map<LL,int>bh;
void line(int j,int i)
{
     tt2++;if(!tail[j])head[j]=tt2;p[tt2]=i;aft[tail[j]]=tt2;tail[j]=tt2;
}
void init()
{
     for(LL i=1;i*i<=n;i++)
     if(n%i==0)
     {
               ys[++tot]=i;
               if(i*i!=n)
               ys[++tot]=n/i;
               }
     sort(ys+1,ys+1+tot);
     for(int i=1;i<=tot;i++)bh[ys[i]]=i;
     for(int i=1;i<=tot;i++)
     for(int j=1;j<=i;j++)
     if(ys[i]%ys[j]==0)line(i,j);
}
int dfs(int now,LL dep,int need)
{
    if(ys[now]==1)
    {
                  printf("1 ");
                  return 1;
                  }
     if(dep==k)
     {
               int us=need;
               for(int u=head[now];u&&need;need--,u=aft[u])
               printf("%I64d ",ys[p[u]]);
               return us-need;
               }
     int us=need;
     for(int u=head[now];u&&need;need-=dfs(p[u],dep+1,need),u=aft[u]);
     return us-need;
}
int main()
{
    scanf("%I64d%I64d",&n,&k);if(k>100000)k=100000;
    init();
    if(!k)
    {
          printf("%I64d\n",n);
          return 0;
          }
    dfs(bh[n],1,100000);
    return 0;
}