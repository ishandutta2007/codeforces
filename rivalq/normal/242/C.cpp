//https://codeforces.com/contest/242/problem/C
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
int dirs[8][2] ={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
int solve(){
  int x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;  
  int n;cin>>n;          
  set<pii> s1;
  rep3(n){
      int x,y1,y2;
      cin>>x>>y1>>y2;
      for(int j=y1;j<=y2;j++){
          s1.insert({x,j});
      }  
  }
  map<pii,vector<pii>>mp;
  for(auto i:s1){
      int x=i.x,y=i.y;
      for(int k=0;k<8;k++){
          int xd=x+dirs[k][0];
          int yd=y+dirs[k][1];
          pii p={xd,yd};
          if(pres(s1,p)){
             mp[{x,y}].pb(p);
          }
      }
  }
   map<pii,int> visit;
   queue<pii> q;
   map<pii,int>level;
   q.push({x1,y1});
   level[{x1,y1}]=0;
   while(!q.empty()){
    pii p=q.front();
    q.pop();
    visit[p]=1;
    for(auto j:mp[p]){
      if(!visit[j]){
         visit[j]=1;
          q.push(j);
            level[j]=level[p]+1;           
         }
      }
    }
   if(!visit[{x2,y2}]){
       cout<<-1<<endl;ret;
   }    
   cout<<level[{x2,y2}]<<endl;
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