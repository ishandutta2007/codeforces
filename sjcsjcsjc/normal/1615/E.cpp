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

int n,k,tot,sz[200010],a[200010],id[200010];
vector<int> v[200010];
priority_queue<int> q[200010];

inline void dfs(int x,int pr)
{
	sz[x]=1;
	vector<int> res;
	int mx=0,pos=-1;
	for(int i=0;i<v[x].size();i++) if(v[x][i]!=pr){
		dfs(v[x][i],x);
		res.push_back(v[x][i]);
		sz[x]+=sz[v[x][i]];
		if(sz[v[x][i]]>mx){
			mx=sz[v[x][i]];
			pos=v[x][i];
		}
	}
	if(pos==-1){
		id[x]=x;
		q[id[x]].push(1);
	}
	else{
		id[x]=id[pos];
		for(int i=0;i<res.size();i++) if(res[i]!=pos){
			int u=res[i];
			while(!q[id[u]].empty()){
				int t=q[id[u]].top();
				q[id[u]].pop();
				q[id[x]].push(t);
			}
		}
		q[id[x]].push(0);
		int t=q[id[x]].top();
		q[id[x]].pop();
		q[id[x]].push(t+1);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,-1);
	vector<int> x;
	while(!q[id[1]].empty()){
		int t=q[id[1]].top();
		q[id[1]].pop();
		x.push_back(t);
	}
	reverse(x.begin(),x.end());
	a[n]=0;
	for(int i=0;i<x.size();i++) a[n-i-1]=a[n-i]+x[i];
	long long ans=-INF;
	for(int i=0;i<=k;i++){
		int r=i,b=min(a[i],n/2),w=n-r-b;
		ans=max(ans,1ll*w*(r-b));
	}
	cout<<ans<<'\n';
	return 0;
}