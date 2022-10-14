//https://codeforces.com/contest/1277/problem/D
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
 vector<int>zo,oz,o,z;
 map<string,int>mp;
 vector<string>v;
 v.pb("8");
 rep3(n){
     string s;cin>>s;
     char f=s[0];
     char b=s.back();
     if(b==f && b=='0')z.pb(i+1);
     else if(b==f && f=='1')o.pb(i+1);
     else if(f=='0' && b=='1')zo.pb(i+1);
     else oz.pb(i+1);
     mp[s]=i+1;
     v.pb(s);
 }
 set<int>v1,v2;
 //1 for oz,2 for zo
 for(auto i:oz){
    string s=v[i];
    reverse(all(s));
    if(mp.count(s)){
          v1.insert(i);
          v2.insert(mp[s]);
    }
 }
 if(sz(oz)==0 && sz(zo)==0 && sz(z)!=0 && sz(o)!=0){
     cout<<-1<<endl;
     ret;
 }
 else{
     if(abs(sz(oz)-sz(zo))<=1){
         cout<<0<<endl;
         cout<<endl;
     }
     else{
         int k=abs(sz(oz)-sz(zo));
         k/=2;
         int cnt=0;
         if(sz(oz)>sz(zo)){
             vector<int>ans;
             for(auto i:oz){
                 if(pres(v1,i)==0)ans.pb(i);
             }
             if(ans.size()<k){
                 cout<<-1<<endl;
             }
             else{
                 cout<<k<<endl;
                 rep3(k)cout<<ans[i]<<" ";
             }
         }
         else{
             vector<int>ans;
             for(auto i:zo){
                 if(pres(v2,i)==0)ans.pb(i);
             }
             if(ans.size()<k){
                 cout<<-1<<endl;
             }
             else{
                 cout<<k<<endl;
                 rep3(k)cout<<ans[i]<<" ";
             }
         }
         cout<<endl;
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