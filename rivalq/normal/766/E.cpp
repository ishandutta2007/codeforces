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
/**** LCA PART***/
const int maxn=100005;
set<int> g[maxn];
int p[maxn];
int b_p[maxn][21];
int lvl[maxn];
int sz[maxn];
int temp=0;
int dp[maxn];
int a[maxn];
int ans=0;
int lvl2[maxn];
void dfs(int n=1,int e=0,int l=0){
     lvl[n]^=a[n];
     lvl2[n]=l;
     for(auto i:g[n]){
         if(i!=e){
         	 b_p[i][0]=n;
         	 lvl[i]^=lvl[n];
             dfs(i,n,l+1);
         }
     }
     return;
}
void lift(int n){
     for(int i=1;i<=20;i++){
         for(int j=1;j<=n;j++){
              b_p[j][i]=b_p[b_p[j][i-1]][i-1];
         }
     }
     return;
}
int lca(int u, int v){
   if(lvl2[v]<lvl2[u])u=v+u-(v=u);
   int diff=lvl2[u]-lvl2[v];
   for (int i=20;i >= 0; i--) {
        if (lvl2[v]-lvl2[u] >=(1 << i)) {
            v = b_p[v][i];
        }
   }
   if(v==u){
       return u;
   }
   int k=20;
   while(k>=0){
        if(b_p[u][k]!=b_p[v][k]){
            u=b_p[u][k];
            v=b_p[v][k];
        }
        k--;
   } 
   return b_p[u][0];
}
int d(int u,int v){
	int lc=lca(u,v);
	return lvl[u]^lvl[v]^a[lc];
}
/**** CENTROID DECOMPOSITION****/
void dfs1(int u,int par){
	 sz[u]=1;
	 temp++;
	 for(auto i:g[u]){
	 	if(i!=par){
            dfs1(i,u);
            sz[u]+=sz[i];
	 	}
	 }
}
int dfs2(int u,int par){
	 for(auto i:g[u]){
	 	if(i!=par && sz[i]>temp/2){
             return dfs2(i,u);
	 	}
	 }
	 return u;
}
vector<pii>s; 
int dfs3(int u,int par,int centroid){
    int dis=d(centroid,u);
    ans+=dis;
    dis=dis^a[centroid];
    for(int j=19;j>=0;j--){
        if(dis&(1<<j))ans+=s[j].y*(1<<j);
        else ans+=s[j].x*(1<<j);
    }
    for(auto i:g[u]){
    	if(i!=par)dfs3(i,u,centroid);
    } 
}
void dfs4(int u,int par,int centroid){
    int dis=d(centroid,u);
    for(int j=19;j>=0;j--){
    	if(dis&(1<<j))s[j].x++;
    	else s[j].y++;
    }
    for(auto i:g[u]){
    	if(i!=par)dfs4(i,u,centroid);
    }
}
void decompose(int u,int par){
   temp=0;
   s.clear();
   dfs1(u,u);
   int centroid=dfs2(u,u);
   ans+=a[centroid];
   s.resize(20);
   for(auto i:g[centroid]){
   	   dfs3(i,centroid,centroid);
   	   dfs4(i,centroid,centroid);
   }
   for(auto i:g[centroid]){
   	  g[i].erase(centroid);
   	  decompose(i,centroid);
   } 
   g[centroid].clear();
}
int solve(){
 int n;cin>>n;
 rep(i,1,n+1)cin>>a[i];
 rep3(n-1){
 	int a,b;cin>>a>>b;
 	g[a].insert(b);
 	g[b].insert(a);
 }
 dfs();
 b_p[1][0]=1;
 lift(n);
 decompose(1,-1);
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