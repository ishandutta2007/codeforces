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
#include<ctime>
#include<bitset>
using namespace std;
struct Bian
{
	int s,t,last;
}bian[1000010];
int last[200010],maxbian=0;
void addbian(int s,int t)
{
	maxbian++;
	bian[maxbian].s=s;
	bian[maxbian].t=t;
	bian[maxbian].last=last[s];
	last[s]=maxbian;
}
int dfn[200010],low[200010],scc[200010],ins[200010];
stack<int> s;
int maxdfn=0,maxscc=0;
vector<int> ch[200010];
void tarjan(int i)
{
	maxdfn++;
	dfn[i]=low[i]=maxdfn;
	s.push(i);
	ins[i]=1;
	int j;
	for(j=last[i];j;j=bian[j].last)
	{
		if(!dfn[bian[j].t])
		{
			tarjan(bian[j].t);
			low[i]=min(low[i],low[bian[j].t]);
		}
		else
			if(ins[bian[j].t])
				low[i]=min(low[i],dfn[bian[j].t]);
	}
	if(dfn[i]==low[i])
	{
		maxscc++;
		ins[s.top()]=0;
		scc[s.top()]=maxscc;
		ch[maxscc].push_back(s.top());
		while(s.top()!=i)
		{
			s.pop();
			ins[s.top()]=0;
			scc[s.top()]=maxscc;
			ch[maxscc].push_back(s.top());
		}
		s.pop();
	}
}
Bian nbian[1000010];
int nlast[200010],maxnbian=0;
int rd[200010];
void addnbian(int s,int t)
{
	maxnbian++;
	nbian[maxnbian].s=s;
	nbian[maxnbian].t=t;
	rd[t]++;
	nbian[maxnbian].last=nlast[s];
	nlast[s]=maxnbian;
}
int tp[200010],ftp[200010];
int n,m,m1,t1,t2,s1,p,n1,p1;
queue<int> q;
void topo()
{
	int k=0;
	for(n1=1;n1<=maxscc;n1++)
		if(rd[n1]==0)
		{
			k++;
			ftp[k]=n1;
			tp[n1]=k;
			q.push(n1);
		}
	while(!q.empty())
	{
		t1=q.front();
		q.pop();
		for(t2=nlast[t1];t2;t2=nbian[t2].last)
		{
			rd[nbian[t2].t]--;
			if(rd[nbian[t2].t]==0)
			{
				k++;
				ftp[k]=nbian[t2].t;
				tp[nbian[t2].t]=k;
				q.push(nbian[t2].t);
			}
		}
	}
}
vector<int> v[100010],ans;
int l[100010];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&l[i]);
		for(int j=1;j<=l[i];j++)
		{
			scanf("%d",&t1);
			v[i].push_back(t1);
		}
	}
	for(int i=1;i<n;i++)
	{
		int now=-1;
		for(int j=0;j<min(l[i],l[i+1]);j++)
			if(v[i][j]!=v[i+1][j])
			{
				now=j;
				break;
			}
		if(now==-1)
		{
			if(l[i]>l[i+1])
			{
				printf("No");
				return 0;
			}
		}
		else
		{
			if(v[i][now]>v[i+1][now])
			{
				addbian(v[i][now],v[i][now]+m);
				addbian(v[i+1][now]+m,v[i+1][now]);
			}
			else
			{
				addbian(v[i+1][now]+m,v[i][now]+m);
				addbian(v[i][now],v[i+1][now]);
			}
		}
	}
	for(int i=1;i<=2*m;i++)
		if(dfn[i]==0)
			tarjan(i);
	for(int i=1;i<=m;i++)
		if(scc[i]==scc[i+m])
		{
			printf("No\n");
			return 0;
		}
	for(n1=1;n1<=maxbian;n1++)
		if(scc[bian[n1].s]!=scc[bian[n1].t])
			addnbian(scc[bian[n1].t],scc[bian[n1].s]);
	topo();
	for(int i=1;i<=m;i++)
	{
		if(tp[scc[i]]>tp[scc[i+m]])
			ans.push_back(i);
	}
	cout<<"Yes\n";
	cout<<ans.size()<<endl;
	for(int j=0;j<ans.size();j++)
		printf("%d ",ans[j]);
}