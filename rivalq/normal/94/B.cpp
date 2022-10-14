//https://codeforces.com/contest/94/problem/B
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
  int m;cin>>m;
  int arr[6][6];
  lop(i,6,1){
      lop(j,6,1)arr[i][j]=0;
  }
  lop(i,m,1){
      int a,b;cin>>a>>b;
      arr[a][b]=1;arr[b][a]=1;
  }
  int q=0;
  for(int i=1;i<=5;i++){
      for(int j=1;j<=5;j++){
          for(int k=1;k<=5;k++){
             
              if(i!=j && i!=k && k!=j){
                   //cout<<i<<" "<<j<<" "<<k<<endl;
                   if(arr[i][j]==arr[j][k] && arr[j][k]==arr[i][k]){q=1;break;}
              }
          }
      }
  }
  if(q)cout<<"WIN"<<endl;
  else cout<<"FAIL"<<endl;
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