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
int solve(){
 ll n;cin>>n;  
 ll m=n; 
 vector<int> v;
 while(n){
     v.pb(n%3);
     n/=3;
 }
 v.pb(0);
 reverse(all(v));
 int pz=0;
 int k=v.size();
 int f=0;
 for(int i=0;i<k;i++){
     if(v[i]==0)pz=i;
     if(v[i]==2){
         f=1;
         break;
     }
 }
 if(f==0){
     cout<<m<<endl;
     ret;
 }
 v[pz]=1;
 for(int i=pz+1;i<k;i++)v[i]=0;
 ll ans=0;
 //for(auto i:v)cout<<i<<" ";cout<<endl;
 for(int i=0;i<k;i++){
     ans=ans*3+v[i];
 }
 cout<<ans<<endl;
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}