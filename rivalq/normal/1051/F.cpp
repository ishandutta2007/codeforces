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

const int N=2e5+5;
vector<pii>g[N];
int dep[N];
pii dp[N][22];
int te=0;
int tin[N],LOG[N];

void dfs(int u,int p,int l,int h=1){
	dep[u]=l;
	te++;
	tin[u]=te;
	dp[te][0]={h,u};
	for(auto i:g[u]){
		if(i.x!=p){
			dfs(i.x,u,l+i.y,h+1);
			te++;
			dp[te][0]={h,u};
		}
	}

}

int lca(int u,int v){
	int l=min(tin[u],tin[v]);
	int r=max(tin[u],tin[v]);
	int j=LOG[r-l+1];
	pii p=min(dp[l][j],dp[r-(1<<j)+1][j]);
	return p.y;
}
 
int dis(int u,int v){
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
 
int p[N];
int sz[N];
void clear(int n=N){
    rep(i,0,N)p[i]=i,sz[i]=1;
}
int root(int x){
   while(x!=p[x]){
       p[x]=p[p[x]];
       x=p[x];
   }
   return x;  
}
void merge(int x,int y){
    int p1=root(x);
    int p2=root(y);
    if(p1==p2)return;
    if(sz[p1]>=sz[p2]){
        p[p2]=p1;
        sz[p1]+=sz[p2];
    }
    else{
        p[p1]=p2;
        sz[p2]+=sz[p1];
    }
}

vector<int>mp[50];
vector<pii>g2[N];
int cnt=0;
void dijkstra(int u,int n){
	  multiset<pii> pq;
	  vector<int> vi(n+1,0);
	  vector<int> dis(n+1,1e18);
	  dis[u]=0;
	  pq.insert({0,u});
	  while(!pq.empty()){
	      pii v=*pq.begin();
	      pq.erase(pq.begin());
	      int node=v.y;
	      int wei=v.x;
	      if(vi[node])continue;
	      vi[node]=1;
	      for(auto i:g2[node]){
	          int e=i.x;
	          int w=i.y;
	          if(dis[node]+w<dis[e]){
	              dis[e]=dis[node]+w;
	              pq.insert({dis[e],e});
	          }
	      }
	  }
	  mp[cnt]=dis;
	  cnt++;
}


int solve(){
	int n,m;cin>>n>>m;
	set<int>dij;
	clear();
	rep3(m){
		int u,v,d;cin>>u>>v>>d;
		g2[u].pb({v,d});
		g2[v].pb({u,d});
		if(root(u)==root(v)){
			dij.insert(u);
			//dij.insert(v);
		}
		else{
			merge(u,v);
			g[u].pb({v,d});
			g[v].pb({u,d});
		}
	}
	dfs(1,1,0);
 	for(int j=1;j<=20;j++){
 		for(int i=1;i+(1<<(j-1))<=te;i++){
 			dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
 		}
 	}
 	for(auto i:dij)dijkstra(i,n);
 	int q;cin>>q;
 	rep3(q){
 		int u;int v;cin>>u>>v;
 		int ans=dis(u,v);
 		for(int i=0;i<cnt;i++){
 			mins(ans,mp[i][u]+mp[i][v]);
 		}
 		cout<<ans<<endl;
 	}	
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for(int i=2;i<=N;i++){
    	LOG[i]=1+LOG[i/2];
    }
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