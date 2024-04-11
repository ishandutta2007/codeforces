//https://codeforces.com/contest/1096/problem/E
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
#define cat
ll fact[N+1],infact[N+1];
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
    rep(i,1,100000+1)fact[i]=(i*fact[i-1])%narak;
    rep(i,2,100000+1)infact[i]=xymodp(fact[i],narak-2,narak);
    infact[0]=1;infact[1]=1;
}
ll ncr(int n,int r){
    if(n==r||r==0)return 1;
    if(r>n)return 0;
    if(n<0 || r<0) return 0;
    return fact[n]*infact[r]%narak*infact[n-r]%narak;
}
ll count(ll n,ll s,ll r){
    if(n==0){
        if(s==0)return 1;
        else return 0;
    }
    if(r==0){
        return 0;
    }
    ll ans=0;
    for(int i=0;i<=s;i+=r){
       ll val=ncr(s-i+n-1,n-1)*ncr(n,i/r)%narak;
       if((i/r)%2==0)ans=ans+val;
       else ans=ans-val;
       ans=(ans+narak)%narak;
    }
    return ans;
}
int solve(){
 ll p,s,r;cin>>p>>s>>r;
 ll ans=0;
 for(int i=r;i<=s;i++){
     for(int j=1;i*j<=s && j<=p;j++){
        ll n=p-j;
        ll sum=s-i*j;
        ll r=i;
        ans=(ans+count(n,sum,r)*xymodp(j,narak-2,narak)%narak*ncr(p-1,j-1)%narak)%narak;
        //cout<<count(n,0,0)<<endl;
     }
 }
 ll val=ncr(s-r+p-1,p-1);
 ans=ans*xymodp(val,narak-2,narak)%narak;
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