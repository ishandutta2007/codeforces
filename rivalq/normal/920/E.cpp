//https://codeforces.com/contest/920/problem/E
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
const int N=200010;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
set<int> vis;
set<int>s[N];
int cnt=0;
void dfsb(int node,int n){
    cnt++;
    vis.erase(node);
    for(int i=*vis.begin();i<=n;i=*vis.upper_bound(i)){
       if(s[node].count(i)==0)dfsb(i,n);
    }
}
int solve(){
 int n,m;cin>>n>>m;
 rep3(n+1)vis.insert(i+1);
 rep3(m){
     int x,y;cin>>x>>y;
     s[x].insert(y);
     s[y].insert(x);
 }

  vector<int> v;
  for(int j=1;j<=n;j++){
    if(vis.count(j)){  
      cnt=0;
      dfsb(j,n);
      v.pb(cnt);
    } 
  }  
  sort(all(v));cout<<sz(v)<<endl;
  for(auto i:v)cout<<i<<" ";cout<<endl; 
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