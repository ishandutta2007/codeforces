//https://codeforces.com/contest/1105/problem/C
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
const int N=300000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
ll dp[N][3];
int n;
int a[3];
ll zeno(int i,int mod){
    if(i==n){
        return mod==0;
    }
    if(dp[i][mod]!=-1)return dp[i][mod];
    dp[i][mod]=0;
    for(int j=0;j<3;j++){
        int mmod=(j+mod)%3;
        dp[i][mod]=(dp[i][mod]+a[j]*zeno(i+1,mmod)%hell)%hell;
    }
    return dp[i][mod];
}
int solve(){
  cin>>n;          
  int l,r;cin>>l>>r;
  a[0]=r/3-(l-1)/3;   
  int l2=l,r2=r;
  if(l2%3==0)l2++;
  else if(l2%3==2)l2+=2;
  if(r2%3==0)r2-=2;
  else if(r2%3==2)r2--;
  a[1]=(r2-l2+1)/3+1;
  a[2]=r-l+1-a[0]-a[1];
  mem1(dp);
  //cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
  cout<<zeno(0,0)<<endl;       
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