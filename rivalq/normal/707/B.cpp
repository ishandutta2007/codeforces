//https://codeforces.com/problemset/problem/707/B
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
#define hell 1000000007L
using namespace std;
set<pair<ll,ll>> q;
ll dist[100001]={0};
void bfs(vector<pii> g[],int s){
  for(auto i:g[s]){
      if(dist[s]+i.sc<dist[i.fr]){
         auto it = q.find({ dist[i.fr], i.fr }); 
            q.erase(it); 
            dist[i.fr] = dist[s] + i.sc; 
            q.insert({ dist[i.fr], i.fr }); 
      }
  }
   if (q.size() == 0) 
        return;
    auto it = q.begin(); 
    int next = it->second; 
    q.erase(it); 
  
    bfs(g,next); 
}
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int solve(){
  int n,m,k,a,b,w;cin>>n>>m>>k;
  vector<pii> g[n+1];
  lop(i,m,1){
      cin>>a>>b>>w;
      g[a].pb({b,w});
      g[b].pb({a,w});
  }
  if(k==0){
      cout<<-1<<endl;
      ret;
  }
  int bakery[n+1]={0};
  lop(i,k,1){
      int t;cin>>t;
      bakery[t]=1;
  }
  
 
  for(int i=1;i<=n;i++){
      if(bakery[i])q.insert({0,i});
      else q.insert({10*hell,i}),dist[i]=10*hell;
  }
  int s=q.begin()->sc;
  bfs(g,s);
  ll mi=hell;
  for(auto i:dist){
      if(i){
          mi=min(i,mi);
      }
  }
  if(mi==hell)mi=-1;
  cout<<mi<<endl;
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