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

struct node{
    int a=0;
    int b=0;
    int c=0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->a=min(n1.a,n2.a);
        this->b=n1.b+n2.b;
    }
};
struct update{
  int val=0;
  update(int t=0){
     val=t;
  }
  void combine(update &par,int tl,int tr){
      val=par.val;
  }
  void apply(node &node,int r){
      node.a=val;
      node.b=r*val;
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
       zaker[v].apply(t[v],tr[v]-tl[v]+1);
     }
  }
  inline void apply(update &u,int v){
      if(tl[v]!=tr[v]){
          lazy[2*v]=lazy[2*v+1]=1;
          zaker[2*v].combine(u,tl[2*v],tr[2*v]);
          zaker[2*v+1].combine(u,tl[2*v+1],tr[2*v+1]);
      }
  }
  void build(int v,int start,int end,int arr[]){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a=arr[start];
          t[v].b=arr[start];
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m,arr);
          build(2*v+1,m+1,end,arr);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,update val){
      pushdown(v);
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
      	    t[v].a=val.val;	
            t[v].b=val.val*(tr[v]-tl[v]+1);
            apply(val,v); 
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
  }
  int first_less(int v,int val){
  	while(tl[v]!=tr[v]){
  		pushdown(2*v);pushdown(2*v+1);
  		if(t[2*v].a>=val)v=2*v+1;
  		else v=2*v;
  	}
  	return tl[v];
  }
  void query(int v,int l,int &rem,int &cnt){
      if(tr[v]<l || rem<t[v].a)return;
      pushdown(v);
      if(l<=tl[v] && t[v].b<=rem){
      	 rem-=t[v].b;
      	 cnt+=tr[v]-tl[v]+1;
         return;
      }
      if(tl[v]==tr[v])return;
      query(2*v,l,rem,cnt);
      query(2*v+1,l,rem,cnt);
  }
  int get(int v,int x){
  		while(tl[v]!=tr[v]){
  			pushdown(2*v),pushdown(2*v+1);
  			int mid=(tl[v]+tr[v])/2;
  			if(mid>=x)v=2*v;
  			else v=2*v+1;
  		}
  		return t[v].b;
  }
public:
  void query(int l,int &rem,int &cnt){
      return query(1,l,rem,cnt);
  }
  void upd(int l,int r,update val){
      return zeno(1,l,r,val);
  }   
};


segtree<node,update>seg;

int a[N];

int solve(){
 		int n,q;cin>>n>>q;
 		rep(i,1,n+1){
 			cin>>a[i];
 		}
 		seg.build(1,1,n,a);
 		rep(i,0,q){
 			int t;cin>>t;
 			if(t==1){
 				int x,y;cin>>x>>y;
 				int j=seg.first_less(1,y);
 				if(j<=x)seg.upd(j,x,y);
 			}
 			else{
 				int x,y;cin>>x>>y;
 				int cnt=0;
 				seg.query(x,y,cnt);
 				cout<<cnt<<endl;
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