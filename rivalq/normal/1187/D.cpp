//https://codeforces.com/contest/1187/problem/D
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
const int N=3*100000;
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
struct node{
    ll a=0;
    node (ll val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->a=min(n1.a,n2.a);
    }
}nul(hell);
struct update{
  ll val=0;
  update(ll t=0){
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
  void build(int v,int start,int end,ll arr[]){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a=arr[start];
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
            //apply(val,v); 
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
segtree<node,update> seg;
map<int,queue<int>>mp;
int solve(){
 mp.clear();   
 int n;cin>>n;           
 ll a[n+1],b[n+1];
 rep3(n)cin>>a[i+1];
 rep3(n)cin>>b[i+1];
 for(int i=1;i<=n;i++){
     mp[a[i]].push(i);
 }
 update upd;
 upd.val=inf1;
 for(int i=1;i<=n;i++){
    seg.upd(i,i,upd);
 }
 seg.build(1,1,n,a);           
 int temp=-1;
 int j=1;
 for(int i=1;i<=n;i++){
     if(a[j]==b[i]){
         mp[a[j]].pop();
         j++;
         while(seg.query(j,j).a==inf1)j++;
         continue;
     }
     int val=b[i];
     if(mp[val].empty()){
         cout<<"NO"<<endl;ret;
     }
     int idx=mp[val].front();
     mp[val].pop();
     int q=seg.query(j,idx).a;
     //cout<<j<<" "<<idx<<" "<<q<<endl;
     if(q!=val){
         cout<<"NO"<<endl;ret;
     }
     update upd;
     upd.val=inf1;
     seg.upd(idx,idx,upd);
     temp=idx;
 }
 cout<<"YES"<<endl;
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}