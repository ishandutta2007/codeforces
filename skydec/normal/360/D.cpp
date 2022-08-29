#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
typedef long long LL;
#define MAXN 110000
int gcd(int a,int b){if(!a||!b)return a+b;return gcd(b,a%b);}
int n,m,p;
int Power(int a,int b)
{
    int c=1;
    for(;b;b>>=1,a=a*1ll*a%(p))if(b&1)c=c*1ll*a%(p);
    return c;
}
int a[MAXN],b[MAXN];int t[MAXN];int tot=0;int s[MAXN];
map<int,int>fuck;int f[MAXN];
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    rep(i,1,n)scanf("%d",&a[i]);int d=p-1;
    rep(i,1,m){int v;scanf("%d",&v);d=gcd(d,v);}
    for(int i=1;i*i<=p-1;i++)
    if((p-1)%i==0)
    {
                  t[++tot]=i;
                  if((p-1)/i!=i)t[++tot]=(p-1)/i;
                  }
    sort(t+1,t+1+tot);
    for(int i=1;i<=n;i++)
    rep(j,1,tot)
    if(Power(a[i],t[j]*1ll*d%(p-1))==1)
    {
       s[i]=(p-1)/t[j];
       break;
       }
    sort(s+1,s+1+n);int ans=0;
    per(i,n,1)
    if(!fuck[s[i]])
    {
                   fuck[s[i]]=1;
                   f[i]=(p-1)/s[i];
                   rep(j,i+1,n)
                   if(s[j]%s[i]==0)f[i]-=f[j];
                   ans+=f[i];
                   }
    printf("%d\n",ans);
    return 0;
}