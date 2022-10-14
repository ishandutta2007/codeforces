//https://codeforces.com/problemset/problem/277/A
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
int solve(){
  int n,m;cin>>n>>m;
  vector<int> v[m+1];
  int f=0;
  lop(i,n,1){
      int k;cin>>k;
      if(k)f=1;
      lop(j,k,1){
          int l;cin>>l;
          v[l].pb({i+1});
      }
  }
  /*for(auto i:v){
      for(auto j:i)cout<<j<<" ";cout<<endl;
  }*/
  set<int> g[n+1];
  for(int i=1;i<=m;i++){
      int n=v[i].size();
      if(n==1)continue;
      for(int j=0;j<n-1;j++){
          g[v[i][j]].insert({v[i][j+1]});
          g[v[i][j+1]].insert({v[i][j]});
      }
  }
  int cnt=0;
  int visit[n+1]={0};
  for(int i=1;i<=n;i++){
      if(!visit[i]){
      queue<int> q;
       q.push(i);
       visit[i]=1;
       while(!q.empty()){
           int v=q.front();
           q.pop();
           visit[v]=1;
           for(auto j:g[v]){
               if(!visit[j]){
                   visit[j]=1;
                   q.push(j);
               }
           }
       }
       cnt++;
      }
  } 
 if(f==0)cnt++; 
 cout<<cnt-1<<endl;
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