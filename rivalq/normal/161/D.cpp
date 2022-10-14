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
const int maxn=100005;
set<int> g[maxn];
int p[maxn];
int b_p[maxn][21];
int level[maxn];
int k;
void dfs(int n=1,int e=1,int l=0){
     p[n]=e;
     level[n]=l;
     for(auto i:g[n]){
         if(i!=e){
             dfs(i,n,l+1);
         }
     }
     return;
}
void lift(int n){
     for(int i=0;i<=20;i++){
         for(int j=1;j<=n;j++){
             if(i==0)b_p[j][i]=p[j];
             else b_p[j][i]=b_p[b_p[j][i-1]][i-1];
         }
     }
     return;
}
int lca(int u, int v){
   if(level[v]<level[u])u=v+u-(v=u);
   int diff=level[u]-level[v];
   for (int i=20;i >= 0; i--) {
        if (level[v]-level[u] >=(1 << i)) {
            v = b_p[v][i];
        }
   }
   if(v==u){
       return u;
   }
   int k=ceil(log2(level[u]));
   while(k>=0){
        if(b_p[u][k]!=b_p[v][k]){
            u=b_p[u][k];
            v=b_p[v][k];
        }
        k--;
   } 
   return p[u];

}
int d(int u,int v){
	return level[u]+level[v]-2*level[lca(u,v)];
}
int ctree[maxn];
int temp=0;
int sz[maxn];
map<int,int>mp;
map<int,int>mp2;
int ans=0;
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
void dfs3(int u,int centroid,int par){
     int dis=d(u,centroid);
     int req=k-dis;
     if(mp.count(req))ans+=mp[req];
     mp2[dis]++;
     for(auto i:g[u]){
     	if(i!=par){
     		dfs3(i,centroid,u);
     	}
     }

}
void decompose(int u,int par){
   temp=0;
   dfs1(u,u);
   mp.clear();
   mp[0]++;
   int centroid=dfs2(u,u);
   if(par==-1)par=u;
   ctree[u]=par;
   for(auto i:g[centroid]){
   	 dfs3(i,centroid,centroid);
   	 for(auto i:mp2)mp[i.x]+=i.y;
   	 mp2.clear();	
   }
   for(auto i:g[centroid]){
   	  g[i].erase(centroid);
   	  decompose(i,centroid);
   } 
   g[centroid].clear();
}
int solve(){
 int n;cin>>n>>k;
 rep3(n-1){
 	int a,b;
 	cin>>a>>b;
 	g[a].insert(b);
 	g[b].insert(a);
 }
 dfs();
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