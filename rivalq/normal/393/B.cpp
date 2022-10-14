//https://codeforces.com/contest/393/problem/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define eb emplace_back
#define pii pair<int,int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define mod 1000000007
using namespace std;
int solve(){
  int n;cin>>n;
  double arr[n][n];
  lop(i,n,1){
      lop(j,n,1)cin>>arr[i][j];
  }
  double a[n][n];
  double b[n][n];
  lop(i,n,1){
      lop(j,n,1){
          a[i][j]=(arr[i][j]+arr[j][i])/2;
          b[i][j]=(arr[i][j]-arr[j][i])/2;
      }
  }
  lop(i,n,1){
      lop(j,n,1)cout<<a[i][j]<<" ";
      cout<<endl;
  }
   lop(i,n,1){
      lop(j,n,1)cout<<b[i][j]<<" ";
      cout<<endl;
  }
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