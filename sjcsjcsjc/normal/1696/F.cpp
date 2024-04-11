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

int n,val[110][110][110],tot[110],r[110][110],par[110],dist[110][110];
vector<int> res,v[110],u[110],g[110][110];
bool vis[110];

inline void dfs(int x)
{
	res.push_back(x);vis[x]=1;
	for(int i=0;i<v[x].size();i++) if(!vis[v[x][i]]){
		dfs(v[x][i]);
	}
}

inline void dfs2(int x,int id,int pr,int dis)
{
	dist[id][x]=dis;
	for(int i=0;i<u[x].size();i++) if(u[x][i]!=pr){
		dfs2(u[x][i],id,x,dis+1);
	}
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) val[i][j][j]=1;
		for(int i=1;i<=n-1;i++){
			for(int j=1;j<=n-i;j++){
				for(int k=1;k<=n;k++){
					char ch;cin>>ch;
					val[k][i][i+j]=val[k][i+j][i]=ch-'0';
				}
			}
		}
		bool flag=true;
		for(int i=1;i<=n&&flag;i++){
			for(int j=1;j<=n;j++) v[j].clear(),vis[j]=0;
			for(int j=1;j<=n;j++) if(j!=i){
				for(int k=j+1;k<=n;k++) if(k!=i){
					if(val[i][j][k]){
						v[j].push_back(k);
						v[k].push_back(j);
					}
				}
			}
			tot[i]=0;
			for(int j=1;j<=n&&flag;j++) if(j!=i&&!vis[j]){
				res.clear();dfs(j);
				bool ok=true;
				for(int k=0;k<res.size()&&ok;k++){
					for(int l=k+1;l<res.size()&&ok;l++){
						if(!val[i][res[k]][res[l]]) ok=false;
					}
				}
				if(!ok) flag=false;
				tot[i]++;g[i][tot[i]]=res;
				for(int k=0;k<res.size();k++) r[i][res[k]]=tot[i];
			}
		}
		if(!flag){
			cout<<"No\n";
			continue;
		}
		bool found=false;
		for(int i=1;i<=tot[1]&&!found;i++){
			for(int j=1;j<=n;j++) u[j].clear(),par[j]=-1;
			par[1]=0;
			for(int j=0;j<g[1][i].size();j++){
				u[1].push_back(g[1][i][j]);
				u[g[1][i][j]].push_back(1);
				par[g[1][i][j]]=1;
			}
			queue<int> q;
			bool ok=true;int cur=1;
			for(int j=0;j<g[1][i].size();j++) q.push(g[1][i][j]);
			while(!q.empty()&&ok){
				int x=q.front();q.pop();cur++;
				int pr=par[x];
				int id=r[x][pr];
				for(int j=0;j<g[x][id].size()&&ok;j++){
					int now=g[x][id][j];
					if(now==pr) continue;
					if(par[now]!=-1) ok=false;
					u[x].push_back(now);
					u[now].push_back(x);
					par[now]=x;q.push(now);
				}
			}
			if(ok&&cur==n){
				for(int j=1;j<=n;j++){
					dfs2(j,j,-1,0);
				}
				bool check=true;
				for(int j=1;j<=n&&check;j++){
					for(int k=1;k<=n&&check;k++){
						for(int l=1;l<=n&&check;l++){
							if((dist[j][k]==dist[j][l])!=val[j][k][l]) check=false;
						}
					}
				}
				if(check){
					cout<<"Yes\n";
					for(int j=1;j<=n;j++){
						for(int k=0;k<u[j].size();k++) if(j<u[j][k]){
							cout<<j<<' '<<u[j][k]<<'\n';
						}
					}
					found=true;
				}
			}
		}
		if(!found) cout<<"No\n";
	}
	return 0;
}