//https://codeforces.com/problemset/problem/1062/B
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
 int n;cin>>n;
 map<int,int>mp;
 for(int i=2;i<=sqrt(n);i++){
     if(n%i==0){
         while(n%i==0)mp[i]++,n/=i;
     }
 }
 if(n>1)mp[n]++;
 int f=0;
 int ma=-1;
 int p=1;
 for(auto i:mp){
    int k=i.sc;
    if(floor(log2(k))!=ceil(log2(k))){
        f=1;
    }
    if(ma!=ceil(log2(k))){
         if(ma!=-1)f=1;
         ma=max(ma,(int)ceil(log2(k)));
    }
    p*=i.fr;
 }
 ma=max(0,ma);
 cout<<p<<" "<<ma+f<<endl;   
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}