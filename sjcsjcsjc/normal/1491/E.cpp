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

int n,mx,f[100],par[200010],sz[200010];
vector<int> v[200010],res;
bool vis[200010];

inline void dfs(int x,int pr)
{
	par[x]=pr;
	for(int i=0;i<v[x].size();i++) if(v[x][i]!=pr){
		dfs(v[x][i],x);
	}
}

inline void dfs2(int x,int pr)
{
	res.push_back(x);sz[x]=1;
	for(int i=0;i<v[x].size();i++) if(v[x][i]!=pr&&!vis[v[x][i]]){
		dfs2(v[x][i],x);
		sz[x]+=sz[v[x][i]];
	}
}

inline bool dfs1(int x,int pr,int id)
{
	if(id<=3) return true;
	res.clear();dfs2(x,pr);
	int pos=-1;
	for(int i=0;i<res.size();i++){
		if(sz[res[i]]==f[id-2]||sz[res[i]]==f[id-1]){
			pos=res[i];break;
		}
	}
	if(pos==-1) return false;
	vis[pos]=1;
	if(sz[pos]==f[id-1]){
		if(!dfs1(x,pr,id-2)) return false;
		if(!dfs1(pos,par[pos],id-1)) return false;
		return true;
	}
	else{
		if(!dfs1(x,pr,id-1)) return false;
		if(!dfs1(pos,par[pos],id-2)) return false;
		return true;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	f[0]=1;f[1]=1;mx=1;
	for(int i=2;;i++){
		if(f[i-2]+f[i-1]>n) break;
		f[i]=f[i-2]+f[i-1];mx=i;
	}
	if(n!=f[mx]){
		cout<<"NO\n";
		return 0;
	}
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,-1);
	int ans=dfs1(1,-1,mx);
	if(ans) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}