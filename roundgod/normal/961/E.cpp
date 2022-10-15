#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
ll bit[MAXN+1];
ll sum(ll i)
{
    ll s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(ll i,ll x)
{
    while(i<MAXN)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
vector<ll> G[MAXN];
int main()
{
	scanf("%I64d",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		if(a[i]>200000) a[i]=200001;
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		ans+=sum(a[i]);
		if(a[i]>i)
		{
			add(i,1);
			G[a[i]].push_back(i);
		}
		for(ll j=0;j<G[i].size();j++)
			add(G[i][j],-1);
	}
	printf("%I64d\n",ans);
	return 0;
}