//https://codeforces.com/problemset/problem/474/E
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
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
struct node{
    ll a=0;
    int idx=0;
    node (ll val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->a=max(n1.a,n2.a);
        if(this->a==n1.a)this->idx=n1.idx;
        else idx=n2.idx;
    }
}nul;
struct update{
  ll val=0;
  ll idx=0;
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
  int tl[4*N];
  int tr[4*N];
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
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            if(val.val>t[v].a){
                t[v].a=val.val;
                t[v].idx=val.idx;
            }
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
  }
  node query(int v,int l,int r){
      if(l>r)return nul;
      if(tr[v]<l || tl[v]>r)return nul;
      //pushdown(v);
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
int solve(){
  int n;cin>>n;   
  ll d;cin>>d;       
  ll h[n+1];
  rep3(n)cin>>h[i+1];
  ordered_set s1;
  rep(i,1,n+1)s1.insert(h[i]);
  seg.build(1,1,sz(s1));
  int dp[n+1]={0};
  int p[n+1]={0};
  for(int i=n;i>=1;i--){
      int idx1=s1.order_of_key(h[i]-d);
      int idx2=s1.order_of_key(h[i]+d)+1;
      if(pres(s1,h[i]-d))idx1++;
      //if(pres(s1,h[i]+d))idx2--;
      auto m1=seg.query(1,idx1);
      auto m2=seg.query(idx2,sz(s1));
      if(m1.a>m2.a){
         dp[i]=m1.a+1;
         p[i]=m1.idx; 
      }
      else{
          dp[i]=m2.a+1;
          p[i]=m2.idx;
      }
      int idx=s1.order_of_key(h[i])+1;
      update upd;
      upd.val=dp[i];
      upd.idx=i;
      seg.upd(idx,idx,upd);
  }
  int ma=0;
  int j;
  for(int i=1;i<=n;i++){
      if(ma<dp[i]){
          ma=dp[i];
          j=i;
      }
  }
  cout<<ma<<endl;
  while(ma--){
      cout<<j<<" ";
      j=p[j];
  }
 ret;
}
int main(){
    IOS;
    nul.a=0;
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