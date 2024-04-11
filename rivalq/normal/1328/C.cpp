//https://codeforces.com/contest/1328/problem/C
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
  int n;cin>>n;  
  string x;          
  cin>>x;
  int a[n]={0};
  int b[n]={0};        
  int f=0;
  for(int i=0;i<n;i++){
      if(x[i]=='0'){
          a[i]=b[i]=0;
      }
      else if(x[i]=='2'){
          if(f==1)a[i]=2,b[i]=0;
          else a[i]=b[i]=1; 
      }
      else{
          if(f==1)a[i]=1,b[i]=0;
          else {
              f=1;
              b[i]=1;
              a[i]=0;
          }
      }
  } 
  rep3(n)cout<<b[i];cout<<endl;
  rep3(n)cout<<a[i];cout<<endl; 
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