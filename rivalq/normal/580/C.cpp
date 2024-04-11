//https://codeforces.com/problemset/problem/580/C
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
const int N=1e5 +10;
int cats[N];
vector<int> g[N];
int m;
int ans=0;
void dfs(int s,int c,int e,int m){
  //cout<<m<<endl;  
  
  if(cats[s-1])c++;
  if(c>m)return;  
  bool leaf=true;
  for(auto i: g[s]){
    if(i!=e){
      //cout<<"*"<<i<<endl;   
      leaf=false;   
      if(cats[i-1])dfs(i,c,s,m);
      else dfs(i,0,s,m);
    } 
  }
  if(leaf){
      ans++;
      return;
  }   

}
int solve(){
  int n,m;cin>>n>>m;
  inarr(cats,n);
  lop(i,n-1,1){
    int a,b;
    cin>>a>>b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(1,0,0,m);
  cout<<ans<<endl;
 
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