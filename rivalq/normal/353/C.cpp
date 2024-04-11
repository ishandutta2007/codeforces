//https://codeforces.com/problemset/problem/353/C
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define inarr(arr,n) lop(i,n,1)cin>>arr[i]
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define eb emplace_back
#define fr first
#define sc second
#define pii pair<int,int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define hell 1000000007
using namespace std;
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int solve(){
  int n;cin>>n;
  vector<ll> arr(n);inarr(arr,n);
  string m;cin>>m;
  reverse(all(m));
  reverse(all(arr));
  ll sm=0,ms=0,zm=0;
  lop(i,n,1){sm+=arr[i];
  if(m[i]=='0')zm+=arr[i];}
  ll ma=0;
  for(int i=0;i<n;i++){
       //cout<<zm<<" "<<sm<<" "<<ms<<endl;
       if(m[i]=='0')sm-=arr[i],zm-=arr[i];
       else{
           if(zm>arr[i]){
               //ms+=sm-arr[i];
               sm-=arr[i];
               ma=max(ma,ms+sm);
               ms+=arr[i];
           }
           else{
               ms+=arr[i];
               sm-=arr[i];
               ma=max(ma,ms+sm-zm);
           }
       }
       //ma=max(ma,ms);
  }
  cout<<ma<<endl;
  ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}