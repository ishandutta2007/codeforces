#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
//#define int long long
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

int n,m,val[200010];
vector<pair<int,int> > v[200010],g[200010];
vector<pair<pair<int,int>,int> > e;
bool vis[200010],flag;

inline void dfs(int x,int pr,int now)
{
	val[x]=now;
	for(int i=0;i<v[x].size();i++) if(v[x][i].first!=pr){
		int u=v[x][i].first,d=v[x][i].second;
		if(now==-1||d==-1) dfs(u,x,-1);
		else dfs(u,x,now^d);
	}
}

inline void dfs2(int x,int c)
{
	vis[x]=1;val[x]=c;
	for(int i=0;i<g[x].size()&&flag;i++){
		int u=g[x][i].first,d=g[x][i].second;
		if(val[u]==-1){
			dfs2(u,c^d);
		}
		else{
			if((c^d)==val[u]){
				if(!vis[u]) dfs2(u,c^d);
			}
			else flag=false;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		e.clear();
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			int x,y,c;cin>>x>>y>>c;
			v[x].push_back(make_pair(y,c));
			v[y].push_back(make_pair(x,c));
			e.push_back(make_pair(make_pair(x,y),c));
		}
		dfs(1,-1,0);
		for(int i=1;i<=n;i++) if(val[i]!=-1) val[i]=((__builtin_popcount(val[i]))&1);
		for(int i=1;i<=n;i++) g[i].clear(),vis[i]=0;
		for(int i=1;i<=m;i++){
			int x,y,p;cin>>x>>y>>p;
			g[x].push_back(make_pair(y,p));
			g[y].push_back(make_pair(x,p));
		}
		for(int i=0;i<e.size();i++){
			int x=e[i].first.first,y=e[i].first.second,c=e[i].second;
			if(c!=-1){
				int id=((__builtin_popcount(c))&1);
				g[x].push_back(make_pair(y,id));
				g[y].push_back(make_pair(x,id));
			}
		}
		flag=true;
		for(int i=1;i<=n;i++) if(val[i]!=-1&&!vis[i]){
			dfs2(i,val[i]);
			if(!flag) break;
		}
		if(!flag){
			cout<<"NO\n";
			continue;
		}
		for(int i=1;i<=n;i++) if(!vis[i]){
			dfs2(i,0);
			if(!flag) break;
		}
		if(!flag){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		for(int i=0;i<e.size();i++){
			int x=e[i].first.first,y=e[i].first.second,c=e[i].second;
			if(c==-1){
				int id1=((__builtin_popcount(val[x]))&1);
				int id2=((__builtin_popcount(val[y]))&1);
				if(id1==id2) c=0;
				else c=1;
			}
			cout<<x<<' '<<y<<' '<<c<<'\n';
		}
	}
	return 0;
}