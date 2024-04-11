//https://codeforces.com/contest/1324/problem/E
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
const int inf1=1e9;
const ll inf2=1e18;
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int dp[2010][2010]={-1};
int dpp(int h1,int h,int i,int n,int arr[],int l,int r){
    if(i==n+1)return 0;
    int k1=(h1+arr[i])%h;
    int k2=(h1+arr[i]-1+h)%h;
    int ans1=(k1>=l && k1<=r);
    int ans2=(k2>=l && k2<=r);
    if(dp[i+1][k1]==-1){
        dp[i+1][k1]=dpp(k1,h,i+1,n,arr,l,r);
    }
    if(dp[i+1][k2]==-1){
        dp[i+1][k2]=dpp(k2,h,i+1,n,arr,l,r);
    }
    return dp[i][h1]=max(ans1+dp[i+1][k1],ans2+dp[i+1][k2]);
}
int solve(){
 int n,h,l,r;cin>>n>>h>>l>>r;
 for(int i=1;i<=n;i++){
     for(int j=0;j<h;j++)dp[i][j]=-1;
 }
 int arr[n+1];
 rep3(n)cin>>arr[i+1];
 cout<<dpp(0,h,1,n,arr,l,r)<<endl;
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