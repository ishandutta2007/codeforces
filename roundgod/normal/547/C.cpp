#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 500005
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int cnt[MAXM];
int n,q,a[MAXN];
bool has[MAXN];
int prime[MAXM],mu[MAXM];
bool is_prime[MAXM];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    mu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; mu[i]=-1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            mu[prime[j]*i]=(i%prime[j]?-mu[i]:0);
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main()
{
    sieve(500000);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(has,false,sizeof(has));
    ll ans=0;
    for(int i=0;i<q;i++)
    {
        int id;
        scanf("%d",&id);
        int mult=has[id]?-1:1;
        if(!has[id])
        {
            for(int j=1;j*j<=a[id];j++)
            {
                if(a[id]%j) continue;
                ans+=mu[j]*cnt[j];
                if(j*j!=a[id]) ans+=mu[a[id]/j]*cnt[a[id]/j];
            }
            for(int j=1;j*j<=a[id];j++)
            {
                if(a[id]%j) continue;
                cnt[j]++;
                if(j*j!=a[id]) cnt[a[id]/j]++;
            }
        }
        else
        {
            for(int j=1;j*j<=a[id];j++)
            {
                if(a[id]%j) continue;
                cnt[j]--;
                if(j*j!=a[id]) cnt[a[id]/j]--;
            }
            for(int j=1;j*j<=a[id];j++)
            {
                if(a[id]%j) continue;
                ans-=mu[j]*cnt[j];
                if(j*j!=a[id]) ans-=mu[a[id]/j]*cnt[a[id]/j];
            }
        }
        has[id]=!has[id];
        printf("%lld\n",ans);
    }
    return 0;
}