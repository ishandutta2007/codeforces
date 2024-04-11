//https://codeforces.com/contest/514/problem/B
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
#define inf 100000
#define nan 1000000
using namespace std;
int solve(){
  int n,xg,yg;
  cin>>n>>xg>>yg;
  int arr[n][2];
  lop(i,n,1) cin>>arr[i][0]>>arr[i][1];
  double slopes[n];
  lop(i,n,1) slopes[i]=nan;
  lop(i,n,1){
      if(slopes[i]==nan){
      double s;
      if(xg==arr[i][0]) slopes[i]==inf;
      else{
          s = (double)(yg-arr[i][1])/(double)(xg-arr[i][0]);slopes[i]=s;
      }
    }
  }
  set<double> s(slopes,slopes+n);
  cout<<s.size()<<endl;
}
int main(){
    IOS;
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}