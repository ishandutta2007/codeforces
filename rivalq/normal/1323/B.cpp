//https://codeforces.com/contest/1323/problem/B
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep3(n)cin>>arr[i]
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
#define int long long
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int solve(){
 int n,m,k;cin>>n>>m>>k;
 int a[n],b[m];inarr(a,n);inarr(b,m);
 map<int,int>mp1,mp2;
 int i=0;
 while(i<n){
     int j=i;
     while(j<n && a[j])j++;
     if(j!=i)mp1[j-i]++,i=j;
     else i++;
 }
 i=0;
  while(i<m){
     int j=i;
     while(j<m && b[j])j++;
     if(j!=i)mp2[j-i]++,i=j;
     else i++;
 }
 int cnt=0;
 map<int,int> mp3;
 for(auto i:mp1){
   int l=i.x;
   for(int j=1;j<=l;j++){
       if(k%j==0){
           mp3[j]+=(i.y)*(l-j+1);
       }
   }
 }
 //cout<<cnt<<endl;
 for(auto i:mp2){
   int l=i.x;
   for(int j=1;j<=l;j++){
       if(k%j==0){
           if(mp3.count(k/j)){
               cnt=cnt+mp3[k/j]*mp2[l]*(l-j+1);
           }
       }
   }
 }
 cout<<cnt<<endl;
 ret;
}
signed main(){
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