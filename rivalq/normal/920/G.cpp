//https://codeforces.com/contest/920/problem/G
#include<iostream>
#include<vector>
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
int isprime[N*10+10];
vector<int> primes;
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
vector<pii> pie(vector<int> p,int m){
    int ans=0;
    vector<pii> v;
    int n=p.size();
    for(int i=1;i<(1L<<n);i++){
        int cnt=0;
        ll a=1;
        for(int j=0;j<n;j++){
            int k=1<<j;
            if(i&k)a=a*p[j],cnt++;
        }
        if(cnt&1)v.pb({a,1});
        else v.pb({a,-1});
    }
    return v;
}
vector<int> prm[1000001];
int gcnt(vector<pii> vu,int m,int x){
    int ru1=0,ru2=0;
    for(auto i:vu)ru1+=(m/i.x)*(i.y),ru2+=(x/i.x)*(i.y);
    return (m-ru1)-(x-ru2);
}
int query(int x,int p,int k){
   vector<int> pp;
   int ppp=p;
   for(auto i:primes){
      if(ppp<i)break;
      if(ppp%i==0)pp.pb(i);
      while(ppp%i==0){
          ppp=ppp/i;
      }
   }
   vector<pii> vu=pie(pp,x);
   int u=1e7;
   int l=1;
   int ans=1;
   while(l<=u){
      int m=(l+u)/2;
      if(gcnt(vu,m,x)<k){
          l=m+1;
      }
      else{
          ans=m;
          u=m-1;
      }
   }
   return ans;
}
int solve(){
  int t;cin>>t;
  rep3(t){
      int x,p,k;cin>>x>>p>>k;
      cout<<query(x,p,k)<<endl;
  }          
            
 ret;
}
int main(){
    IOS;
    //freopen("inputt.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieve(isprime,1000000);
    for(int i=2;i<=1e6;i++){
        if(isprime[i])primes.pb(i);
    }
    #ifdef cat
    cat();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}