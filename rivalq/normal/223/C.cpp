#include<bits/stdc++.h>
#define rep1(i,n,a)    for(int i=0;i<n;i+=a)
#define rep2(i,n,a)    for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep1(i,n,1)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define trav(a,x)      for(auto x:a)
#define endl           "\n"
#define eb             emplace_back
#define fr             first
#define sc             second
#define gcd(a,b)       __gcd(a,b)
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)         (int)a.size()
#define pii            pair<int,int>
#define psi            pair<string,int>
#define pss            pair<string,string>
#define pll            pair<ll,ll>
#define vec            vector<int>
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
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
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
ll fact[100001]={0},infact[100001]={0};
map<ll,ll> mp;
int solve(){
 int n,k;cin>>n>>k;
 ll a[n],b[n],p[n];
 rep3(n){
     cin>>a[i];
     b[i]=a[i];
 }
 
 ll j=k;
 mp[j-1]=1;
 for(int i=0;i<=n;i++){
     mp[j+i]=mp[j+i-1]*(j+i);
     mp[j+i]%=hell;
 }
 ll d[n]={0};
 for(int i=n-1;i>=0;i--){
     for(int j=0;j<=i;j++){
        ll k2=(b[j]*mp[k+i-j-1])%hell;
        k2=((k2*infact[i-j])%hell);
        d[i]=d[i]+k2;
        d[i]%=hell;
     }
 }
 for(auto i:d)cout<<i<<" ";cout<<endl;
 ret;
}
int main(){
    IOS;
    //freopen("output.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;//cin>>t;
    fact[0]=1;
    rep2(i,100001,1)fact[i]=(i*fact[i-1])%hell;
    rep2(i,100001,1)infact[i]=xymodp(fact[i],hell-2,hell);
    infact[0]=infact[1]=1;
    while(t--){
        solve();
    }
    ret;
}