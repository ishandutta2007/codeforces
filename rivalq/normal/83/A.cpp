//https://codeforces.com/contest/83/problem/A
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
  long long  arr[n];
  for(int i=0;i<n;i++)cin>>arr[i];
  vector<long long> v;
  int i=0;
  while(i<n){
      int t=0;
      long long k=arr[i];
      while(i<n && k==arr[i]){
          t++;i++;
      }
      v.pb(t);
  }
  long long c=0;
  for(auto i:v){
      c=c+i*(i+1)/2;
  } 
  cout<<c<<endl;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}