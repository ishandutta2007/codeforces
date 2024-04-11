//https://codeforces.com/problemset/problem/131/D
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define inarr(arr,n) lop(i,n,1)cin>>arr[i]
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define eb emplace_back
#define fr first
#define sc second
#define pii pair<int,int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define hell 1000000007
using namespace std;
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
vector<int> cycle;
vector<int> g[3000+1];
int par[3000+1];
void dfs_cycle(int s,int p,int color []){
    if(color[s]==2){
        return;
    }
    if(color[s]==1){
        int cur=p;
        cycle.pb(p);
        while(cur!=s){
            cur=par[cur];
            cycle.pb(cur);
        }
        return ;
    }
    par[s]=p;
    color[s]=1;
    for(auto i:g[s]){
        if(p==i)continue;
        dfs_cycle(i,s,color);
    }
    color[s]=2;
}
int solve(){
  int n;cin>>n;
  
  lop(i,n,1){
      int a,b;cin>>a>>b;
      g[a].pb(b);
      g[b].pb(a);
  }
  int color[n+1]={0};
  dfs_cycle(1,0,color);
  int visit[n+1]={0};
  int level[n+1]={0};
  for(auto i:cycle){
      visit[i]=1;     
  }
  for(auto i:cycle){
      stack<int> s;
      s.push(i);
      while(!s.empty()){
       int v=s.top();
       s.pop();
       for(auto j:g[v]){
           if(visit[j]==0){
               visit[j]=1;
               level[j]=1+level[v];
               s.push(j);
           }
       }
      }
  }
  for(int i=1;i<=n;i++)cout<<level[i]<<" ";cout<<endl;
  ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}