//https://codeforces.com/contest/482/problem/B
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define IOS            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret            return 0
#define pi             3.1415926536
#define hell           1000000007
#define narak          998244353
#define elasped_time 1.0 * clock() / CLOCKS_PER_SEC
const int inf1=1e9;
const ll inf2=1e18;
const int N=100000;
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
struct node{
    int a=0;
    void merge(node &n1,node &n2){
        this->a=n1.a&n2.a;
    }
}nul;
struct update{
  int val=0;
  void combine(update &par,int tl,int tr){
      val|=par.val;
  }
  void apply(node &node){
      node.a|=val;
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
  void build(int v,int start,int end){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          //t[v].a=arr[start];
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,update &val){
      pushdown(v);
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            t[v].a|=val.val;
            apply(val,v); 
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
  }
  int query(int v,int l,int r){
      if(tr[v]<l || tl[v]>r){
          int j=1<<30;
          j--;
          return j;
      }
      pushdown(v);
      if(l<=tl[v] && tr[v]<=r){
         return t[v].a;
      }
      int a=query(2*v,l,r);
      int b=query(2*v+1,l,r);
      return a&b;
  }
public:
  int query(int l,int r){
      return query(1,l,r);
  }
  void upd(int l,int r,update &val){
      return zeno(1,l,r,val);
  }   
};
segtree<node,update> seg;
int solve(){
  int n,m;cin>>n>>m;          
  seg.build(1,1,n);
  int q[m][3];
  update upd;
  rep3(m){
      cin>>q[i][0]>>q[i][1]>>q[i][2];
      if(q[i][2]==0)continue;
      for(int j=29;j>=0;j--){
          if((1<<j)&q[i][2]){
              upd.val=1<<j;
              seg.upd(q[i][0],q[i][1],upd);
          }
      }
  }
  rep3(m){
      int l=q[i][0];
      int r=q[i][1];
      int k=q[i][2];
      if(seg.query(l,r)!=k){
          cout<<"NO"<<endl;ret;
      }
  }
  cout<<"YES"<<endl;
  rep3(n){
      cout<<seg.query(i+1,i+1)<<" ";
  }    
 ret;
}
int main(){
    IOS;
    nul.a=(1<<30);
    nul.a--;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}