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

int n,m,cnt,tot,pos[400010],a[400010],b[400010],deg[400010];
vector<vector<char> > c;
vector<vector<int> > id;
vector<int> v[400010],rev[400010],g[400010],res;
bool vis[400010];

inline void dfs1(int x)
{
	vis[x]=1;
	for(int i=0;i<v[x].size();i++) if(!vis[v[x][i]]){
		dfs1(v[x][i]);
	}
	res.push_back(x);
}

inline void dfs2(int x,int num)
{
	vis[x]=1;b[x]=num;
	for(int i=0;i<rev[x].size();i++) if(!vis[rev[x][i]]){
		dfs2(rev[x][i],num);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	c.resize(n+1,vector<char>(m+1,'.'));
	id.resize(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		pos[i]=n+1;
		for(int j=1;j<=n;j++) if(c[j][i]=='#'){
			pos[i]=j;break;
		}
		for(int j=pos[i];j<=n;j++){
			id[j][i]=++cnt;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=pos[i];j<=n;j++){
			if(j>pos[i]&&c[j-1][i]=='#'){
				v[id[j][i]].push_back(id[j-1][i]);
				rev[id[j-1][i]].push_back(id[j][i]);
			}
			if(j<n){
				v[id[j][i]].push_back(id[j+1][i]);
				rev[id[j+1][i]].push_back(id[j][i]);
			}
			if(i>1&&c[j][i-1]=='#'){
				v[id[j][i]].push_back(id[j][i-1]);
				rev[id[j][i-1]].push_back(id[j][i]); 
			}
			if(i<m&&c[j][i+1]=='#'){
				v[id[j][i]].push_back(id[j][i+1]);
				rev[id[j][i+1]].push_back(id[j][i]);
			}
		}
	}
	for(int i=1;i<=cnt;i++) if(!vis[i]) dfs1(i);
	memset(vis,0,sizeof(vis));
	for(int i=res.size()-1;i>=0;i--) if(!vis[res[i]]){
		tot++;dfs2(res[i],tot);
	}
	for(int i=1;i<=cnt;i++){
		for(int j=0;j<v[i].size();j++) if(b[i]!=b[v[i][j]]){
			g[b[i]].push_back(b[v[i][j]]);
			deg[b[v[i][j]]]++;
		}
	}
	int ans=0;
	for(int i=1;i<=tot;i++) if(deg[i]==0) ans++;
	cout<<ans<<endl;
	return 0;
}