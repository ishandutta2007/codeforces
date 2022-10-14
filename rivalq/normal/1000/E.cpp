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

const int maxn=2000005;
int p[maxn];
int sz[maxn];
vector<int>vec[N];
vector<int>g[N];
vector<int>sg[N];
set<pii>bridges;


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

int dp[N];
int vis[N];
int dep[N];


void dfs(int u,int p){
		vis[u]=1;
 		for(auto i:g[u]){
 			if(i!=p){
 				if(vis[i]){
 					if(dep[i]<dep[u]){
 						dp[u]++;
 						
 					}
 					else{
 						dp[u]--;
 					}
 				}
 				else{	
 					dep[i]=dep[u]+1;
 					dfs(i,u);
 					dp[u]+=dp[i];
 				}
 			}
 		}
 		if(u!=1 && dp[u]==0){
 			bridges.insert({min(p,u),max(p,u)});
 		}
}


int solve(){
 	int n,m;cin>>n>>m;
 	rep(i,0,m){
 		int a,b;cin>>a>>b;
 		g[a].pb(b);
 		g[b].pb(a);
 	}
 	dfs(1,0);
 	clear(n);
 	for(int i=1;i<=n;i++){
 		for(auto j:g[i]){
 			if(j<i)continue;
 			if(bridges.count(make_pair(i,j)))continue;
 			merge(i,j);
 		}
 	}
 	for(int i=1;i<=n;i++){
 		for(auto j:g[i]){
 			if(root(i)==root(j))continue;
 			sg[root(i)].pb(root(j));
 		}
 	}
 	int mx=0,j=-1;
 	function<void(int,int,int)>dia=[&](int u,int p,int h){
 		if(mx<h){
 			mx=h;
 			j=u;
 		}
 		for(auto i:sg[u]){
 			if(i!=p){
 				dia(i,u,h+1);
 			}	
 		}
 	};
 	dia(root(1),0,0);
 	dia(j,j,0);
 	cout<<mx<<endl;
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