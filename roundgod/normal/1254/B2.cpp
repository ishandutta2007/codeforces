#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,a[MAXN];
vector<P> v;
int prime[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
ll get_res()
{
    ll ans=0,sum=0,cnt=0;
    int sz=(int)v.size();
    for(int i=0;i<sz;i++) sum+=v[i].S;
    ll need=sum/2;
    for(int i=0;i<sz;i++)
    {
        if(cnt+v[i].S>=need)
        {
            ans-=v[i].F*(need-cnt);
            break;
        }
        else {ans-=1LL*v[i].F*v[i].S; cnt+=v[i].S;}
    }
    cnt=0;
    for(int i=sz-1;i>=0;i--)
    {
        if(cnt+v[i].S>=need)
        {
            ans+=v[i].F*(need-cnt);
            break;
        }
        else {ans+=1LL*v[i].F*v[i].S; cnt+=v[i].S;}
    }
    return ans;
}
ll get_ans(ll d)
{
    v.clear();
    if(d==1) return INF;
    ll cnt=0;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int x=a[i]%d;
        cnt+=x;
        if(cnt>=d)
        {
            v.push_back(make_pair(i,x-(cnt-d)));
            ans+=get_res(); cnt%=d;
            v.clear(); v.push_back(make_pair(i,cnt));
        }
        else
        {
            v.push_back(make_pair(i,x));
        }
    }
    return ans;
}
vector<ll> fact;
int main()
{
    scanf("%d",&n);
    int p=sieve(1000000);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    ll ans=INF;
    for(int i=0;i<p;i++)
    {
        if(sum%prime[i]==0)
        {
            fact.push_back(prime[i]);
            while(sum%prime[i]==0) sum/=prime[i];
        }
    }
    if(sum>1) fact.push_back(sum);
    for(auto p:fact) ans=min(ans,get_ans(p));
    if(ans==INF) puts("-1"); else printf("%lld\n",ans);
    return 0;
}