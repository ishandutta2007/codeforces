//https://codeforces.com/contest/1249/problem/D1
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
int arr[2*N+10]={0};
int solve(){
 int n,k;cin>>n>>k;
 map<pii,int> mp,mp2;
 int ma=0;
 rep3(n){
     int a,b;cin>>a>>b;
     mp[{a,i}]=b;
     mp2[{b,i}]=a;
     ma=max(ma,b);
 }
 auto itr=mp.begin();
 auto itr2=mp2.begin();
 set<pair<int,int>>pq;
 int c=0;
 set<int> s;
 for(int i=1;i<=ma;i++){
   while(itr!=mp.end() && itr->fr.fr==i){
       pq.insert({-itr->sc,itr->fr.sc});
       //cout<<"*"<<itr->fr.fr<<" "<<itr->sc<<endl;
       itr++;
   }
   while(pq.size()>k){
       int idx=pq.begin()->sc;
       s.insert(idx+1);
       pq.erase(pq.begin());
   }
   while(itr2!=mp2.end() && itr2->fr.fr==i){
       //cout<<"%"<<itr2->sc<<" "<<itr2->fr.fr<<endl;
       pq.erase({-itr2->fr.fr,itr2->fr.sc});
       itr2++;
   }
 }
 cout<<sz(s)<<endl;
 for(auto i:s)cout<<i<<" ";cout<<endl;
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