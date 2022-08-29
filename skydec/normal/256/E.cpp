#include<stdio.h>
#include<cstring>
#define jsb 777777777
#define MAXN 410000
using namespace std;
int good[4][4];
struct info
{
       int kt[4][4];
       void init()
       {
            memset(kt,0,sizeof kt);
            }
       void make(int x)
       {
            init();
            if(!x)
            {
                  for(int i=1;i<=3;i++)
                  kt[i][i]=1;
                  }
            else
            {
                kt[x][x]=1;
                }
                }
       info operator +(info b)
       {
            info c;c.init();
            for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            for(int s1=1;s1<=3;s1++)
            for(int s2=1;s2<=3;s2++)
            if(good[s1][s2])
            c.kt[i][j]=(c.kt[i][j]+kt[i][s1]*1ll*b.kt[s2][j]%jsb)%jsb;
            return c;
            }
}data[MAXN];
int pos[MAXN];
int n,m;
void build(int now,int l,int r)
{
     if(l==r)
     {
             pos[l]=now;
             data[now].make(0);
             return;
             }
     int mid=(l+r)>>1;
     build(now*2,l,mid);
     build(now*2+1,mid+1,r);
     data[now]=data[now*2]+data[now*2+1];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=3;i++)
    for(int j=1;j<=3;j++)scanf("%d",&good[i][j]);
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
            int v,t;scanf("%d%d",&v,&t);
            data[pos[v]].make(t);
            int u=pos[v]/2;
            while(u)data[u]=data[u*2]+data[u*2+1],u/=2;
            int ans=0;
            for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            ans=(ans+data[1].kt[i][j])%jsb;
            printf("%d\n",ans);
            }
    return 0;
}