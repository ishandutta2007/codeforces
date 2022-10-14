//https://codeforces.com/contest/1093/problem/D
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
#define narak 998244353
using namespace std;
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
ll xymodp(ll x,ll y,ll p){
    ll a=1;
    x%=p;
    while(y){
        if(y&1)a=(a*x)%p;
        x=(x*x)%p;
        y/=2;
    }
    return a;
}

int solve(){
  int n,m,a,b;cin>>n>>m;
  vector<int> g[n+1];
  lop(i,m,1){
    cin>>a>>b;
    g[a].pb(b);
    g[b].pb(a);
  }
  ll ans=1;
  int vis[n+1]={0},f=1;
for(int i=1;i<=n;i++){ 
 if(vis[i]==0){
  int cnt=1;       
  queue<int> q;
  q.push(i);
  vis[i]=1;
  ll odd=1,even=0;
  while(!q.empty()){
      int v=q.front();
      q.pop();
      for(auto i:g[v]){
          if(vis[i]==vis[v]){
              f=0;goto l;
          }
          if(vis[i]==0){
              cnt++;
              if(vis[v]==1)vis[i]=2,even++;
              else vis[i]=1,odd++;
              q.push(i);
          }
      }
  }
   if(cnt==1)ans=(ans*3)%narak;
   else{
      ll k=xymodp(2,odd,narak)+xymodp(2,even,narak);
      ans=(ans*k)%narak; 
   }
 }
} 
  l:
  if(f==0){
      cout<<0<<endl;
  }
  else{
      cout<<ans<<endl;
  }
  
  ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}