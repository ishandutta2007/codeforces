//https://codeforces.com/contest/361/problem/B
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
  int n,k;
  cin>>n>>k;int arr[n+1]={0};rep(i,n+1,1)arr[i]=i;
  if(k==n)cout<<-1<<endl;
  
  else{
      
      if((n-k)&1){
          if(n-k!=1){
              int t=n-k-1;int i=2;
              while(t!=0){
                   arr[i+1]=arr[i]+arr[i+1]-(arr[i]=arr[i+1]);
                   t-=2,i+=2;
              }
          }
      }
      else{
          arr[1]=2,arr[2]=1;
          if(n-k!=2){
               int t=n-k-2;int i=3;
              while(t!=0){
                   arr[i+1]=arr[i]+arr[i+1]-(arr[i]=arr[i+1]);
                   t-=2,i+=2;
              }
          }
      }
        rep(i,n+1,1)cout<<arr[i]<<" ";

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