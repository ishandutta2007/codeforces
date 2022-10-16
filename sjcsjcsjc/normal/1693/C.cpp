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

int n,m,deg[200010],val[200010];
vector<int> v[200010],g[200010];
bool vis[200010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		if(x!=n){
			v[x].push_back(y);
			g[y].push_back(x);
			deg[x]++;
		} 
	}
	for(int i=1;i<=n;i++) val[i]=INF;
	priority_queue<pair<int,int> > q;q.push(make_pair(0,n));val[n]=0;
	while(!q.empty()){
		pair<int,int> t=q.top();q.pop();
		if(-t.first!=val[t.second]) continue;
		for(int i=0;i<g[t.second].size();i++){
			int u=g[t.second][i];deg[u]--;
			int now=val[t.second]+1+deg[u];
			if(val[u]>now){
				val[u]=now;
				q.push(make_pair(-val[u],u));
			}
		}
	}
	cout<<val[1]<<'\n';
	return 0;
}