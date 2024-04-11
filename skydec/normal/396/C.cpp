#include<stdio.h>
#include<cstring>
#define jsb 1000000007
#define MAXN 610000
using namespace std;
typedef long long LL;
int head[MAXN],next[MAXN],p[MAXN];
int dep[MAXN];
int tot=0;int dt=0;
int n,q;
int st[MAXN],ed[MAXN];
int cnt1[MAXN],cnt2[MAXN];
void dfs(int x,int dd)
{
     dep[x]=dd;
     st[x]=++dt;
     for(int u=head[x];u;u=next[u])dfs(p[u],dd+1);
     ed[x]=++dt;
}
int ADD1(int l,int r,int v)
{
    //printf("%d %d %d\n",l,r,v);
    if(l>1)
    for(int x=l-1;x<=dt;x+=x&-x)cnt1[x]=(cnt1[x]-v)%jsb;
    if(r!=0)
    for(int x=r;x<=dt;x+=x&-x)cnt1[x]=(cnt1[x]+v)%jsb;
}
int ADD2(int l,int r,int v)
{
    if(l-1!=0)
    for(int x=l-1;x<=dt;x+=x&-x)cnt2[x]=(cnt2[x]-v)%jsb;
    if(r!=0)
    for(int x=r;x<=dt;x+=x&-x)cnt2[x]=(cnt2[x]+v)%jsb;
    //printf("%d %d %d\n",l,r,v);
}
int Q1(int v)
{
    int ans=0;
    for(int x=dt;x;x-=x&-x)ans=(ans+cnt1[x])%jsb;
    for(int x=v-1;x;x-=x&-x)ans=(ans-cnt1[x])%jsb;
    return ans;
}
int Q2(int v)
{
    int ans=0;
    for(int x=dt;x;x-=x&-x)ans=(ans+cnt2[x])%jsb;
    for(int x=v-1;x;x-=x&-x)ans=(ans-cnt2[x])%jsb;
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
            int v;scanf("%d",&v);
            tot++;p[tot]=i;next[tot]=head[v];head[v]=tot;
            }
    dfs(1,0);scanf("%d",&q);
    while(q--)
    {
              int opt;scanf("%d",&opt);
              if(opt==1)
              {
                        int v,x,k;scanf("%d%d%d",&x,&v,&k);
                        ADD1(st[x],ed[x],v);
                        ADD1(st[x],ed[x],(dep[x]*1ll*k)%jsb);
                        ADD2(st[x],ed[x],k);
                        }
              else
              {
                  int x;scanf("%d",&x);
                  int a=(Q1(st[x])+Q2(st[x])*1ll*(-dep[x]))%jsb;
                  if(a<0)a+=jsb;
                  printf("%d\n",a);
                  }
                  }
    return 0;
}