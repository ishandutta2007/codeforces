//https://codeforces.com/problemset/problem/382/C
#include<bits/stdc++.h>
#define rep1(i,n,a) for(int i=0;i<n;i+=a)
#define rep2(i,n,a) for(int i=a;i<n;i++)
#define rep3(n)     for(int i=0;i<n;i++)
#define inarr(arr,n) rep1(i,n,1)cin>>arr[i]
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define trav(a,x) for(auto x:a)
#define endl "\n"
#define eb emplace_back
#define fr first
#define sc second
#define gcd(a,b) __gcd(a,b)
#define pres(a,x) a.find(x)!=a.end()
#define sz(a) (int)a.size()
#define pii pair<int,int>
#define psi pair<string,int>
#define pss pair<string,string>
#define pll pair<ll,ll>
#define vec vector<int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define hell 1000000007
#define narak 998244353
const int inf1=1e9;
const ll inf2=1e18;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int solve(){
 int n;cin>>n;
 if(n==1){cout<<-1<<endl;return 0;}
 ll b[n];
 inarr(b,n);
 sort(b,b+n);
 if(n==2){
      set<ll>k;
      int d=b[1]-b[0];
      k.insert({b[0]-d});
     if(b[1]%2==b[0]%2){ 
      k.insert({(b[1]+b[0])/2}); 
     } 
      k.insert({b[n-1]+d});
      cout<<k.size()<<endl;
      for(auto i:k)cout<<i<<" ";cout<<endl; 
     ret;
 }
 set<ll>s;
 for(int i=0;i<n-1;i++){
     s.insert({b[i+1]-b[i]});
 }
 if(s.size()==1){
     set<ll>k;
     k.insert({*s.begin()+b[n-1]});
     k.insert({-*s.begin()+b[0]});
     cout<<k.size()<<endl;
     for(auto i:k)cout<<i<<" ";cout<<endl;
 }
 else if(s.size()==2){
     int d1=*s.begin();
     auto itr=s.begin();
     itr++;
     int d2=*itr;
     if(d2/2==d1){
         int c1=0;
         int c2=0;
         for(int i=0;i<n-1;i++){
             if(b[i+1]-b[i]==d2)c1++;
         }
         if(c1>1){
             cout<<0<<endl;ret;
         }
         for(int i=0;i<n;i++){
             if(b[i+1]-b[i]==d2){
                if(b[i]%2==b[i+1]%2){ 
                 cout<<1<<endl;
                 cout<<(b[i+1]+b[i])/2<<endl;
                }
                else{
                    cout<<0<<endl;
                } 
             }
         }
     }
     else{
         cout<<0<<endl;
     }
 }
 else{
     cout<<0<<endl;
 }
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