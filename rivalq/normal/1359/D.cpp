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
const int N=100005;
struct node{
    int a=0;
    int id=0;
    int mx=0;
    int mn=0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        if(n1.a>=n2.a){
                 a=n1.a;
                 id=n1.id;
        }
        else{
        	a=n2.a;
        	id=n2.id;
        }
        this->mx=max(n1.mx,n2.mx);
        this->mn=min(n1.mn,n2.mn);
    }
}nul;
struct update{
  int val=0;
  update(int t=0){
     val=t;
  }
  void combine(update &par,int tl,int tr){
      val=par.val;
  }
  void apply(node &node){
      node.a=val;
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
  void build(int v,int start,int end,vector<int>&arr,vector<int>&p){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a=arr[start];
          t[v].mx=p[start];
          t[v].mn=p[start];
          t[v].id=tl[v];
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m,arr,p);
          build(2*v+1,m+1,end,arr,p);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,update val){
      pushdown(v);
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            t[v].a=val.val;
            apply(val,v); 
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
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
segtree<node,update>seg;
int solve(){
 	int n;cin>>n;
 	vector<int>a(n+1),p(n+1);
 	rep(i,1,n+1){
 		cin>>a[i];
 		p[i]+=a[i]+p[i-1];
 	}
 	seg.build(1,0,n,a,p);
 	int ans=0;
 	function<int(int,int)> dc=[&](int l,int r){
                  if(l>=r)return 0LL;
                  int id=seg.query(l,r).id;
                  int p2=seg.query(id,r).mx;
                  int p1=seg.query(l-1,id-1).mn;
                  return max({p2-p1-a[id],dc(l,id-1),dc(id+1,r)});
        };
 	cout<<dc(1,n)<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    nul.a=-hell;
    nul.mx=-hell;
    nul.mn=hell;
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