//https://codeforces.com/problemset/problem/157/B
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
  int n;
  cin>>n;
  ll arr[n];
  lop(i,n,1){
      cin>>arr[i];
  }
  sort(arr,arr+n);
  ll red=0,blue=0,c=1;
  for(int i=n-1;i>=0;i--){
      if(c) {red+=arr[i]*arr[i];c=0;}
      else {blue+=arr[i]*arr[i];c=1;}
  }
cout<<setprecision(12)<<pi*(red-blue);
}
int main(){
    IOS;
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}