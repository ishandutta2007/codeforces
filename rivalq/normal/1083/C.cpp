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

const int N=4e5+5;

vector<int>g[N];
int p[N];int d[N];
int par[N],dis[N];
pii dp[N][21];
int tin[N],tout[N];
int LOG[N];
int c=0;

void dfs(int u=1,int p=1){
	tin[u]=++c;par[u]=p;
	dp[c][0]={dis[u],u};
	for(auto i:g[u]){
		if(i!=p){
			dis[i]=dis[u]+1;
			dfs(i,u);
			dp[++c][0]={dis[u],u};
		}
	}
}
pii get_min(int l,int r){
	int x=LOG[r-l+1];
	return min(dp[l][x],dp[r-(1<<x)+1][x]);
}
int lca(int u,int v){
	int l=min(tin[u],tin[v]);
	int r=max(tin[u],tin[v]);
	return get_min(l,r).y;
}
int dist(int u,int v){
	return dis[u]+dis[v]-2*dis[lca(u,v)];
}
int func(int u,int v){
	if(u==v)return 1;
	if(tin[u]<=tin[v] && tout[v]<=tout[u]){
		return 1;
	}
	return 0;
}
void sort(vector<int>&v){
	sort(all(v),[&](int u,int v){return tin[u]<tin[v];});
}

struct node{
   bool f=0;
   int u=0,v=0;
   void merge(node p,node q){
   	 f=0;
   	 if(p.f && q.f){
   	 	pair<int,pii>pp={-1,{-1,-1}};
   	 	vector<int>vec={p.u,p.v,q.u,q.v};
   	 	for(int i=0;i<4;i++){
   	 		for(int j=i+1;j<4;j++){
   	 			pair<int,pii>temp={dist(vec[i],vec[j]),{vec[i],vec[j]}};
   	 			maxs(pp,temp);
   	 		}
   	 	}
   	 	u=pp.y.x;
   	 	v=pp.y.y;
   	 	for(int i=0;i<4;i++){
   	 		int d=dist(u,vec[i])+dist(vec[i],v);
   	 		if(d!=pp.x){
   	 			return;
   	 		}
   	 	}
   	 	f=1;
   	 }
   }
   
};
template<typename node>
struct segtree{
  node t[4*N];
  int tl[4*N];
  int tr[4*N];
  void build(int v,int start,int end,int arr[]){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
      	  t[v].f=1;
          t[v].v=t[v].u=arr[start];
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m,arr);
          build(2*v+1,m+1,end,arr);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,int val){
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
      	    t[v].u=t[v].v=val;		
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
  }
  int query(int v){
       if(t[v].f)return tr[v]+1;
       while(t[2*v].f==0)v=2*v;
       if(tl[v]==tr[v])return tl[v];
       node p=t[2*v];
       v=2*v+1;
       while(tl[v]!=tr[v]){
       	     node q;
       	     q.merge(p,t[2*v]);
       	     if(q.f)v=2*v+1,p=q;
       	     else v=2*v;
       }
       return tl[v];
  }
public:
  int query(){
      return query(1);
  }
  void upd(int l,int r,int val){
      return zeno(1,l,r,val);
  }   
};

segtree<node>seg;
int solve(){
 	int n;cin>>n;
 	rep(i,1,n+1){
 		cin>>p[i];
 		d[p[i]]=i;
 	}
 	rep(i,2,n+1){
 		int p;cin>>p;
 		g[p].pb(i);
 		g[i].pb(p);
 	}
 	dfs();
 	for(int i=2;i<N;i++){
 		LOG[i]=LOG[i/2]+1;
 	}
 	for(int i=1;i<=LOG[2*n];i++){
 		for(int j=1;j+(1<<(i-1))<=2*n;j++){
 			dp[j][i]=min(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
 		}
 	}
        seg.build(1,0,n-1,d);
 	int q;cin>>q;
 	rep3(q){
 		int t;cin>>t;
 		if(t==1){
 			int x,y;cin>>x>>y;
 			d[p[x]]=y;d[p[y]]=x;
 			seg.upd(p[x],p[x],y);
 			seg.upd(p[y],p[y],x);
 			swap(p[x],p[y]);
 		}
 		else{
 			cout<<seg.query()<<endl;
 		}
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
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}