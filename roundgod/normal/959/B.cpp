#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,m,a[MAXN];
string str;
map<string,int> mp;
ll p[MAXN],r[MAXN];
void init(ll n)
{
    for(ll i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
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
    if(r[x]<r[y]) {p[x]=y; a[y]=min(a[y],a[x]);}
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
        a[x]=min(a[x],a[y]);
    }
}
bool same(ll x,ll y)
{
    return find(x)==find(y);
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&k,&m);
	for(ll i=1;i<=n;i++)
	{
		cin>>str;
		mp[str]=i;
	}
	for(ll i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	init(n);
	for(ll i=1;i<=k;i++)
	{
		ll x;
		scanf("%I64d",&x);
		ll fst;
		scanf("%I64d",&fst);
		for(ll j=0;j<x-1;j++)
		{
			ll p;
			scanf("%I64d",&p);
			unite(p,fst);
		}
	}
	ll ans=0;
	for(ll i=0;i<m;i++)
	{
		cin>>str;
		ll id=mp[str];
		ans+=a[find(id)];
	}
	printf("%I64d\n",ans);
	return 0;
}