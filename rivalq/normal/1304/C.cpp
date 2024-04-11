//https://codeforces.com/contest/1304/problem/C
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
bool ch(int x1,int x2,int x3,int x4){
    if(x1>x4 || x3>x2)return 0;
    return 1;
}
int solve(){
 ll n,m;cin>>n>>m;
 ll mi_temp=m;
 ll ma_temp=m;
 ll arr[n][3];
 rep3(n)cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
 ll time=0;
 rep3(n){
     ll li=arr[i][1];
     ll hi=arr[i][2];
     ll d=arr[i][0]-time;
     if(li>ma_temp){
         ma_temp=min(hi,ma_temp+d);
         if(ma_temp<li){
             cout<<"NO"<<endl;
             //cout<<i+1<<endl;
             ret;
         }
         mi_temp=li;
     }
     else if(mi_temp>hi){
         mi_temp=max(li,mi_temp-d);
         if(mi_temp>hi){
             cout<<"NO"<<endl;
             //cout<<i+1<<endl;
             ret;
         }
         ma_temp=hi;
     }
     else if(ma_temp<=hi && li<=mi_temp){
            ma_temp=min(ma_temp+d,hi);
            mi_temp=max(li,mi_temp-d);
     }
     else if(ma_temp>=hi && li>=mi_temp) {
          ma_temp=hi;
          mi_temp=li;
     }
     else if(ma_temp<=hi && ma_temp>=li && mi_temp<=li){
          ma_temp=min(hi,ma_temp+d);
          mi_temp=li;
     }
     else if(mi_temp>=li&&ma_temp>=hi && hi>=mi_temp){
         mi_temp=max(li,mi_temp-d);
         ma_temp=hi;
     }
     time=time+d;
     //cout<<mi_temp<<" "<<ma_temp<<endl;

 }
 cout<<"YES"<<endl;ret;   
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