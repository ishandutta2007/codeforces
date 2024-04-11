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

int a[300010],pos[300010],nw[300010];
pair<int,int> v[300010];
bool vis[300010];

inline void dfs(int x)
{
	vis[x]=1;
	if(!vis[nw[x]]) dfs(nw[x]);
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		for(int i=0;i<n;i++) v[i].first=0,v[i].second=i;
		for(int i=1;i<=n;i++) cin>>a[i],pos[a[i]]=i;
		for(int i=1;i<=n;i++){
			if(pos[i]>=i) v[pos[i]-i].first++;
			else v[n+pos[i]-i].first++;
		}
		sort(v,v+n);reverse(v,v+n);
		vector<int> g;
		for(int i=0;i<3;i++){
			int x=v[i].second;
			for(int j=1;j<=n;j++){
				if(j>x) nw[j]=pos[j-x];
				else nw[j]=pos[n+j-x];
			}
			for(int j=1;j<=n;j++) vis[j]=0;
			int cnt=0;
			for(int j=1;j<=n;j++) if(!vis[j]){
				dfs(j);cnt++;
			}
			if(cnt>=n-m) g.push_back(x);
		}
		if(!g.empty()){
			sort(g.begin(),g.end());
		}
		cout<<g.size()<<' ';
		for(int i=0;i<g.size();i++) cout<<g[i]<<' ';
		cout<<'\n';
	}
	return 0;
}