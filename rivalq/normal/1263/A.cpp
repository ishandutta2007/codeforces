//https://codeforces.com/contest/1263/problem/A
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
  ll arr[3];
  cin>>arr[0]>>arr[1]>>arr[2];
  sort(arr,arr+3);
  if(arr[2]>=(arr[0]+arr[1])){
      cout<<arr[0]+arr[1]<<endl;
  }
  else{
      cout<<arr[2]+(arr[1]+arr[0]-arr[2])/2<<endl;
  }
}
int main(){
    IOS;
    ll t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}