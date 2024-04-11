#include<bits/stdc++.h>

using namespace std;

const long long maxn=200020;

long long cost=1e9+7,n,m,s,t;

long long c[maxn],v[maxn];

long long dis[maxn],d[maxn],sd[maxn];

int main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&s,&t);
	for(long long i=1;i<=n;i++) scanf("%I64d%I64d",&c[i],&v[i]);
	for(long long i=1;i<=m;i++) scanf("%I64d",&dis[i]);
	sort(dis+1,dis+m+1);
	dis[++m]=s;
	for(long long i=1;i<=m;i++) d[i]=dis[i]-dis[i-1];
	sort(d+1,d+m+1);
	for(long long i=1;i<=m;i++) sd[i]=sd[i-1]+d[i];
	for(long long i=1;i<=n;i++)
	{
		if(cost<=c[i]) continue;
		if(v[i]<d[m]) continue;
		if(v[i]>=d[m]*2)
		{
			if(sd[m]<=t)
				cost=c[i];
			continue;
		}
		long long tp=upper_bound(d+1,d+m+1,v[i]/2)-d-1;
		long long ans=sd[tp];
		ans+=3LL*(sd[m]-sd[tp])-(m-tp)*v[i];
		if(ans<=t) cost=c[i];
	}
	if(cost==1e9+7)
		cout<<-1<<endl;
	else
		cout<<cost;
}