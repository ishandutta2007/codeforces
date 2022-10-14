//https://codeforces.com/contest/192/problem/B
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
  int arr[n];
  lop(i,n,1)cin>>arr[i];
  int pa=min(arr[0],arr[n-1]);
  int oa=0;
  if(n>2){
  while(1){
      int j=1;
      while(arr[j]==0 && j<n){j++;}
      int mi=arr[j];
      for(int i=1;i<n-1;i++){
          if(arr[i]!=0) mi=min(arr[i],mi);
        }
      for(int i=1;i<n-1;i++){
          if(arr[i]!=0)arr[i]-=mi;}
        oa+=mi;

      for(int i=1;i<n-2;i++){
          if(arr[i]==0 && arr[i+1]==0)goto x;
      }

      
  }
  }
  else oa=pa;
  x:
  cout<<min(oa,pa)<<endl;
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