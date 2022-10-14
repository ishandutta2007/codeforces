//https://codeforces.com/contest/1332/problem/B
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
bool isPrime(ll N){
    if(N<2)return false;
    if(N<4)return true;
    if((N&1)==0)return false;
    if(N%3==0)return false;
    ll curr=5,s=sqrt(N);
    while(curr<=s){
        if(N%curr==0)return false;
        curr+=2;
        if(N%curr==0)return false;
        curr+=4;
    }
    return true;
}
int solve(){
  int n;cin>>n;          
  int a[n];rep3(n)cin>>a[i];
  int c[n]={0};
  int cnt=1;
  for(int i=2;i<=1000;i++){
      if(isPrime(i)){
          bool f1=0;
          for(int j=0;j<n;j++){
              if(a[j]%i==0 && c[j]==0){
                  f1=1;
                  c[j]=cnt;
              }
          }
          cnt+=f1;
      }
  }          
  cout<<cnt-1<<endl;
  rep3(n)cout<<c[i]<<" ";cout<<endl;
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