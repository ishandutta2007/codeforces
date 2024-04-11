//https://codeforces.com/contest/1304/problem/F1
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
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
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int dp[100][N];
int n,m,k;
int pre[100][N];
struct node{
    int a=0;
    node (ll val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->a=max(n1.a,n2.a);
    }
}nul;
struct update{
  int val=0;
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
  node t[N];
  int tl[N];
  int tr[N];
  void build(int v,int start,int end){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          //t[v].a=arr[start];
          t[v].a=-inf1;
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,update val){
      //pushdown(v);
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
segtree<node,update>seg1,seg2;
int zeno(int i,int j){
    if(i>n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int t=zeno(i+1,1);
    int pmax[m+10]={0};
    int smax[m+10]={0};
    for(int x=1;x<=m-k+1;x++)pmax[x]=max(dp[i+1][x],pmax[x-1]);
    for(int x=m-k+1;x>=1;x--)smax[x]=max(dp[i+1][x],smax[x+1]);
    for(int x=1;x<=m-k+1;x++){
        update upd;
        upd.val=dp[i+1][x]-pre[i+1][x+k-1];
        seg1.upd(x,x,upd);
    }
    for(int x=1;x<=m;x++){
        update upd;
        upd.val=dp[i+1][x]+pre[i+1][x-1];
        seg2.upd(x,x,upd);
    }
    for(int z=1;z<=m-k+1;z++){
          int sum=pre[i][z+k-1]-pre[i][z-1];
          dp[i][z]=max(dp[i][z],sum+smax[z+k]+pre[i+1][z+k-1]-pre[i+1][z-1]); 
          dp[i][z]=max(dp[i][z],pmax[max(0,z-k)]+sum+pre[i+1][z+k-1]-pre[i+1][z-1]);
          /**for(int x=max(1,z-k+1);x<=z;x++){
            dp[i][z]=max(dp[i][z],sum+dp[i+1][x]+(pre[i+1][z+k-1]-pre[i+1][x+k-1]));
          }***/
          dp[i][z]=max(dp[i][z],sum+pre[i+1][z+k-1]+seg1.query(max(1,z-k+1),z).a);
          dp[i][z]=max(dp[i][z],sum-pre[i+1][z-1]+seg2.query(z+1,z+k-1).a);

          /**for(int x=z+1;x<=z+k-1;x++){
            dp[i][z]=max(dp[i][z],sum+dp[i+1][x]+pre[i+1][x-1]-pre[i+1][z-1]);
          }**/

    } 
    return dp[i][j];
}
int solve(){
  cin>>n>>m>>k;   
  mem1(dp); 
  nul.a=-inf1; 
  seg1.build(1,1,m-k+1);  
  seg2.build(1,1,m-k+1);   
  for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
          cin>>pre[i][j];
          pre[i][j]+=pre[i][j-1];
      }
  }    
  int ans=zeno(1,1);
  for(int i=1;i<=m-k+1;i++)ans=max(ans,dp[1][i]);
  cout<<ans<<endl;
 ret;
}
int main(){
    IOS;
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