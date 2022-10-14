//https://codeforces.com/problemset/problem/546/D
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
void sieve(int isprime[],int n){
   rep(i,1,n+1)isprime[i]=i;
   for(int p=2;p*p<=n;p++){
       if(isprime[p]){
           for(int i=p*p;i<=n;i+=p){
               isprime[i]=0;
           }
       }
   }
}
vector<int>p;
int isprime[5000001]={0};
int a[5000001]={0};
int get(int a){
    int cnt=0;
    for(auto i:p){
      if(i*i>a)break;  
      while(a%i==0)a=a/i,cnt++;
    }
    if(a>1)cnt++;
    return cnt;
}
int dp[5000001]={0};
int solve(){
  int a,b;cin>>a>>b;          
  cout<<dp[a]-dp[b]<<endl;          
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    sieve(isprime,5000000);
    for(int i=2;i<=5000000;i++){
        if(isprime[i]){
            for(int j=i;j<=5000000;j+=i){
                int x=j;
                int cnt=0;
                while(x%i==0){
                    cnt++;
                    x=x/i;
                }
                a[j]+=cnt;
            }
        }
    }
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=5000000;i++){
       dp[i]=dp[i-1]+a[i];
    }
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}