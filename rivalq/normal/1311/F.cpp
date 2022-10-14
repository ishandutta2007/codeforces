//https://codeforces.com/contest/1311/problem/F
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define IOS            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret            return 0
#define pi             3.1415926536
#define hell           1000000007
#define narak          998244353
const int inf1=1e9;
const ll inf2=1e18;
const int N=100000;
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> 
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
ll get(ll BIT[],int i){
    ll sum=0;
    i++;
    while(i){
        sum+=BIT[i];
        i-=i&(-i);
    }
    return sum;
}
void upbit(ll BIT[],int i,int n,ll val){
    i++;
    while(i<=n){
        BIT[i]+=val;
        i+=i&(-i);
    }
}
int solve(){
 int n;cin>>n;           
 vector<pii> v;
 vector<pii> vel;
 rep3(n){
     int a;cin>>a;
     v.eb(a,0);
     vel.eb(0,a);
 }
 rep3(n){
     int a;cin>>a;
     v[i].y=a;
     vel[i].x=a;
 }
 sort(all(v)); 
 sort(all(vel));
 ll BIT[n+1]={0};
 rep3(n){
     upbit(BIT,i,n,vel[i].y);
 }
 map<int,int> mp;
 rep3(n){
     mp[vel[i].y]=i;
 }
 ordered_set s;
 ll cnt=0;
 rep3(n){
     s.insert({v[i].y,v[i].x});
     int k=s.order_of_key({v[i].y,v[i].x});
     //cout<<k<<endl;
     //k+=mp2[v[i].y]-1;
     cnt+=((ll)k*v[i].x);
 }
 int c=n;
 rep3(n){
    int k=s.order_of_key({v[i].y,v[i].x});
    //if(mp2[v[i].y])k+=mp2[v[i].y]-1;
    //cout<<k<<endl;
    k=c-k-1;
    //cout<<k<<endl;
    cnt=cnt-(ll)k*v[i].x;
    auto itr=s.find({v[i].y,v[i].x});
    s.erase(itr);
    c--;
 }
 cout<<cnt<<endl;
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}