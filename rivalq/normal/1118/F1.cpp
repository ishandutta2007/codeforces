//https://codeforces.com/contest/1118/problem/F1
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
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int col[3*N+10];
int dp1[3*N+10][2];
int dp2[3*N+10][2];
int cnt=0;
class Graph{
   public: 
   vector<int> *adj;
   int n; 
   Graph(int sz){
       n=sz;
       adj =new vector<int>[n+1];
   }
   void init(int m){
       rep3(m+1)cin>>col[i+1];
       rep3(m){
           int a,b;cin>>a>>b;
           adj[a].pb(b);
           adj[b].pb(a);
       }
   }
   void dfs1(int u=1,int p=0){
       if(col[u]==1)dp1[u][0]++;
       else if(col[u]==2)dp1[u][1]++;
       for(auto i:adj[u]){
           if(i!=p){
               dfs1(i,u);
               dp1[u][0]+=dp1[i][0];
               dp1[u][1]+=dp1[i][1];
           }
       }
   }
   void dfs2(int u=1,int p=0,int c1=0,int c2=0){
       dp2[u][0]+=dp1[u][0]+c1;
       dp2[u][1]+=dp1[u][1]+c2;
       for(auto i:adj[u]){
           if(i!=p){
               int r1=dp2[u][0]-dp1[i][0];
               int b1=dp2[u][1]-dp1[i][1];
               if((r1==0 || b1==0) && (dp1[i][0]==0 || dp1[i][1]==0 )){
                   cnt++;
               }
               dfs2(i,u,r1,b1);
           }
       }
   }
   
};
int solve(){
  int n;cin>>n;
  Graph g(n);
  g.init(n-1);
  g.dfs1();
  g.dfs2();
  cout<<cnt<<endl;    
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