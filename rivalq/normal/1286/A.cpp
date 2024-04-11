//https://codeforces.com/problemset/problem/1286/A
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
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define IOS            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret            return 0
#define pi             3.1415926536
#define hell           1000000007
#define narak          998244353
#define mem1(a)        memset(a,-1,sizeof(a))
const int inf1=1e9;
const ll inf2=1e18;
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int dp[101][101][101][2];
int arr[101];
int garland(int i,int o,int e,int n,int p){
    if(i==n)return 0;
    if(p!=-1 && dp[i][o][e][p]!=-1)return dp[i][o][e][p];
    if(arr[i]!=-1){
        return (arr[i]!=p &&p!=-1)+garland(i+1,o,e,n,arr[i]);
    }
    int x1=inf1;
    if(o>0)x1=garland(i+1,o-1,e,n,1)+(p==0);
    int x2=inf1;
    if(e>0)x2=garland(i+1,o,e-1,n,0)+(p==1);
    if(p!=-1)dp[i][o][e][p]=min(x1,x2);
    else{
        dp[i][o][e][0]=dp[i][o][e][1]=min(x1,x2);
    }
    return min(x1,x2);
}
int solve(){
 int n;cin>>n;
 mem1(dp);
 rep3(n)cin>>arr[i];
 int o=n/2+(n%2);
 int e=n/2;
 rep3(n){
     if(arr[i]==0){
         arr[i]=-1;
         continue;
     }
     arr[i]=arr[i]%2;
     if(arr[i])o--;
     else e--;
 }
 cout<<garland(0,o,e,n,-1)<<endl;
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