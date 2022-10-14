//https://codeforces.com/problemset/problem/375/D
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
const int N=300000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
vector<int>g[N];
vector<int>eulerpath;
int first[N];
int last[N];
int col[N];
int bl[N];
int ans[N];
struct query{
    int l,r,id,k;
    bool operator<(const query &rhs){
        return (bl[l]==bl[rhs.l])?r<rhs.r:bl[l]<bl[rhs.l];
    }
}q[N];
int ff[N];
int f[N];
int vis[N];
void dfs(int u=1,int p=0){
  eulerpath.pb(u);
  first[u]=eulerpath.size();
  first[u]--;
  for(auto i:g[u]){
      if(i!=p){
          dfs(i,u);
      }
  }
  last[u]=eulerpath.size();
  last[u]--;
}
inline void check(int u){
  if(vis[u]){
      ff[f[col[u]]]--;
      f[col[u]]--;
  }
  else{
     f[col[u]]++;
     ff[f[col[u]]]++; 
  }
  vis[u]=1-vis[u];
}
void compute(int m){
    int cl=q[0].l,cr=q[0].l-1;
    for(int i=0;i<m;i++){
      while(cl<q[i].l)check(eulerpath[cl++]);
      while(cl>q[i].l)check(eulerpath[--cl]);
      while(cr<q[i].r)check(eulerpath[++cr]);
      while(cr>q[i].r)check(eulerpath[cr--]);
      ans[q[i].id]=ff[q[i].k];
      //cout<<cl<<" "<<cr<<" "<<q[i].id<<endl;
    }
    for(int i=0;i<m;i++)cout<<ans[i]<<endl;
}
int solve(){
 int n,m;cin>>n>>m;           
 rep3(n)cin>>col[i+1];
 rep3(n-1){
     int a,b;cin>>a>>b;
     g[a].pb(b);
     g[b].pb(a);
 }
 int block=sqrt(n);
 dfs();
 /**for(auto i:eulerpath){
     cout<<i<<" ";
 }
 cout<<endl;
 for(int i=1;i<=n;i++){
     cout<<first[i]<<" "<<last[i]<<endl;
 }**/
 for(int i=0;i<eulerpath.size();i++)bl[i]=i/block;
 rep3(m){
  int v,k;cin>>v>>k;
  int l=first[v];
  int r=last[v];
  q[i].l=l;q[i].r=r;q[i].k=k;q[i].id=i;
 }           
 sort(q,q+m);
 compute(m);
 ret;
}
int main(){
    IOS;
    eulerpath.pb(-1);
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