//https://codeforces.com/problemset/problem/620/E
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
const int inf1=1e9;
const ll inf2=1e18;
const int N=1000000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
vector<int> g[N];
ll eulerpath[1000000];
map<int,vector<int>> mp;
int cur=1;
void dfs(int u=1,int p=-1){
    eulerpath[cur]=u;
    cur++;
    for(auto i:g[u]){
        if(i!=p){
            dfs(i,u);
            eulerpath[cur]=u;cur++;
        }
    }
}
struct node{
    ll a=0;
    node (ll val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->a=n1.a|n2.a;
    }
};
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
segtree<node,update> t;
int fun(ll val){
    int cnt=0;
    while(val){
        cnt+=(val%2);
        val=val/2;
    }
    return cnt;
}
int solve(){
  int n,q;cin>>n>>q;          
  ll c[n+1];rep3(n)cin>>c[i+1];
  rep3(n-1){
      int a,b;cin>>a>>b;
      g[a].pb(b);
      g[b].pb(a);
  }
  dfs();
  for(int i=1;i<cur;i++){
      mp[eulerpath[i]].pb(i);
      //cout<<eulerpath[i]<<" ";
      eulerpath[i]=(1LL<<c[eulerpath[i]]);
  }
  t.build(1,1,cur-1,eulerpath);
  rep3(q){
      int ty;cin>>ty;
      if(ty==1){
          ll v,c;cin>>v>>c;
          int idx1=mp[v].front();
          int idx2=mp[v].back();
          update u;
          u.val=(1LL<<c);
          t.upd(idx1,idx2,u);
      }
      else{
          int v;cin>>v;
          int idx1=mp[v].front();
          int idx2=mp[v].back();
          node val=t.query(idx1,idx2);
          cout<<fun(val.a)<<endl;
        }
  }
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