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
struct node{
    int a=0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->a=min(n1.a,n2.a);
    }
}nul;
template<typename node>
struct segtree{
  node *t;
  void resize(int n){
  	   t=new  node[4*n];
  }
  void build(int32_t v,int32_t start,int32_t end,vector<int> &arr){
      if(start==end){
          t[v].a=arr[start];
      }
      else{
          int32_t m=(start+end)/2;
          build(2*v,start,m,arr);
          build(2*v+1,m+1,end,arr);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  node query(int32_t v,int32_t l,int32_t r,int32_t tl,int32_t tr){
      if(tr<l || tl>r)return nul;
      if(l<=tl && tr<=r){
         return t[v];
      }
      int mid=(tl+tr)/2;
      node a=query(2*v,l,r,tl,mid);
      node b=query(2*v+1,l,r,mid+1,tr);
      node ans;
      ans.merge(a,b);
      return ans;
  }
public:
  node query(int32_t l,int32_t r,int32_t tl,int32_t tr){
      return query(1,l,r,tl,tr);
  }
};
const int maxn=500005;
set<pii> g[maxn];
int32_t p[maxn];
int32_t b_p[maxn][21];
int level[maxn];
int32_t lvl2[maxn];
vector<int>leaves;
void dfs(int32_t n,int32_t e,int l){
     p[n]=e;
     level[n]=l;
     if(g[n].size()==1)leaves.pb(n);
     for(auto i:g[n]){
         if(i.x!=e){
         	 lvl2[i.x]=lvl2[n]+1;
         	 int w=i.y;
             dfs(i.x,n,l+w);
         }
     }
     return;
}
void lift(int32_t n){
     for(int i=0;i<=20;i++){
         for(int j=1;j<=n;j++){
             if(i==0)b_p[j][i]=p[j];
             else b_p[j][i]=b_p[b_p[j][i-1]][i-1];
         }
     }
     return;
}
int32_t lca(int32_t u, int32_t v){
   if(lvl2[v]<lvl2[u])u=v+u-(v=u);
   int32_t diff=lvl2[u]-lvl2[v];
   for (int i=20;i >= 0; i--) {
        if (lvl2[v]-lvl2[u] >=(1 << i)) {
            v = b_p[v][i];
        }
   }
   if(v==u){
       return u;
   }
   int32_t k=ceil(log2(lvl2[u]));
   while(k>=0){
        if(b_p[u][k]!=b_p[v][k]){
            u=b_p[u][k];
            v=b_p[v][k];
        }
        k--;
   } 
   return p[u];

}
int d(int32_t u,int32_t v){
	return level[u]+level[v]-2*level[lca(u,v)];
}
int32_t ctree[maxn];
int32_t sz[maxn];
int32_t temp=0;
vector<int32_t>cen[maxn];
/**** CENTROID DECOMPOSITION****/
void dfs1(int u,int par){
	 sz[u]=1;
	 temp++;
	 for(auto i:g[u]){
	 	if(i.x!=par){
            dfs1(i.x,u);
            sz[u]+=sz[i.x];
	 	}
	 }
}
int dfs2(int u,int par){
	 for(auto i:g[u]){
	 	if(i.x!=par && sz[i.x]>temp/2){
             return dfs2(i.x,u);
	 	}
	 }
	 return u;
}
void decompose(int u,int par){
   temp=0;
   dfs1(u,u);
   int centroid=dfs2(u,u);
   if(par<=0)par=centroid;
   ctree[centroid]=par;
   for(auto i:g[centroid]){
   	  g[i.x].erase({centroid,i.y});
   	  decompose(i.x,centroid);
   } 
   g[centroid].clear();
}
unordered_map<int,segtree<node>>seg;
void process(int32_t n){
	for(auto i:leaves){
		int32_t x=i;
		while(1){
			cen[x].pb(i);
			if(x==ctree[x])break;
			x=ctree[x];
		}
	}
	for(int32_t i=1;i<=n;i++){
		if(cen[i].empty())continue;
		vector<int>temp;
		sort(all(cen[i]));
		for(auto j:cen[i])temp.pb(d(i,j));
		seg[i].resize(sz(temp));
		seg[i].build(1,0,sz(temp)-1,temp);	
	}

}
int query(int32_t x,int32_t l,int32_t r){
	int32_t u=x;
	int mi=1e18;
	while(1){
       int val=d(x,u);
       if(cen[u].empty() || cen[u].front()>r || cen[u].back()<l){
       	  if(u==ctree[u]||ctree[u]==0)break;
       	  u=ctree[u];
       }
       else{
       	  int32_t l2=lower_bound(all(cen[u]),l)-cen[u].begin();
       	  int32_t r2=upper_bound(all(cen[u]),r)-cen[u].begin();
       	  r2--;
       	  //cout<<l2<<" "<<r2<<" "<<u<<endl;
       	  mins(mi,val+seg[u].query(l2,r2,0,sz(cen[u])-1).a);
          if(u==ctree[u] || ctree[u]==0)break;
          u=ctree[u];
       }
	}
	return mi;
}
#undef int
int solve(){
 int n,q;cin>>n>>q;
 rep3(n-1){
 	int p,w;cin>>p>>w;
 	g[i+2].insert({p,w});
 	g[p].insert({i+2,w});
 }
 dfs(1,0,0);
 lift(n);
 decompose(1,-1);
 process(n);
 for(int i=1;i<=q;i++){
 	int v,l,r;cin>>v>>l>>r;
 	cout<<query(v,l,r)<<endl;
 }
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
    nul.a=1e18;
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}