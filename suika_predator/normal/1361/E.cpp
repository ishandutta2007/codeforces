#include<bits/stdc++.h>
using namespace std;
const int tt=100;
struct edge
{
	int v;
	edge *next;
}*h[111111],pool[1111111];
int top;
inline void addedge(int u,int v)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
}
int T,n,m,k;
std::mt19937 ran;
vector<int> ans;
int dfn[111111],ins[111111],ind;
int ret[111111],up[111111];
int st[111111],pot;
int find(int x){return up[x]?up[x]=find(up[x]):x;}
bool dfs1(int u)
{
//	cerr<<"dfs "<<u<<' '<<endl;
	dfn[u]=++ind;st[++pot]=u;ins[u]=pot;
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
//		cerr<<u<<' '<<tmp->v<<endl;
		if(!dfn[tmp->v])
		{
			if(!dfs1(tmp->v))
				return false;
		}
		else if(!ins[tmp->v])return false;
		else
		{
//			cerr<<"back edge "<<u<<"->"<<tmp->v<<endl;
			int cur=u;
			while(ins[cur]>ins[tmp->v])
			{
//				cerr<<pos<<' '<<st[pos]<<endl;
				if(ret[cur])
				{
					ret[cur]=-1;
					up[cur]=st[ins[cur]-1];
				}
				else
				{
					ret[cur]=tmp->v;
				}
				cur=find(st[ins[cur]-1]);
			}
		}
	}
	ins[u]=0;
	pot--;
//	cout<<"pop "<<u<<endl;
	return true;
}
int ok[111111];
queue<int> q;
vector<int> gg[111111];
bool solve(int r)
{
//	cerr<<"solve "<<r<<endl;
	memset(dfn,0,sizeof(int)*(n+5));
	memset(ins,0,sizeof(int)*(n+5));
	memset(ret,0,sizeof(int)*(n+5));
	memset(up,0,sizeof(int)*(n+5));
	memset(st,0,sizeof(int)*(n+5));
	ind=0;pot=0;
	if(!dfs1(r))return false;
//	for(int i=1;i<=n;i++)cerr<<i<<' '<<ret[i]<<endl;
	for(int i=1;i<=n;i++)gg[i].clear();
	for(int i=1;i<=n;i++)
	{
		if(ret[i]==-1)
		{
			ok[i]=0;
			q.push(i);
		}
		else
		{
			ok[i]=1;
			if(ret[i])gg[ret[i]].push_back(i);
		}
	}
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(auto v:gg[u])
		{
			if(ok[v])
			{
				ok[v]=0;
				q.push(v);
			}
		}
	}
	ans.clear();
	for(int i=1;i<=n;i++)if(ok[i])ans.push_back(i);
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
//	freopen("data.txt","r",stdin);
	ran.seed(time(0));
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		memset(h,0,sizeof(edge*)*(n+5));
		ans.clear();
		int x,y;
		for(int i=1;i<=m;i++)
		{
			cin>>x>>y;
			addedge(x,y);
		}
//		cerr<<"???"<<endl;
		int ok=0;
		for(int ttt=1;ttt<=tt;ttt++)
		{
			int root=ran()%n+1;
			if(solve(root))
			{
				if(ans.size()*5>=n)
				{
					for(auto x:ans)cout<<x<<' ';
					cout<<endl;
				}
				else cout<<-1<<endl;
				ok=1;
				break;
			}
		}
		if(!ok)cout<<-1<<endl;
	}
	return 0;
}