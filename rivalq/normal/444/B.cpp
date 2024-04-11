//https://codeforces.com/problemset/problem/444/B
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
ll x,n,d;
ll getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
int a[N+10];
int b[N+10];
void initAB() {
    for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}
double fail=0.008;
int solve(){
  cin>>n>>d>>x;
  initAB();          
  map<int,int,greater<int>> mp;
  int cnt=0;
  vector<int>o;
  rep3(n){
      int ans=0;
      mp[a[i]]=i;
      cnt+=(b[i]);
      if(b[i])o.pb(i);
      if(cnt==0){
          cout<<0<<endl;
          continue;
      }
      double psuc=(1.0*cnt/(i+1));
      if(psuc<fail){
         for(auto j:o)ans=max(ans,a[i-j]);
         cout<<ans<<endl;
         continue;
      }
      for(auto j:mp){
         if(b[i-j.y]){
             cout<<j.x<<endl;
             break;
         }
      }
  }          
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