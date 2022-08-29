#include<stdio.h>
#include<vector>
#include<cmath>
#define pb push_back
#define MAXN 110000
using namespace std;
int n,m;
vector<int> head[MAXN];
int mod;
int min(int a,int b){if(a<b)return a;return b;}
long long max(long long a,long long b){if(a>b)return a;return b;}
int ask(int x,int y)
{
    int res=0;
    //printf("%d\n",(1<<head[x].size()));
    for(int i=0;i<(1<<head[x].size());i++)
    {
            int p=1;int f=1;
            for(int j=0;j<head[x].size();j++)
            if(i&(1<<j))f*=-1,p*=head[x][j];
            int tmp=min(y,m)/p;
res+=f*((tmp*1ll*(m+1)%mod)-(((tmp+1)*1ll*tmp/2)%mod)*1ll*p%mod)%mod;
            res%=mod;
            }
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    int l,r;scanf("%d%d%d",&l,&r,&mod);
    int MAX=n;if(m>MAX)MAX=m;MAX++;
    for(int i=2;i<=MAX;i++)
    if(head[i].size()==0)
    for(int j=i;j<=MAX;j+=i)
    head[j].pb(i);
    int ans=0;
    if(l<=1)
    {
            ans=(n+1)*1ll*m%mod;
            ans+=(m+1)*1ll*n%mod;
            ans%=mod;
            }
    //printf("%d\n",ans);
    for(int i=1;i<=n;i++)
    {
            if(i>=r)break;
            int j=(int)sqrt(r*1ll*r-i*1ll*i);
            int reu=ask(i,j);
            j=(int)sqrt(max(l*1ll*l-i*1ll*i-1,0));
            reu-=ask(i,j);reu%=mod;
            reu=reu*2%mod;
            ans+=reu*1ll*(n-i+1)%mod;
            ans%=mod;
            }
    if(ans<0)ans+=mod;
    printf("%d\n",ans);
    return 0;
}