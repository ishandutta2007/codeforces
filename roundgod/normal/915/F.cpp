#include<bits/stdc++.h>
#define MAXN 1000005
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll p[MAXN],r[MAXN],a[MAXN],sz[MAXN];
bool used[MAXN];
vector<ll> G[MAXN];
ll n;
P save[MAXN];
bool cmp(P x,P y)
{
	return x.F>y.F;
}
void init(ll n)
{
	memset(used,false,sizeof(used));
    for(ll i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
        sz[i]=1;
    }
}
ll find(ll x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(ll x,ll y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) {p[x]=y; sz[y]+=sz[x];}
    else
    {
        p[y]=x;
        sz[x]+=sz[y];
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(ll x,ll y)
{
    return find(x)==find(y);
}
int main()
{
	scanf("%I64d",&n);
	for(ll i=0;i<n;i++)
		scanf("%I64d",&a[i]);
	for(ll i=0;i<n-1;i++)
	{
		ll x,y;
		scanf("%I64d%I64d",&x,&y);
		G[x-1].push_back(y-1);
		G[y-1].push_back(x-1);
	}
	for(ll i=0;i<n;i++)
	{
		save[i].F=a[i];
		save[i].S=i;
	}
	sort(save,save+n);
	init(n);
	ll maxn=0,minn=0;
	for(ll i=0;i<n;i++)
	{
		ll num=save[i].F,id=save[i].S;
		ll cnt=0,res=0;
		used[id]=true;
		for(ll j=0;j<G[id].size();j++)
		{
			res++;
			ll to=G[id][j];
			if(used[to])
			{
				res+=sz[find(to)]*(cnt+1);
				cnt+=sz[find(to)];
				unite(id,to);
			}
		}
		maxn+=res*num;
	}
	sort(save,save+n,cmp);
	init(n);
	for(ll i=0;i<n;i++)
	{
		ll num=save[i].F,id=save[i].S;
		ll cnt=0,res=0;
		used[id]=true;
		for(ll j=0;j<G[id].size();j++)
		{
			res++;
			ll to=G[id][j];
			if(used[to])
			{
				res+=sz[find(to)]*(cnt+1);
				cnt+=sz[find(to)];
				unite(id,to);
			}
		}
		minn+=res*num;
	}
	printf("%I64d\n",maxn-minn);
    return 0;
}