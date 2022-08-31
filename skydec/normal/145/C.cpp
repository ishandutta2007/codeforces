#include<stdio.h>
#include<map>
#define jsb 1000000007
#include<cstring>
#define MAXN 110000
using namespace std;
int f[MAXN];
int data[MAXN];
int tot=0;int k;
map<int,int>num;
void dfs(long long x)
{
     if(x>=1000000000)return;
     if(x)
     num[(int)x]=++tot;
     if(x==0)dfs(4),dfs(7);
     else dfs(x*10ll+4ll),dfs(x*10ll+7ll);
}
int cc[2000];
void add(int &x,int y){x=(x+y)%jsb;}
int n;
int Fac[110000],nwFac[110000];
int Pow(int a,int b)
{
    int c=1;for(;b;b>>=1,a=a*1ll*a%jsb)
    if(b&1)c=c*1ll*a%jsb;
    return c;
}
void init()
{
     Fac[0]=1;for(int i=1;i<=n;i++)Fac[i]=Fac[i-1]*1ll*i%jsb;
     for(int i=0;i<=n;i++)nwFac[i]=Pow(Fac[i],jsb-2);
}
int C(int m,int nx)
{
    //printf("%d %d %d %d %d\n",m,nx,Fac[m],nwFac[nx],nwFac[m-nx]);
    if(m<nx)return 0;
    return Fac[m]*1ll*(nwFac[nx]*1ll*nwFac[m-nx]%jsb)%jsb;
}
int main()
{
    scanf("%d",&n);scanf("%d",&k);
    init();
    for(int i=1;i<=n;i++)scanf("%d",&data[i]);
    dfs(0);
    for(int i=1;i<=n;i++)data[i]=num[data[i]];
    int u=0;
    for(int i=1;i<=n;i++)
    if(data[i]==0)u++;
    else cc[data[i]]++;
    int ans=0;
    for(int i=0;i<=u;i++)f[i]=C(u,i);
    for(int i=1;i<=tot;i++)
    if(cc[i])
    for(int j=k;j>=1;j--)
    add(f[j],f[j-1]*1ll*cc[i]%jsb);
    printf("%d\n",f[k]);
    return 0;
}