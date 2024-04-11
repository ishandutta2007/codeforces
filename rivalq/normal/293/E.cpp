#include<cstdio>
#include<vector>
#include <algorithm>
#include <string.h>
using namespace std;
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
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


template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
int n,l,w;
const int maxn=100005;
vector<pii> g[maxn];
ll ans=0;
int ctree[maxn];
int sz[maxn];
int temp=0;
vector<pii>store;
vector<pii>vec;
int vis[maxn];
struct Fenwick{
    int tree[maxn]={0};
    int query(int i){
       int sum=0;
       for(int j=i+1;j>=1;j-=(j&(-j))){
          sum+=tree[j];
       }
       return sum;
    }
    void update(int i,int val){
        for(int j=i+1;j<maxn;j+=(j&(-j))){
            tree[j]+=val;
        }
    }
};
Fenwick fn;
ll calc(vector<pii>&v){
	  ll cnt=0;
    int n=sz(v);
    sort(all(v),[&](pii p1,pii p2){return p1.y<p2.y;});
    for(auto i:v)fn.update(i.x,1);
    for(int i=0,j=n-1;i<n;i++){
        while(j>=i && v[j].y+v[i].y>w){
        	   fn.update(v[j].x,-1);
        	   j--;
        }
        if(j<i)break;
        fn.update(v[i].x,-1);
        cnt+=fn.query(l-v[i].x);
    }
    return cnt;
}
/**** CENTROID DECOMPOSITION****/
void dfs1(int u,int par){
	 sz[u]=1;
	 temp++;
	 for(auto i:g[u]){
	 	if(vis[i.x])continue;
	 	if(i.x!=par){
            dfs1(i.x,u);
            sz[u]+=sz[i.x];
	 	}
	 }
}
int dfs2(int u,int par){
	 for(auto i:g[u]){
	 	if(vis[i.x])continue;
	 	if(i.x!=par && sz[i.x]>temp/2){
             return dfs2(i.x,u);
	 	}
	 }
	 return u;
}
void dfs3(int u,int p,int lt,int wt){
	int l_cen=lt;int w_cen=wt;
  vec.eb(l_cen,w_cen);  
	for(auto i:g[u]){
		if(vis[i.x])continue;
		if(i.x!=p)dfs3(i.x,u,lt+1,wt+i.y);
	}
}
void decompose(int u,int par){
   temp=0;vec.clear(); dfs1(u,u);
   int centroid=dfs2(u,u);vis[centroid]=1;
   dfs3(centroid,par,0,0);ans+=calc(vec);
   for(auto i:g[centroid]){
       if(vis[i.x])continue;vec.clear();
       dfs3(i.x,centroid,1,i.y);ans-=calc(vec);
   }
   for(auto i:g[centroid]){
   	  if(vis[i.x])continue;decompose(i.x,centroid);
   } 
}
void solve(){
 scanf("%d%d%d",&n,&l,&w);	
 rep(i,2,n+1){
     int p,w;
     scanf("%d%d",&p,&w);
     g[p].pb({i,w});
     g[i].pb({p,w});
 }
 decompose(1,-1);
 printf("%lld\n",ans);
}
signed main(){
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