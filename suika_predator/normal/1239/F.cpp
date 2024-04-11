#include<bits/stdc++.h>
using namespace std;
const int TEST=0;
pair<int,vector<int>> solve(int tcase)
{
	int n,m;
	cin>>n>>m;
	if(tcase==TEST)cerr<<n<<' '<<m<<endl;
	if(n==1)
	{
		return make_pair(0,vector<int>());
	}
	vector<vector<int>> G(n+5);
	vector<int> deg(n+5);
	vector<int> pa(n+5);
	function<int(int)> find=[&](int x){return pa[x]?pa[x]=find(pa[x]):x;};
	vector<pair<int,int>> eg;
	int cnt=n;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		if(tcase==TEST)cerr<<u<<' '<<v<<endl;
		G[u].push_back(v);
		G[v].push_back(u);
		deg[u]++;deg[v]++;
		eg.emplace_back(u,v);
		int pu=find(u),pv=find(v);
		if(pu!=pv)
		{
			pa[pv]=pu;
			cnt--;
		}
	}
	if(cnt>1)
	{
		int p=find(1);
		vector<int> ans;
		for(int i=1;i<=n;i++)
		{
			if(find(i)==p)ans.push_back(i);
		}
		return make_pair(n,ans);
	}
	for(int i=1;i<=n;i++)
	{
		if(deg[i]%3==0)
		{
			return make_pair(n,vector<int>({i}));
		}
	}
	int cnt1=0;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]%3==1)cnt1++;
	}
	if(cnt1>=2)
	{
		for(int i=1;i<=n;i++)
		{
			if(deg[i]%3==1)
			{
				vector<int> pre(n+5),vis(n+5);
				queue<int> q;
				q.push(i);
				vis[i]=1;
				int T=-1;
				while(not q.empty())
				{
					int u=q.front();q.pop();
					for(auto v:G[u])
					{
						if(not vis[v])
						{
							pre[v]=u;
							q.push(v);
							vis[v]=1;
							if(deg[v]%3==1 and T==-1)T=v;
						}
					}
				}
				vector<int> ans;
				while(T)
				{
					ans.push_back(T);
					T=pre[T];
				}
				if((int)ans.size()==n)
				{
					return make_pair(0,vector<int>());
				}
				else
				{
					return make_pair(n,ans);
				}
			}
		}
	}
	else if(cnt1==0)
	{
		vector<int> vis(n+5),pre(n+5),cyc;
		queue<int> q;
		q.push(1);
		vis[1]=1;
		int S=-1,T=-1;
		while(not q.empty())
		{
			int u=q.front();q.pop();
			for(auto v:G[u])
			{
				if(pre[u]==v)continue;
				if(not vis[v])
				{
					vis[v]=vis[u]+1;
					pre[v]=u;
					q.push(v);
				}
				else if(S==-1)
				{
					S=u,T=v;
				}
			}
		}
		if(S!=-1)
		{
			while(S!=T)
			{
				if(vis[S]>vis[T])cyc.push_back(S),S=pre[S];
				else cyc.push_back(T),T=pre[T];
			}
			cyc.push_back(S);
		}
		if((int)cyc.size()==n)
		{
			return make_pair(0,vector<int>());
		}
		else
		{
			return make_pair(n,cyc);
		}
	}
	else
	{
		vector<int> ans;
		int sp=0;
		for(int i=1;i<=n;i++)
			if(deg[i]%3==1)
				sp=i;
		{
			vector<vector<int>> G2(n+5);
			for(auto [u,v]:eg)
			{
				if(u==sp or v==sp)continue;
				G2[u].push_back(v);
				G2[v].push_back(u);
			}
			vector<int> vis(n+5),pre(n+5),cyc;
			queue<int> q;
			
			for(int i=1;i<=n;i++)
			{
				if(not vis[i] and i!=sp)
				{
					q.push(i);
					vis[i]=1;
					int S=-1,T=-1;
					while(not q.empty())
					{
						int u=q.front();q.pop();
						for(auto v:G2[u])
						{
							if(pre[u]==v)continue;
							if(not vis[v])
							{
								vis[v]=vis[u]+1;
								pre[v]=u;
								q.push(v);
							}
							else if(S==-1)
							{
								S=u,T=v;
							}
						}
					}
					if(S!=-1)
					{
						while(S!=T)
						{
							if(vis[S]>vis[T])cyc.push_back(S),S=pre[S];
							else cyc.push_back(T),T=pre[T];
						}
						cyc.push_back(S);
						return make_pair(n,cyc);
					}
				}
			}
		}
		ans.push_back(sp);
		int cc=0;
		vector<int> pre(n+5),vis(n+5),good(n+5);
		for(auto v:G[sp])good[v]=1;
		for(int i=1;i<=n;i++)
		{
			if(vis[i] or not good[i])continue;
			queue<int> q;
			q.push(i);
			vis[i]=1;
			int T=-1;
			while(not q.empty())
			{
				int u=q.front();q.pop();
				for(auto v:G[u])
				{
					if(not vis[v] and v!=sp)
					{
						pre[v]=u;
						q.push(v);
						vis[v]=1;
						if(good[v] and T==-1)T=v;
					}
				}
			}
			while(T)
			{
				ans.push_back(T);
				T=pre[T];
			}
			cc++;
			if(cc==2)break;
		}
		assert(cc==2);
		if((int)ans.size()==n)
		{
			return make_pair(0,vector<int>());
		}
		else
		{
			return make_pair(n,ans);
		}
	}
	return make_pair(0,vector<int>());
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	for(int tt=1;tt<=T;tt++)
	{
		auto [n,ans]=solve(tt);
		if(n==0)cout<<"No\n";
		else
		{
			cout<<"Yes\n";
			vector<int> tmp,vis(n+5);
			for(auto z:ans)vis[z]=1;
			cout<<n-(int)ans.size()<<"\n";
			for(int i=1;i<=n;i++)
			{
				if(not vis[i])
					cout<<i<<' ';
			}
			cout<<"\n";
		}
	}
	return 0;
}