#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long li;
typedef pair<int,int> P;
li n,m,q;
vector<int> G[MAXN];
li p[MAXN],color[MAXN],mx[MAXN],sum[MAXN];
void dfs_visit(li v,li pa)
{
	color[v]=1;
	p[v]=pa;
	for(li i=0;i<G[v].size();i++)
	{
		li to=G[v][i];
		if(to==pa) continue;
		if(color[to]==0)
		{
			p[to]=v;
			dfs_visit(to,v);
		}
		else if(color[to]==1)
		{
			li l=min(to,v);
			li r=max(to,v);
			li now=v;
			while(now!=to)
			{
				now=p[now];
				l=min(l,now);
				r=max(r,now);
			}
			mx[l]=min(mx[l],r-1);
		}
	}
	color[v]=2;
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for(li i=0;i<m;i++)
	{
		li u,v;
		scanf("%I64d%I64d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(color,0,sizeof(color));
	fill(mx+1,mx+n+1,n);
	for(li i=1;i<=n;i++)
		if(color[i]==0) dfs_visit(i,-1);
	for(li i=n-1;i>=1;i--)
		mx[i]=min(mx[i],mx[i+1]);
	sum[0]=0;
	for(li i=1;i<=n;i++)
		sum[i]=mx[i]-i+1+sum[i-1];
	scanf("%I64d",&q);
	for(li i=0;i<q;i++)
	{
		li l,r;
		scanf("%I64d%I64d",&l,&r);
		li ll=l-1,rr=r+1;
		while(rr-ll>1)
		{
			li mid=(ll+rr)/2;
			if(mx[mid]<r) ll=mid; else rr=mid;
		}
		printf("%I64d\n",sum[ll]-sum[l-1]+(r-ll)*(r+1)-(ll+r+1)*(r-ll)/2);
	}
	return 0;
}