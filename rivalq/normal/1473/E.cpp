// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


int solve(){
 	int n,m;cin>>n>>m;
 	vector<pii>g[n+1];
 	rep(i,0,m){
 		int a,b,w;cin>>a>>b>>w;
 		g[a].push_back({b,w});
 		g[b].push_back({a,w});
 	}
 	priority_queue<pair<int,pii>>pq;
 	vector<vector<int>>dis(n+1,vector<int>(4,1e18));
 	// 0-> nothing,1-> 1 extra taken,2-> 1 subtracted,3->both 1 and 2
 	vector<vector<int>>vis(n+1,vector<int>(4));
 	pq.push({0,{1,0}});
 	while(!pq.empty()){
 		pii v = pq.top().y;
 		int w = -pq.top().x;
 		pq.pop();
 		if(vis[v.x][v.y])continue;
 		vis[v.x][v.y]=1;
 		dis[v.x][v.y]=w;
 		for(auto i:g[v.x]){
 			int we = i.y;
 			int u = i.x;
 			if(dis[v.x][v.y]+we<dis[u][v.y]){
 					dis[u][v.y]=dis[v.x][v.y]+we;
 					pq.push({-dis[u][v.y],{u,v.y}});
 			}
 			if(v.y%2==0){
 				int new_state=v.y+1;
 				if(dis[v.x][v.y]+2*we<dis[u][new_state]){
 					dis[u][new_state]=dis[v.x][v.y]+2*we;
 					pq.push({-dis[u][new_state],{u,new_state}});
 				}
 			}
 			if(v.y==1 ||v.y==0){
 				int new_state=v.y+2;
 				if(dis[v.x][v.y]<dis[u][new_state]){
 					dis[u][new_state]=dis[v.x][v.y];
 					pq.push({-dis[u][new_state],{u,new_state}});
 				}
 			}
 			if(v.y==0){
 				int new_state=3;
 				if(dis[v.x][v.y]+we<dis[u][new_state]){
 					dis[u][new_state]=dis[v.x][v.y]+we;
 					pq.push({-dis[u][new_state],{u,new_state}});
 				}	
 			}
 		}
 	}
 	for(int i=2;i<=n;i++){
 		cout<<dis[i][3]<<" ";
 	}cout<<endl;
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