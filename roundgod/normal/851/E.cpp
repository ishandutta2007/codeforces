#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
unordered_map<ll,ll> sg,vis;
ll n,a[105];
ll prime[MAXN];
bool is_prime[MAXN];
ll sieve(ll n)
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            prime[p++]=i;
            for(ll j=2*i;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}
ll grundy(ll x)
{
	if(sg.count(x)) return sg[x];
	if(x==0) return sg[x]=0;
	for(ll i=1;i<=30;i++)
	{
		ll nxt=(x>>i)|(x&((1LL<<(i-1))-1));
		if(nxt!=x) grundy(nxt);
	}
	vis.clear();
	for(ll i=1;i<=30;i++)
	{
		ll nxt=(x>>i)|(x&((1LL<<(i-1))-1));
		if(nxt!=x) vis[grundy(nxt)]=1;
	}
	for(ll i=0;;i++) if(vis[i]==0) return sg[x]=i;
}
int main()
{
	scanf("%I64d",&n);
	for(ll i=0;i<n;i++)
		scanf("%I64d",&a[i]);
	ll p=sieve(MAXN);
	ll ans=0;
	for(ll i=0;i<p;i++)
	{
		ll s=0;
		for(ll j=0;j<n;j++)
		{
			ll cnt=0;
			while(a[j]%prime[i]==0)
			{
				a[j]/=prime[i];
				cnt++;
			}
			if(cnt>0) s|=(1<<(cnt-1));
		}
		if(s>0) ans^=grundy(s);
	}
	for(ll i=0;i<n;i++)
	{
		if(a[i]!=1)
		{
			ll now=a[i];
			ans^=1;
			for(ll j=0;j<n;j++)
				if(a[j]%now==0) a[j]/=now;
		}
	}
	if(ans) puts("Mojtaba"); else puts("Arpa");
	return 0;
}