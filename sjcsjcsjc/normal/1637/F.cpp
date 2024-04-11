#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000000000000007ll
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

int h[200010],maxv[200010];
vector<int> v[200010];
long long mn,val[200010],now[200010],sum[200010],son[200010];

inline void dfs1(int x,int pr)
{
	int cnt=0;val[x]=0ll;maxv[x]=0;
	for(int i=0;i<v[x].size();i++) if(v[x][i]!=pr){
		dfs1(v[x][i],x);cnt++;
		val[x]+=val[v[x][i]];
		if(maxv[v[x][i]]>maxv[x]){
			val[x]+=1ll*maxv[x];
			maxv[x]=maxv[v[x][i]];
		}
		else val[x]+=1ll*maxv[v[x][i]];
	}
	if(cnt==0){
		maxv[x]=h[x];
		val[x]=0ll;
	}
	else{
		if(maxv[x]<h[x]) maxv[x]=h[x];
	}
}

inline void dfs2(int x,int pr)
{
	now[x]=val[x]+1ll*maxv[x];
	sum[x]=sum[pr]+now[x];
	for(int i=0;i<v[x].size();i++) if(v[x][i]!=pr){
		dfs2(v[x][i],x);
	}
}

inline void dfs3(int x,int pr)
{
	for(int i=0;i<v[x].size();i++) if(v[x][i]!=pr) son[x]+=now[v[x][i]];
	son[x]+=son[pr];
	for(int i=0;i<v[x].size();i++) if(v[x][i]!=pr){
		dfs3(v[x][i],x);
	}
}

inline void dfs4(int x,int pr,int root)
{
	int cnt=0;
	for(int i=0;i<v[x].size();i++) if(v[x][i]!=pr){
		dfs4(v[x][i],x,root);cnt++;
	}
	if(cnt==0){
		mn=min(mn,son[x]-sum[x]+now[root]);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i];
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int mxv=0,pos=0;
	for(int i=1;i<=n;i++){
		if(h[i]>mxv){
			mxv=h[i];pos=i;
		}
	}
	for(int i=0;i<v[pos].size();i++){
		dfs1(v[pos][i],pos);
	}
	for(int i=0;i<v[pos].size();i++){
		dfs2(v[pos][i],pos);
	}
	for(int i=0;i<v[pos].size();i++){
		dfs3(v[pos][i],pos);
	}
	long long ans=0ll;
	vector<long long> g;
	for(int i=0;i<v[pos].size();i++){
		mn=INF;dfs4(v[pos][i],pos,v[pos][i]);
		mn+=1ll*mxv;
		ans+=now[v[pos][i]];
		g.push_back(now[v[pos][i]]-mn);
	}
	sort(g.begin(),g.end());reverse(g.begin(),g.end());
	long long all=INF;
	all=min(all,1ll*mxv+ans-g[0]);
	if(g.size()>1){
		all=min(all,ans-g[0]-g[1]);
	}
	cout<<all<<'\n';
	return 0;
}