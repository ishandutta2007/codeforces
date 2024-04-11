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

int n,m,k,dist[1010][1010],a[1010],b[1010];
vector<pair<int,int> > v[1010],e;

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,w;cin>>x>>y>>w;
		v[x].push_back(make_pair(y,w));
		v[y].push_back(make_pair(x,w));
		e.push_back(make_pair(x,y));
	}
	for(int i=1;i<=k;i++) cin>>a[i]>>b[i]; 
	for(int i=1;i<=n;i++){
		priority_queue<pair<int,int> > q;
		for(int j=1;j<=n;j++) dist[i][j]=INF;
		dist[i][i]=0;
		q.push(make_pair(0,i));
		while(!q.empty()){
			pair<int,int> t=q.top();q.pop();
			if(-t.first!=dist[i][t.second]) continue;
			for(int j=0;j<v[t.second].size();j++){
				int x=v[t.second][j].first,d=v[t.second][j].second;
				if(dist[i][x]>dist[i][t.second]+d){
					dist[i][x]=dist[i][t.second]+d;
					q.push(make_pair(-dist[i][x],x));
				}
			}
		}
	}
	int ans=INF;
	for(int i=1;i<=m;i++){
		int x=e[i-1].first,y=e[i-1].second;
		int val=0;
		for(int j=1;j<=k;j++){
			int now=dist[a[j]][b[j]];
			now=min(now,dist[a[j]][x]+dist[b[j]][y]);
			now=min(now,dist[a[j]][y]+dist[b[j]][x]);
			val+=now;
		}
		ans=min(ans,val);
	}
	cout<<ans<<endl;
	return 0;
}