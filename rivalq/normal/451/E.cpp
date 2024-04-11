//https://codeforces.com/contest/451/problem/E
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
#define cat
ll fact[N+1],infact[N+1];
int n;
ll xymodp(ll x,ll y,ll p){
    ll a=1;
    x%=p;
    while(y){
        if(y&1)a=(a*x)%p;
        x=(x*x)%p;
        y/=2;
    }
    return a;
}
void init(){
    fact[0]=1;
    rep(i,1,100)fact[i]=(i*fact[i-1])%hell;
    rep(i,1,100)infact[i]=xymodp(fact[i],hell-2,hell);
    infact[0]=1;infact[1]=1;
}
ll get(ll r){
   if(r<0)return 0; 
   if(r==0)return 1;
   ll ans=infact[n-1];
   for(ll i=n-1+r;i>r;i--){
       ll j=i%hell;
       ans=(ans*j)%hell;
   } 
   return ans;
} 
int solve(){
  ll s;  
  cin>>n>>s; 
  ll ans=0;         
  ll arr[n];rep3(n)cin>>arr[i],arr[i]++;
  for(int i=0;i<(1<<n);i++){
      ll su=0;
      int cnt=0;
      for(int j=0;j<n;j++){
         if((1<<j)&i){
             cnt++;
             su=su+arr[j];
         }
      }
      ll k=get(s-su);
      //cout<<k<<endl;
      if(cnt&1)ans=(ans-k)%hell;
      else ans=(ans+k)%hell;
  }          
  cout<<(ans%hell+hell)%hell<<endl;
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}