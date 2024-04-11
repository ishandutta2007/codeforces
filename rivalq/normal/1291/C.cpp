//https://codeforces.com/contest/1291/problem/C
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
 int n,m,k;cin>>n>>m>>k;
 deque<int> dq;
 rep3(n){
   int t;cin>>t;
   dq.pb(t);
 }
 k=min(m-1,k);   
 int ma=1;
 int f=k;
 int b=0;
 while(f>=0){
     deque<int> dq2=dq;
     rep3(f)dq2.pop_front();
     rep3(b)dq2.pop_back();
     int moves=m-k-1;
     int ff=moves;
     int bb=0;
     int mi=hell;
     vector<int>v;
     while(dq2.empty()==0){
         v.pb(dq2.front());
        dq2.pop_front();
     }
     int n=v.size();
     for(int i=0;i<=moves;i++){
         mi=min(mi,max(v[i],v[n-moves-1+i]));
     }
     //cout<<mi<<endl;
     ma=max(mi,ma);
     f--;
     b++;
 }
 cout<<ma<<endl;
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