#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
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

int n,m,q,maxv,dist[610][610],u[360010],v[360010],l[360010];
vector<pair<int,pair<int,int> > > e;
vector<pair<int,int> > g[610];
bool ok[610][610];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n+1;i++) for(int j=1;j<=n+1;j++) dist[i][j]=INF;
	for(int i=1;i<=n+1;i++) dist[i][i]=0;
	for(int i=1;i<=m;i++){
		int x,y,w;cin>>x>>y>>w;
		dist[x][y]=dist[y][x]=w;
		e.push_back(make_pair(w,make_pair(x,y)));
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>u[i]>>v[i]>>l[i];
		maxv=max(maxv,l[i]);
		g[u[i]].push_back(make_pair(v[i],l[i]));
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++) if(!g[i].empty()){
		for(int j=1;j<=n;j++){
			dist[j][n+1]=INF;
			for(int k=0;k<g[i].size();k++) dist[j][n+1]=min(dist[j][n+1],dist[j][g[i][k].first]+maxv-g[i][k].second);
		}
		for(int j=0;j<e.size();j++){
			if(dist[i][e[j].second.first]+e[j].first+dist[e[j].second.second][n+1]<=maxv){
				ok[e[j].second.first][e[j].second.second]=1;
				ok[e[j].second.second][e[j].second.first]=1;
			}
			else if(dist[i][e[j].second.second]+e[j].first+dist[e[j].second.first][n+1]<=maxv){
				ok[e[j].second.first][e[j].second.second]=1;
				ok[e[j].second.second][e[j].second.first]=1;
			}
		}
	}
	int cnt=0;
	for(int i=0;i<e.size();i++){
		if(ok[e[i].second.first][e[i].second.second]) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}