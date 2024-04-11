//https://codeforces.com/contest/1283/problem/D
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
 int n,m;cin>>n>>m;
 vector<int> x,y;
 map<int,int> mp2;
 rep3(n){
     int t;cin>>t;
     x.pb(t);
     mp2[t]=1;
 }
 sort(all(x));
 map<int,ll> mp;
 for(int i=1;i<n-1;i++){
     mp[x[i]]=max((x[i]-x[i-1])/2,(x[i+1]-x[i])/2);
 }
 ll a=0;
 mp[x[0]]=inf2;
 mp[x[n-1]]=inf2;
 for(int j=1;m!=0;j++){
     vector<int> xx;
     for(auto i:x){
         //cout<<i-j<<" "<<i+j<<endl;
         if(m==0)break;
         if(j<=mp[i]){
             xx.pb(i);
         }
         if(pres(mp2,i-j)==0){
              mp2[i-j]=1;
              y.pb(i-j);
              m--;
              a+=j;
         }
         if(m==0)break;
         if(pres(mp2,i+j)==0){
             mp2[i+j]=1;
             y.pb(i+j);
             m--;
             a+=j;
         }
     }
     x.clear();
     x=xx;
 }
 //for(auto i:x)cout<<i<<" ";cout<<endl;
 cout<<a<<endl;   
 for(auto i:y)cout<<i<<" ";cout<<endl;
 ret;
}
int main(){
    //IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}