//https://codeforces.com/group/ZK8T91TYOT/contest/276360/problem/BD
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define elasped_time 1.0 * clock() / CLOCKS_PER_SEC
const int inf1=1e9;
const ll inf2=1e18;
const int N=1005;
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
ll dp1[N][N];
ll dp2[N][N];
ll dp3[N][N];
ll dp4[N][N];
ll mat[N][N];
int solve(){
   int n,m;cin>>n>>m;         
   rep3(n){
       rep(j,1,m+1)cin>>mat[i+1][j];
   }      
   for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++){
           if(i==1 && j==1)dp1[i][j]=mat[i][j];
           else {
               dp1[i][j]=mat[i][j]+max(dp1[i-1][j],dp1[i][j-1]);
           }
       }
   }
   for(int i=n;i>=1;i--){
       for(int j=m;j>=1;j--){
           if(i==n && j==m)dp3[i][j]=mat[i][j];
           else{
               dp3[i][j]=mat[i][j]+max(dp3[i+1][j],dp3[i][j+1]);
           }
       }
   }
   for(int i=n;i>=1;i--){
       for(int j=1;j<=m;j++){
           if(i==n && j==1)dp2[i][j]=mat[i][j];
           else{
               dp2[i][j]=mat[i][j]+max(dp2[i+1][j],dp2[i][j-1]);
           }
       }
   }
   for(int i=1;i<=n;i++){
       for(int j=m;j>=1;j--){
           if(i==1 && j==m)dp4[i][j]=mat[i][j];
           else{
               dp4[i][j]=mat[i][j]+max(dp4[i-1][j],dp4[i][j+1]);
           }
       }
   }
   ll ma=0;
   for(int i=2;i<n;i++){
       for(int j=2;j<m;j++){
          ma=max(ma,dp1[i-1][j]+dp2[i][j-1]+dp3[i+1][j]+dp4[i][j+1]);
          ma=max(ma,dp1[i][j-1]+dp2[i+1][j]+dp4[i-1][j]+dp3[i][j+1]);
       }
   }
   cout<<ma<<endl;
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