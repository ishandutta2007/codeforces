//https://codeforces.com/contest/416/problem/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define mod 1000000007
using namespace std;
int solve(){
  int m,n;cin>>m>>n;
  ll m_time=0;
  ll i_time[n]={0};
  int arr[m][n];
  lop(i,m,1){
      lop(j,n,1){
          cin>>arr[i][j];
      }
  }
  
  lop(i,m,1){
      lop(j,n,1){
         
         if(j==0){
             i_time[0]+=arr[i][0];
             m_time=max(i_time[0],m_time);
             
         }
         else{
             i_time[j]=max(i_time[j-1],i_time[j]);
             i_time[j]+=arr[i][j];
         }
         if(j==n-1)cout<<i_time[j]<<" ";
      }
  }
}
int main(){
    IOS;
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}