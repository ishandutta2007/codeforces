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
const int N=200005;
int lvl[N];
vector<int>g[N];
int id[N];
int tim=0;
int tin[N],tout[N];
int a[N];
int id2[N];
void dfs(int u,int p){
	 tin[u]=++tim;
	 id[tim]=u;
	 for(auto i:g[u]){
	 	if(i!=p){
	 		lvl[i]=1+lvl[u];
	 		dfs(i,u);
	 	}
	 }
	 tout[u]=tim;
}
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

struct node{
    int a=0;
    int lvl=0;
    node(int val=0){}
    void merge(node &n1,node &n2){
        //this->a=min(n1.a,n2.a);
        this->a=n1.a+n2.a;
    }
};
struct update{
  int val=0;
  int lvl=0;
  update(int t=0){
     val=t;
  }
  void combine(update &par,int tl,int tr,int lvln){
       val+=par.val;
  }
  void apply(node &node){
      node.a+=val;
      val=0;
  }
};
template<typename node,typename update>
struct segtree{
  node t[4*N];
  bool lazy[4*N];
  update zaker[4*N];
  int tl[4*N];
  int tr[4*N];
  node nul;
  inline void pushdown(int v){
     if(lazy[v]){    
       apply(zaker[v],v);
       lazy[v]=0;
       zaker[v].apply(t[v]);
     }
  }
  inline void apply(update &u,int v){
      if(tl[v]!=tr[v]){
          lazy[2*v]=lazy[2*v+1]=1;
          zaker[2*v].combine(u,tl[2*v],tr[2*v],t[2*v].lvl);
          zaker[2*v+1].combine(u,tl[2*v+1],tr[2*v+1],t[2*v+1].lvl);
      }
  }
  void build(int v,int start,int end,int arr[]){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a=a[arr[start]];
          t[v].lvl=lvl[arr[start]];
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m,arr);
          build(2*v+1,m+1,end,arr);
          //t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,update val){
      pushdown(v);
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            zaker[v].combine(val,tl[v],tr[v],t[v].lvl);
            zaker[v].apply(t[v]);
            apply(val,v); 
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
  }
  node query(int v,int l,int r){
      if(tr[v]<l || tl[v]>r)return nul;
      pushdown(v);
      if(l<=tl[v] && tr[v]<=r){
         return t[v];
      }
      node a=query(2*v,l,r);
      node b=query(2*v+1,l,r);
      node ans;
      ans.merge(a,b);
      return ans;
  }
public:
  node query(int l,int r){
      return query(1,l,r);
  }
  void upd(int l,int r,update val){
      return zeno(1,l,r,val);
  }   
};
segtree<node,update> seg,seg2;
int solve(){
 int n,q;cin>>n>>q;
 rep(i,1,n+1)cin>>a[i];
 rep3(n-1){
 	int a,b;cin>>a>>b;
 	g[a].pb(b);
 	g[b].pb(a);
 }
 dfs(1,0);
 seg.build(1,1,tim,id); //odd levels
 seg2.build(1,1,tim,id); // even levels;
 rep3(q){
 	int t,x;cin>>t>>x;
 	if(t==1){
 		int val;cin>>val;
 		update upd;
 		if(lvl[x]&1){
 			upd.val=val;
 			seg.upd(tin[x],tout[x],upd);
 			upd.val=-val;
 			seg2.upd(tin[x],tout[x],upd);
 		} 
 		else{
 			upd.val=-val;
 			seg.upd(tin[x],tout[x],upd);
 			upd.val=val;
 			seg2.upd(tin[x],tout[x],upd);
 		}
 	}
 	else{
 		if(lvl[x]&1){
 			cout<<seg.query(tin[x],tin[x]).a<<endl;
 		}
 		else{
 			cout<<seg2.query(tin[x],tin[x]).a<<endl;
 		}
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