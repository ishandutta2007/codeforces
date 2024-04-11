#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
//#define int            long long
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


// min wait segtree



vector<int>v={4,7,44,47,74,77,444,447,474,477,744,747,774,777,4444,4447,4474,4477,4744,4747,4774,4777,7444,7447,7474,7477,7744,7747,7774,7777,hell};

auto f=[&](int x){
	int j=lower_bound(all(v),x)-v.begin();
	return v[j]-x;
};

const int N=1e5+5;


struct node{
    int wait=0;
    int cnt=0;
    int a=0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->wait=min(n1.wait,n2.wait);
        cnt=0;
        if(n1.wait==wait)cnt+=n1.cnt;
        if(n2.wait==wait)cnt+=n2.cnt;
    }
};
struct update{
  int val=0;
  update(int t=0){
     val=t;
  }
  void combine(update &par,int tl,int tr){
      val+=par.val;
  }
  void apply(node &node){
      node.a+=val;
      node.wait-=val;
      assert(node.wait>=0);
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
          zaker[2*v].combine(u,tl[2*v],tr[2*v]);
          zaker[2*v+1].combine(u,tl[2*v+1],tr[2*v+1]);
      }
  }
  void build(int v,int start,int end,int arr[]){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a=arr[start];
          t[v].wait=f(t[v].a);
          t[v].cnt=1;
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
      if(l<=tl[v] && tr[v]<=r && t[v].wait>=val.val){
      	    t[v].wait-=val.val;
      	    t[v].a+=val.val;
            apply(val,v); 
            return;
      }
      if(tl[v]==tr[v]){
      		assert(lazy[v]==0);
      		t[v].a+=val.val;
      		t[v].wait=f(t[v].a);
      		assert(t[v].wait>=0);
      		return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
  }
  int query(int v,int l,int r){
      if(tr[v]<l || tl[v]>r)return 0;
      pushdown(v);
      if(l<=tl[v] && tr[v]<=r){
         return (t[v].wait==0)?t[v].cnt:0;
      }
      int a=query(2*v,l,r);
      int b=query(2*v+1,l,r);
      return a+b;
  }
public:
  int query(int l,int r){
      return query(1,l,r);
  }
  void upd(int l,int r,update val){
      return zeno(1,l,r,val);
  }   
};



int a[N];



segtree<node,update>seg;


int solve(){
 	int n,m;cin>>n>>m;
 	rep(i,1,n+1){
 		cin>>a[i];
 	}
 	seg.build(1,1,n,a);
 	rep(i,0,m){
 		string s;int l,r;cin>>s>>l>>r;
 		if(s=="count")cout<<seg.query(l,r)<<endl;
 		else {
 			int d;cin>>d;
 			seg.upd(l,r,d);
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