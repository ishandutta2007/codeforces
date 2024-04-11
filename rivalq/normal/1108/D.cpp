//https://codeforces.com/contest/1108/problem/D
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
int dp[2*N+10][5];
int n;
int zaker(int i,int f,string &s){
    if(i==n){
        return 0;
    }
    if(dp[i][f]!=-1)return dp[i][f];
    int f1=0;
    int f2=1;
    int f3=2;
    char c=(f==0)?'R':(f==1)?'G':'B';
    dp[i][f]=n;
    if(f1!=f)dp[i][f]=min(zaker(i+1,f1,s)+(c!=s[i]),dp[i][f]);
    if(f2!=f)dp[i][f]=min(zaker(i+1,f2,s)+(c!=s[i]),dp[i][f]);
    if(f3!=f)dp[i][f]=min(zaker(i+1,f3,s)+(c!=s[i]),dp[i][f]);
    return dp[i][f];
}
int solve(){
  mem1(dp);   
  cin>>n;
  string s;cin>>s; 
  char c='-';
  int x1=zaker(0,0,s);
  int x2=zaker(0,1,s);
  int x3=zaker(0,2,s);
  cout<<min(x1,min(x2,x3))<<endl;
  int cnt=0;
  for(int i=0;i<n;i++){          
   int x1=zaker(i,0,s);
   int x2=zaker(i,1,s);
   int x3=zaker(i,2,s);
   if(c=='R')x1=n;
   if(c=='G')x2=n;
   if(c=='B')x3=n;
   if(x1<=x2 && x1<=x3){
       cout<<'R';
       c='R';
   }
   else if(x2<x1 && x2<x3){
       cout<<'G';
       c='G';
   }
   else{
       cout<<'B';
       c='B';
   }
   cnt+=(c!=s[i]);
 } 
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