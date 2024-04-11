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



const int N=3e5+5;

int p[N];
int sz[N];
vector<int>g[N];
vector<int>sg[N];
set<pii>bridges;
int val[N]; 
 
void clear(int n){
    rep(i,0,n+1)p[i]=i,sz[i]=1;
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
 
int dp[N][2];
int vis[N];
int dep[N];
 
 
int b_dp[N];

void dfs(int u,int p){
		vis[u]=1;
 		for(auto i:g[u]){
 			if(i!=p){
 				if(vis[i]){
 					if(dep[i]<dep[u]){
 						b_dp[u]++;
 						
 					}
 					else{
 						b_dp[u]--;
 					}
 				}
 				else{	
 					dep[i]=dep[u]+1;
 					dfs(i,u);
 					b_dp[u]+=b_dp[i];
 				}
 			}
 		}
 		if(u!=1 && b_dp[u]==0){
 			bridges.insert({min(p,u),max(p,u)});
 		}
}
 








int solve(){
 	int n,m;cin>>n>>m;
 	vector<int>a(n+1);
 	vector<pii>edges(m);
 	rep(i,1,n+1){
 		cin>>a[i];
 	}
 	rep(i,0,m){
 		int a,b;cin>>a>>b;
 		g[a].pb(b);
 		g[b].pb(a);
 		edges[i].x=min(a,b);
 		edges[i].y=max(a,b);
 	}
 	int s;cin>>s;
 	dfs(1,1);
 	clear(n);
 	rep(i,0,m){
 		if(!bridges.count(edges[i])){
 			merge(edges[i].x,edges[i].y);
 		}
 	}
 	int ans=0;
 	vector<int>cnt(n+1);
 	for(int i=1;i<=n;i++){
 		for(auto j:g[i]){
 			if(root(i)==root(j))continue;
 			sg[root(i)].pb(root(j));
 		}
 		cnt[root(i)]++;
 		val[root(i)]+=a[i];
 	}
 	int mx=0;
 	vector<int>canret(n+1);
 	function<void(int,int)>dfs2=[&](int u,int p){
 			dp[u][1]=val[u];
 			canret[u]=(cnt[u]>1);
 			for(auto i:sg[u]){
 				if(i!=p){
 					dfs2(i,u);
 					dp[u][1]+=dp[i][1];
 					maxs(dp[u][0],dp[i][0]-dp[i][1]);
 					canret[u]|=canret[i];
 				}
 			}
 			dp[u][0]+=dp[u][1];
 			if(canret[u]==0)dp[u][1]=0;
 	};
 	dfs2(root(s),0);
 	cout<<dp[root(s)][0]<<endl;
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