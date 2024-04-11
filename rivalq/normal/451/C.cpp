//https://codeforces.com/contest/451/problem/C
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
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
#define mem1(a)        memset(a,-1,sizeof(a))
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
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int solve(){
 ll n,k,d1,d2;cin>>n>>k>>d1>>d2;     
 ll b=n/3;
 if(n%3){
     cout<<"no"<<endl;
     ret;
 }
 ll w1=0,w2=0,w3=0;
 int f1=0;
 if((k-(d1+d2))%3==0 && k>=d1+d2){
     w2=(k-(d1+d2))/3;
     w1=(2*d1-d2+k)/3;
     w3=(2*d2-d1+k)/3;
     if(max(w1,w3)<=b){
         f1=1;
     }
 }
 if((k+d1+2*d2)%3==0 && k>=2*d1+d2){
     if((k+d1+2*d2)/3<=b)f1=1;
 }
 if((k+d2+2*d1)%3==0 && k>=2*d2+d1){
     if((k+d2+2*d1)/3<=b)f1=1;
 }
 if((k+d1+d2)%3==0 && k+d1>=2*d2 && k+d2>=2*d1){
     if((k+d1+d2)/3<=b)f1=1;
 }
 if(f1){
     cout<<"yes"<<endl;
 }
 else{
     cout<<"no"<<endl;
 }
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}