#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=200020;
int n,m,last[N]={},next[M]={},end[M]={},l[M]={},total_edge=0;
int dis[N]={},f[N]={},con[N]={},dist[N]={};
inline void add_edge(int u,int v,int len)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	l[total_edge]=len;
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,l;i<=m;++i)
	{
		scanf("%d%d%d",&u,&v,&l);
		++u,++v;
		add_edge(u,v,l),add_edge(v,u,l);
	}
}
void dfs(int s)
{
	con[s]=true;
	for(int i=last[s];i;i=next[i])
		if(l[i]==0 && !con[end[i]])
			dfs(end[i]);
}
void bfs()
{
	int q[N]={},head=0,tail=0;
	bool v[N]={};
	q[++tail]=1;
	v[1]=true;
	dis[1]=0;
	while(head!=tail)
		for(int s=q[++head],i=last[s];i;i=next[i])
			if(!v[end[i]])
				q[++tail]=end[i],v[end[i]]=true,dis[end[i]]=dis[s]+1;
	//cout<<"d="<<dis[n]<<endl;
}
void work()
{
	set<int> s1,s2;
	queue<int> q;
	q.push(n);
	con[n]=false;
	int len=1<<30;
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		len=min(len,dis[s]);
		s1.insert(s);
		for(int i=last[s];i;i=next[i])
			if(con[end[i]] && l[i]==0)
			{
				q.push(end[i]);
				con[end[i]]=false;
				dist[end[i]]=dist[s]+1;
				f[end[i]]=s;
			}
	}
	for(int d=len-1;d>=0;--d)
	{
		int minv=10;
		for(set<int>::iterator it=s1.begin();it!=s1.end();++it)
			for(int i=last[*it];i;i=next[i])
				if(dis[end[i]]==d)
					minv=min(minv,l[i]);
		for(set<int>::iterator it=s1.begin();it!=s1.end();++it)
			for(int i=last[*it];i;i=next[i])
				if(dis[end[i]]==d && l[i]==minv)
				{
					if(f[end[i]]==0 || dist[f[end[i]]]>dist[*it])
					{
						f[end[i]]=*it;
						dist[end[i]]=dist[*it]+1;
					}
					s2.insert(end[i]);
				}
		printf("%d",minv);
		s1=s2;
		s2.clear();
	}
	if(len==0)
		printf("0");
	vector<int> ans;
	int s=1;
	for(int i=1;i<=len;s=f[s],++i)
		ans.push_back(s);
	while(s!=n)
	{
		ans.push_back(s);
		s=f[s];
	}
	ans.push_back(n);
	printf("\n%u\n",ans.size());
	for(int i=0;i<(int)ans.size();++i)
		printf("%d ",ans[i]-1);
	printf("\n");
}
int main()
{
	init();
	dfs(n);
	bfs();
	work();
	return 0;
}