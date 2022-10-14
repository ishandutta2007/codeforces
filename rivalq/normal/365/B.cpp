//https://codeforces.com/problemset/problem/365/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
using namespace std;
int solve(){
  int n;
  cin>>n;
  ll arr[n];
  lop(i,n,1) cin>>arr[i];
  int ma=2,t=2,a=0,b=1;
  rep(i,n,2){
     if(arr[i]==(arr[a]+arr[b])){
         t++;a=b++;
     }
     else{
         ma=max(t,ma);
         t=2;a=b++;
     }
  }
  ma=max(t,ma);
  cout<<min(ma,n);
}
int main(){
    IOS;
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}