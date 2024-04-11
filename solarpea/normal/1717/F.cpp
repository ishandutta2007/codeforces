#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n,m,s,t,x[10010],y[10010],c[10010],a[10010],b[10010];
vector<pair<pair<int,int>,int> > g[10010];
int lvl[10010],r[10010];

inline void add_edge(int x,int y,int c)
{
	g[x].push_back(make_pair(make_pair(y,c),g[y].size()));
	g[y].push_back(make_pair(make_pair(x,0),g[x].size()-1));
}

inline void bfs(int x)
{
	memset(lvl,-1,sizeof(lvl));
	queue<int> q;
	lvl[x]=0;
	q.push(x);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			pair<pair<int,int>,int> e=g[u][i];
			if(e.first.second>0&&lvl[e.first.first]==-1){
				lvl[e.first.first]=lvl[u]+1;
				q.push(e.first.first);
			}
		}
	}
}
	
inline int dfs(int now,int cap)
{ 
	if(now==t){
		return cap;
	}
	for(int i=r[now];i<g[now].size();i++,r[now]++){
		pair<pair<int,int>,int> e=g[now][i];
		if(e.first.second>0&&(lvl[now]<lvl[e.first.first])){
			int dis=dfs(e.first.first,min(cap,e.first.second));
			if(dis>0){
				g[now][i].first.second-=dis;
				g[e.first.first][e.second].first.second+=dis;
				return dis;
			}
		}
	}
	return 0;
}

inline int max_flow()
{
	int flow=0;
	while(true){
		bfs(s);
		if(lvl[t]==-1) return flow;
		memset(r,0,sizeof(r));
		int f=dfs(s,INF);
		while(f>0){
			flow+=f;
			f=dfs(s,INF);
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>x[i]>>y[i],b[x[i]]--,b[y[i]]++;
	bool flag=true;
	for(int i=1;i<=n;i++) if(c[i]==1){
		a[i]-=b[i];
		if(a[i]%2!=0){
			flag=false;break;
		}
		a[i]/=2;
	}
	if(!flag){
		cout<<"NO\n";
		return 0;
	}
	int tot=0;
	for(int i=1;i<=n;i++) tot+=a[i];
	s=n+2;t=n+3;
	add_edge(s,n+1,INF-tot);
	add_edge(n+1,t,INF);
	for(int i=1;i<=n;i++) if(c[i]==1){
		if(a[i]>0) add_edge(s,i,a[i]);
		else add_edge(i,t,-a[i]);
	}
	for(int i=1;i<=n;i++) if(c[i]==0){
		add_edge(i,n+1,INF);
		add_edge(n+1,i,INF);
	}
	for(int i=1;i<=m;i++){
		add_edge(x[i],y[i],1);
	}
	max_flow();
	for(int i=1;i<=n&&flag;i++) if(c[i]==1){
		if(a[i]>0){
			for(int j=0;j<g[i].size();j++) if(g[i][j].first.first==s){
				if(g[i][j].first.second!=a[i]){
					flag=false;break;
				}
			}
		}
		else{
			for(int j=0;j<g[i].size();j++) if(g[i][j].first.first==t){
				if(g[i][j].first.second!=0){
					flag=false;break;
				}
			}
		}
	}
	if(!flag){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++) if(g[i][j].first.first<=n){
			if(g[i][j].first.second==0){
				cout<<g[i][j].first.first<<' '<<i<<'\n';
			}
		}
	}
	return 0;
}