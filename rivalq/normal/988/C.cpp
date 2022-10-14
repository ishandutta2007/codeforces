//https://codeforces.com/contest/988/problem/C
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
 int k;cin>>k;
 vector<int> v[k];
 map<ll,pii> mp;
 rep3(k){
   ll sum=0;
   int n;cin>>n;
   rep1(j,n,1){
       int t;cin>>t;
       v[i].pb(t);
       sum+=t;
   }
   map<int,pii> mp2;
   rep1(j,n,1){
       ll t=sum-v[i][j];
       mp2[t]={i+1,j+1};
   }
   for(auto j:mp2){
       if(pres(mp,j.fr)){
           cout<<"YES"<<endl;
           cout<<mp[j.fr].fr<<" "<<mp[j.fr].sc<<endl;
           cout<<mp2[j.fr].fr<<" "<<mp2[j.fr].sc<<endl;
           ret;
       }
       else{
           mp[j.fr]={mp2[j.fr].fr,mp2[j.fr].sc};
       }
   }
 }
 cout<<"NO"<<endl;   
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