//https://codeforces.com/contest/129/problem/B
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
  int n,m;cin>>n>>m;
  int arr[n+1][n+1];
  int degree[n+1]={0};
  lop(i,n+1,1){
      lop(j,n+1,1)arr[i][j]=0;
  }
  lop(i,m,1){
      int a,b;cin>>a>>b;degree[a]++;degree[b]++;
      arr[a][b]=1;arr[b][a]=1;
  }
  
  int g=0;
  x:
  set<int>s;int f=0;
  for(int i=1;i<=n;i++){
      if(degree[i]==1){f=1;s.insert(i);}
  }
  if(f){
      for(auto i:s){int j;
          for(j=0;j<=n;j++){
              if(arr[i][j]) break;
          }
          if(s.find(j)!=s.end()) s.erase(j);
          arr[i][j]--;arr[j][i]--;degree[i]--;degree[j]--;
      }g++;goto x; 
  }
  else cout<<g<<endl;  
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