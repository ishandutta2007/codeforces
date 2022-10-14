//https://codeforces.com/contest/27/problem/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define pii pair<int,int>
#define eb(a,b) emplace_back(a,b)
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
  int arr[n+1]={0};
  int g[n+1][n+1];
  for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++) g[i][j]=0;
  }
  int k =n*(n-1)/2-1;
  for(int i=0;i<k;i++){
      int a,b;
      cin>>a>>b;
      arr[a]++;
      g[a][b]=1;
      g[b][a]=1;
  }
  int n1,n2;
  for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
           if(i!=j){
               if(g[i][j]==0) {
                   n1=i,n2=j;break;
               }
           }
      }
  }
  if(arr[n1]<arr[n2]){
      cout<<n2<<" "<<n1<<endl;
  }
  else cout<<n1<<" "<<n2<<endl;


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