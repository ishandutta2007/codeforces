//https://codeforces.com/contest/1196/problem/D2
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
int dp[2*N+10][3];
// R-->0,G-->1,2-->B;
int zaker(int i,int f,string &s,int n){
    if(i==n){
        return 0;
    }
    if(dp[i][f]!=-1)return dp[i][f];
    int c=(s[i]=='R')?0:(s[i]=='G')?1:2;
    return dp[i][f]=( (c!=f)+zaker(i+1,(f+1)%3,s,n));

}
int solve(){
  int n,k;cin>>n>>k;  
  string s;cin>>s;          
  int mi=n;
  for(int i=0;i<=n;i++)dp[i][0]=dp[i][1]=dp[i][2]=-1;
  //cout<<zaker(0,0,s,n)<<endl;
  for(int i=0;i+k<=n;i++){
      mi=min(mi,zaker(i,0,s,n)-zaker(i+k,k%3,s,n));
      mi=min(mi,zaker(i,1,s,n)-zaker(i+k,(k+1)%3,s,n));
      mi=min(mi,zaker(i,2,s,n)-zaker(i+k,(k+2)%3,s,n));
  }   
  cout<<mi<<endl;       
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}