//https://codeforces.com/contest/744/problem/A
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
int solve(){
 int n,m,k;cin>>n>>m>>k;    
 int isg[n+1]={0};
 rep3(k){
     int t;cin>>t;
     isg[t]=1;
 }
 vector<int> g[n+1];         
 rep3(m){
     int a,b;cin>>a>>b;
     g[a].pb(b);
     g[b].pb(a);
 }
 pii ng={0,0};
 vector<pii> gov;
 int ans=0;
  int visit[n+1]={0};
   int ma=-1;
   for(int i=1;i<=n;i++){
       if(!visit[i]){
           int cnt=1;
           int cnt2=0;
           queue<int> q;
           q.push(i);
           int is=0;
           while(!q.empty()){
               int v=q.front();
               q.pop();
               visit[v]=1;
               if(isg[v])is=1;
               for(auto j:g[v]){
                   cnt2++;
                   if(!visit[j]){
                       visit[j]=1;
                       q.push(j);
                       cnt++;
                   }
               }
           }
          if(is==1){
              gov.pb({cnt,cnt2/2});
              ans=ans+(cnt*(cnt-1)/2)-cnt2/2;
          }
          else{
              ng.x+=cnt;
              ng.y+=cnt2/2;
          }
       }
      
 }
 int j=ans;  
 for(int i=0;i<sz(gov);i++){
     int cnt=gov[i].x;
     int cnt2=2*gov[i].y;
     int k=(ng.x+gov[i].x)*(ng.x+gov[i].x-1)/2-ng.y-(cnt*(cnt-1)/2);
     ans=max(ans,j+k);
 }
 cout<<ans<<endl;
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