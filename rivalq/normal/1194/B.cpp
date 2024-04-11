//https://codeforces.com/contest/1194/problem/B
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
  int n,m;
  cin>>n>>m;
  char arr[n][m];
  int rows[n],columns[m];
  lop(i,n,1){
      lop(j,m,1){
          cin>>arr[i][j];
      }
  }
  lop(i,n,1){
      int cnt=0;
      lop(j,m,1){
          if(arr[i][j]=='*')cnt++;
      }
      rows[i]=cnt;
  }
  lop(j,m,1){
     int cnt=0;
     lop(i,n,1){
         if(arr[i][j]=='*')cnt++;
     }
     columns[j]=cnt;
  }
  int mi=n+m-1;
  lop(i,n,1){
      lop(j,m,1){  
        int k=rows[i]+columns[j]-(arr[i][j]=='*');
        mi=min(mi,n+m-1-k);
      }
  }
  cout<<mi<<endl;
  ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}