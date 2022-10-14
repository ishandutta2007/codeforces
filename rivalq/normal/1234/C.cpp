//https://codeforces.com/contest/1234/problem/C
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
 int n;cin>>n;   
 string s1,s2;cin>>s1>>s2;           
 int i=0,j=0;
 int d=0;
 rep3(n){
     if(s1[i]=='2')s1[i]='1';
     else if('3'<=s1[i] && s1[i]<='6')s1[i]='3';
     if(s2[i]=='2')s2[i]='1';
     else if('3'<=s2[i] && s2[i]<='6')s2[i]='3';
 }
 // d=1 mean from left
 // d=2 means from top
 // d=3 means from bottom
  for(i=0;i<n;){
     if(i==n-1){
       if(j==1){
          if(s2[i]=='1')cout<<"YES"<<endl;
          else cout<<"NO"<<endl;
          ret;
      }
      else{
          if(s1[i]=='3' && s2[i]=='3'){
              cout<<"YES"<<endl;ret;
          }
          cout<<"NO"<<endl;ret;
      }
    }  
   if(i==0 && j==0){
       if(s1[0]=='1'){
           i++;
           d=1;
       }
       else{
           j++;
           d=2;
       }
   }
   else{
       if(j==0){
           if(d==1){
             if(s1[i]=='1')i++;
             else{
                 d=2;
                 j++;
             }
           }
           if(d==3){
            if(s1[i]=='1'){
                cout<<"NO"<<endl;ret;
            }
             else{
                 d=1;
                 i++;
             }
           }
       }
       else{
           if(d==1){
             if(s2[i]=='1')i++;
             else{
                 d=3; 
                 j--;
             }
           }
           if(d==2){
             if(s2[i]=='1'){
                cout<<"NO"<<endl;ret;
             }
             else{
                 d=1;
                 i++;
             }
           }
       }
   }
   //cout<<i<<" "<<j<<" "<<d<<endl;
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