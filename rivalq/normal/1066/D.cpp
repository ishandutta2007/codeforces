//https://codeforces.com/contest/1066/problem/D
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
int arr[2*N+1];
int greedy(int n,int m,int k){
         int j=n;
         int t=0;
         int sp=k;
         while(t<m &&j>=1){
              if(sp-arr[j]>=0){
                  sp-=arr[j];
                  j--;
              }
              else{
                   sp=k;
                   t++;
              }
         }
     return n-j;
}
int solve(){
  int n,m,k;cin>>n>>m>>k;
  rep3(n)cin>>arr[i+1];          
  int l=n;
  int u=1;
  int ans=greedy(n,m,k);
  
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