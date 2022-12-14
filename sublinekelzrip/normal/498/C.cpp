#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
struct Bian
{
	int s,t,last,flow,now;
}bian[1010];
int maxbian=0,last[220];
void addbian(int s,int t,int flow)
{
	maxbian++;
	bian[maxbian].s=s;
	bian[maxbian].t=t;
	bian[maxbian].last=last[s];
	bian[maxbian].flow=flow;
	bian[maxbian].now=0;
	last[s]=maxbian;
	maxbian++;
	bian[maxbian].s=t;
	bian[maxbian].t=s;
	bian[maxbian].last=last[t];
	bian[maxbian].flow=0;
	bian[maxbian].now=0;
	last[t]=maxbian;
}
int v[220],d[220],s,t;
queue<int> q;
int bfs()
{
	int t1,t2;
	memset(v,0,sizeof(v));
	d[s]=0;
	v[s]=1;
	q.push(s);
	while(!q.empty())
	{
		t1=q.front();
		q.pop();
		for(t2=last[t1];t2;t2=bian[t2].last)
		{
			if(bian[t2].flow>bian[t2].now&&!v[bian[t2].t])
			{
				v[bian[t2].t]=1;
				q.push(bian[t2].t);
				d[bian[t2].t]=d[t1]+1;
			}
		}
	}
	return v[t];
}
int cur[220];
int dfs(int x,int a)
{
	if(x==t||a==0)
		return a;
	int flow=0,f;
	for(;cur[x];cur[x]=bian[cur[x]].last)
		if(d[bian[cur[x]].t]==d[bian[cur[x]].s]+1&&(f=dfs(bian[cur[x]].t,min(bian[cur[x]].flow-bian[cur[x]].now,a)))>0)
		{
			a-=f;
			flow+=f;
			bian[cur[x]].now+=f;
			bian[((cur[x]-1)^1)+1].now-=f;
			if(a==0)
				break;
		}
	return flow;
}
int maxflow()
{
	int flow=0,i;
	while(bfs())
	{
		for(i=1;i<=t;i++)
			cur[i]=last[i];
		flow+=dfs(s,inf);
	}
	return flow;
}
int num[110],l[110],r[110],z[110];
int main()
{
	int n,m,n1,m1;
	cin>>n>>m;
	for(n1=1;n1<=n;n1++)
		scanf("%d",&num[n1]);
	for(m1=1;m1<=m;m1++)
	{
		scanf("%d%d",&l[m1],&r[m1]);
		if(r[m1]%2==1)
			swap(l[m1],r[m1]);
	}
	int x=0;
	s=n+1;
	t=n+2;
	long long ans=0;
	while(x!=1)
	{
		for(n1=1;n1<=n;n1++)
			x=max(x,num[n1]);
		int y=0;
		for(n1=2;n1*n1<=x;n1++)
			if(x%n1==0)
			{
				y=n1;
				break;
			}
		if(y==0)
			y=x;
		memset(last,0,sizeof(last));
		maxbian=0;
		memset(z,0,sizeof(z));
		for(n1=1;n1<=n;n1++)
		{
			while(num[n1]%y==0)
			{
				z[n1]++;
				num[n1]/=y;
			}
			if(n1%2==1)
				addbian(s,n1,z[n1]);
			else
				addbian(n1,t,z[n1]);
		}
		for(m1=1;m1<=m;m1++)
		{
			addbian(l[m1],r[m1],min(z[l[m1]],z[r[m1]]));
		}
		ans+=maxflow();
		x=0;
		for(n1=1;n1<=n;n1++)
			x=max(x,num[n1]);
	}
	cout<<ans<<endl;
}