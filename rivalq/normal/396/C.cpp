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
template<int mod>
struct mint {
  int x;
  mint():x(0){}
  mint(int x):x((x%mod+mod)%mod){}
  // mint(int x):x(x){}
  mint& fix() { x = (x%mod+mod)%mod; return *this;}
  mint operator-() const { return mint(0) - *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}

  friend istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
  friend ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}
  mint<mod> expo(mint<mod> x,int y){
       mint<mod> a=1;
       while(y){
       	 if(y&1)a=a*x;
       	 x=x*x;
       	 y/=2;
       }
       return a;
  }
};
template<int mod>
int operator+=(int& b,mint<mod> a){return b=b+a.x;};
const int N=300005;
int tim=0;
int id[N],tin[N],tout[N];
vector<int>g[N];
int lvl[N];
void dfs(int u=1,int p=0){
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


struct node{
    mint<hell> a=0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->a=n1.a+n2.a;
    }
};
struct update{
  mint<hell> val=0;
  update(int t=0){
     val=t;
  }
  void combine(update &par,int tl,int tr){
      val+=par.val;
  }
  void apply(node &node,int tl,int tr){
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
       zaker[v].apply(t[v],tl[v],tr[v]);
     }
  }
  inline void apply(update &u,int v){
      if(tl[v]!=tr[v]){
          lazy[2*v]=lazy[2*v+1]=1;
          zaker[2*v].combine(u,tl[2*v],tr[2*v]);
          zaker[2*v+1].combine(u,tl[2*v+1],tr[2*v+1]);
      }
  }
  void build(int v,int start,int end){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a=0;
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,update val){
      pushdown(v);
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            t[v].a+=val.val;
            apply(val,v); 
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
  }
  mint<hell> query(int v,int l,int r){
      if(tr[v]<l || tl[v]>r)return 0;
      pushdown(v);
      if(l<=tl[v] && tr[v]<=r){
         return t[v].a;
      }
      mint<hell> a=query(2*v,l,r);
      mint<hell> b=query(2*v+1,l,r);
      return a+b;
  }
public:
  mint<hell> query(int l,int r){
      return query(1,l,r);
  }
  void upd(int l,int r,update val){
      return zeno(1,l,r,val);
  }   
};
segtree<node,update>seg1,seg2;
int solve(){
 int n;cin>>n;
 rep3(n-1){
 	int p;cin>>p;
 	g[p].pb(i+2);
    g[i+2].pb(p);
 }
 dfs();
 seg1.build(1,1,tim);
 seg2.build(1,1,tim);
 int q;cin>>q;
 rep3(q){
 	int t;cin>>t;
    if(t==1){
    	int v,x,k;cin>>v>>x>>k;
    	int l=tin[v];
    	int r=tout[v];
    	update upd;
    	upd.val=x+lvl[v]*k;
    	seg1.upd(l,r,upd);
    	upd.val=k;
    	seg2.upd(l,r,upd);
    }
    else{
    	int v;cin>>v;
    	cout<<seg1.query(tin[v],tin[v])-seg2.query(tin[v],tin[v])*lvl[v]<<endl;
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