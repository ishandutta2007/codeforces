//https://codeforces.com/contest/550/problem/B
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
/***********void sieve(int isprime[],int n){
   memset(isprime,1,sizeof(isprime));
   for(int p=2;p*p<=n;p++){
       if(isprime[p]==1){
           for(int i=p*p;i<=n;i+=p){
               isprime[i]=0;
           }
       }
   }
}*********/
int n,l,r,x;
int arr[15];
map<string,int>mp;
vector<string> mp1;
int cnt=0;
int check(string s){
     int mi=hell,ma=0,sum=0;
     for(int i=0;i<n;i++){
         if(s[i]=='1'){
          sum+=arr[i];
          mi=min(mi,arr[i]);
          ma=max(ma,arr[i]);
         }
     }
     if(mi==ma)return 0;
     if(sum>=l && sum<=r && ma-mi>=x) return 1;
     else return 0;
}
void dfs(string vis,int j){
      
      if(j==n)return;
      string s1=vis;
      s1[j]='1';
      if(j==n-1){
          mp1.pb(s1);
          mp1.pb(vis);
          return ;
      }
      else{
      dfs(vis,j+1);
      dfs(s1,j+1);
      }
}
int solve(){
  cin>>n>>l>>r>>x;
  inarr(arr,n);
  string vis="";
  lop(i,n,1)vis+='0';
 
  
   dfs(vis,0);
   int cnt=0;
   for(auto i:mp1){
      if(check(i))cnt++;
   }
  
  
  cout<<cnt<<endl;
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