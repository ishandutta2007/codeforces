#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#define pb push_back
#define MAXN 110000
using namespace std;
int n;
#define pii pair< int,int >
#define fi first
#define se second
pii data[MAXN];int m=0;
int rest[MAXN];
int tt[MAXN];
bool f[MAXN];
int check(int x)
{
    int cost=0;
    for(int i=0;i<=n;i++)tt[i]=rest[i],f[i]=1;
    for(int i=1;i<=m;i++)
    if(tt[data[i].se]>=x)
    {
               cost+=data[i].fi;
               tt[0]++;
               tt[data[i].se]--;
               f[i]=0;
               }
    for(int i=1;i<=m&&tt[0]<x;i++)
    if(f[i])cost+=data[i].fi,tt[0]++;
    if(tt[0]<x)cost=2100000000;
    return cost;
}                       
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            int a,b;scanf("%d%d",&a,&b);
            rest[a]++;
            if(a)data[++m]=pii(b,a);
            }
    n=100000;
    sort(data+1,data+1+m);
    int l,r;
    l=0;r=100000;
    for(int k=1;k<=100;k++)
    {
            int l0=l+(r-l)/3;
            int r0=r-(r-l)/3;
            if(check(l0)<=check(r0))r=r0;else l=l0;
            }
    int ans=2100000000;
    for(int i=l;i<=r;i++)
    {
            int d=check(i);
            if(d<ans)ans=d;
            }
    printf("%d\n",ans);
    return 0;
}