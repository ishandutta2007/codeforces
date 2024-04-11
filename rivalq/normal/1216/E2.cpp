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
ll dpf(ll n){
    ll cnt=n*(n+1)/2;
    for(ll i=10;i<=inf1;i*=10){
           if(n<i){
               break;
           }
           else{
               ll t=(n-i+1)*(n-i+2)/2;
               cnt+=t;
           }
    }
    return cnt;
}
int ndig(int n){
    return floor(log10(n))+1;
}
ll func2(int i){
    ll j=9;
    ll cnt=0;
  for(int k=1;k<=10;k++){  
    if(i>=k){
       cnt+=j*k;
       j=j*10;
    }
    else return cnt;
  } 
}
ll func1(int i){
     ll j=9;
    ll cnt=0;
    for(int k=1;k<=10;k++){  
     if(i>=k){
       cnt=j;
       j=j*10+9;
    }
    else return cnt;
  } 
}
int solve(){
 ll k;cin>>k;
 ll u=inf1;
 if(k==1){
     cout<<1<<endl;
     ret;
 }
 ll l=1;
 ll a=1;
 while(l<=u){
     ll m=(l+u)/2;
     if(dpf(m)==k){
         a=m;break;
     }
     else if(dpf(m)<k){
         l=m+1;
     }
     else{
         a=m;
         u=m-1;
     }
 }
 k-=dpf(a-1);
 if(k<10){
     cout<<k<<endl;
     ret;
 }
 for(int i=1;i<=9;i++){
     if(k>func2(i)){
         continue;
     }
     else{ 
          int j=func1(i-1)+1;
          k-=func2(i-1);
          //cout<<j<<" "<<k<<endl;
          int c=(k)/i;
          j+=c-(k%i==0);
          k=(k-1)%i+1;
          //cout<<j<<" "<<k<<endl;
          string t=to_string(j);
          cout<<t[k-1]<<endl;
         ret;
     }
 }
 
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