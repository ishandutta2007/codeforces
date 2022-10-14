//https://codeforces.com/problemset/problem/1091/D
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
//#define narak           1000000007
#define narak          998244353
const int inf1=1e9;
const ll inf2=1e18;
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
#define cat
ll fact[10*N+1],infact[10*N+1];
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
    rep(i,1,1000001)fact[i]=(i*fact[i-1])%narak;
    rep(i,1,1000001)infact[i]=xymodp(fact[i],narak-2,narak);
    infact[0]=1;infact[1]=1;
}
ll cat_num(ll n,ll m){
    ll k =fact[n+m];
    k*=infact[n];
    k%=narak;
    k*=infact[m];
    k%=narak;
    k*=(n-m+1);
    k%=narak;
    k*=xymodp(n+1,narak-2,narak);
    return k%narak;
} 
int solve(){
 ll n;cin>>n;
 ll ans=n*fact[n]%narak;
 ll cnt=0;
 rep3(n-1){
   cnt=(cnt+(fact[n]*infact[i+1])%narak)%narak;
 }
 ans=ans-cnt;
 ans%=narak;
 ans=(ans+narak)%narak;
 cout<<ans<<endl;
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