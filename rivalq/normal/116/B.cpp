//https://codeforces.com/contest/116/problem/B
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
int ch(int i,int j,int n,int m){
    if(0<=i && i<n && j>=0 && j<m) return 1;
    return 0;
}
int solve(){
  int n,m;
  cin>>n>>m;
  char f[n][m];
  lop(i,n,1){
      lop(j,m,1){
          cin>>f[i][j];
      }
  }
  int c=0;
  lop(i,n,1){
      lop(j,m,1){
          if(f[i][j]=='W'){
              if(ch(i-1,j,n,m) && f[i-1][j]=='P'){c++;f[i][j]='.';}
              else if(ch(i,j-1,n,m) && f[i][j-1]=='P'){c++;f[i][j]='.';}
              else if(ch(i,j+1,n,m) && f[i][j+1]=='P'){c++;f[i][j]='.';}
              else if(ch(i+1,j,n,m) && f[i+1][j]=='P'){c++;f[i][j]='.';}


          }
      }
  }
  cout<<c<<endl;

}
int main(){
    IOS;
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}