#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

const int N=1005;

vector<pii> g[N];

int solve(){
 	int n,m,k;cin>>n>>m>>k;
 	vector<pii>edges(m+1);
 	rep(i,1,m+1){
 		int u,v,w;cin>>u>>v>>w;
 		g[u].pb({v,w});
 		g[v].pb({u,w});
 		edges[i]={u,v};
 	}
 	vector<vector<int>>dis(n+1,vector<int>(n+1));
 	auto dijikstra=[&](int s){
 		multiset<pii> pq;
 		vector<int>vis(n+1);
 		rep(i,1,n+1)dis[s][i]=1e12;
 		dis[s][s]=0;
 		pq.insert({0,s});
 		while(!pq.empty()){
 		      pii v=*pq.begin();
 		      pq.erase(pq.begin());
 		      int node=v.y;
 		      int wei=v.x;
 		      if(vis[node])continue;
 		      vis[node]=1;
 		      for(auto i:g[node]){
 		          int e=i.x;
 		          int w=i.y;
 		          if(dis[s][node]+w<dis[s][e]){
 		              dis[s][e]=dis[s][node]+w;
 		              pq.insert({dis[s][e],e});
 		          }
 		      }
 		  }
 	};
 	int ans=1e12;
 	rep(i,1,n+1){
 		dijikstra(i);
 	}
 	vector<pii>routes(k+1);
 	rep(i,1,k+1){
 		cin>>routes[i];
 	}
 	rep(i,1,m+1){
 		int c=0;
 		int a=edges[i].x;
 		int b=edges[i].y;
 		rep(j,1,k+1){
 			int u=routes[j].x,v=routes[j].y;
 			int d=min({dis[u][v],dis[a][u]+dis[b][v],dis[b][u]+dis[a][v]});
 			c+=d;
 		}
 		mins(ans,c);
 	}
 	cout<<ans<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}