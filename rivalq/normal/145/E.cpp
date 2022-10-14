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

const int N=1000005;
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
struct node{
    int a=0; // pairs;
    int a2=0; //opposite pairs;
    int cnt1=0;
    int cnt2=0;
    node (int val=0){
    }
    void merge(node &n1,node &n2){
         a=max({n1.cnt1+n2.a,n1.a+n2.cnt2,n1.cnt1+n2.cnt2});
         a2=max({n1.cnt2+n2.a2,n1.a2+n2.cnt1,n1.cnt2+n2.cnt1});
         cnt1=n1.cnt1+n2.cnt1;
         cnt2=n1.cnt2+n2.cnt2;
    }
};
struct update{
  int val=0;
  update(int t=0){
     val=t;
  }
  void combine(update &par,int tl,int tr){
      
  }
  void apply(node &node){
       swap(node.a,node.a2);
       swap(node.cnt1,node.cnt2);
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
          if(lazy[2*v])lazy[2*v]=0;
          else lazy[2*v]=1;
          if(lazy[2*v+1])lazy[2*v+1]=0;
          else lazy[2*v+1]=1;
      }
  }
  void build(int v,int start,int end,string &arr){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
      	  t[v].a=1;
      	  t[v].a2=1;
          if(arr[start]=='4')t[v].cnt1=1;
          else t[v].cnt2=1;
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
      	    if(lazy[v]==0)zaker[v].apply(t[v]);
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
update upd;
int solve(){
 int n,q;cin>>n>>q;
 string s;cin>>s;
 seg.build(1,0,n-1,s);
 rep3(q){
 	string t;cin>>t;
 	if(t=="switch"){
 		int l,r;cin>>l>>r;
 	    seg.upd(l-1,r-1,upd);	
 	}
 	else{
 		cout<<seg.t[1].a<<endl;
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