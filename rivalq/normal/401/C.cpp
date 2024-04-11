//https://codeforces.com/problemset/problem/401/C
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
 if(m==n){
     lop(i,n,1)cout<<10;
 } 
 else if(m==n-1){
      cout<<0;
      lop(i,m,1)cout<<"10";
  }
  else if(m==2*(n+1)){
      cout<<11;
      lop(i,n,1)cout<<"011";
  }
  else if(m>n-1 && m<2*(n+1)){
      int k=2*(n+1)-m;
      if(k==n){
          lop(i,k,1)cout<<"10";
          cout<<11;
      }
     else if(k<n){
           lop(i,k,1)cout<<"10";
           k=m-(n+1);
           lop(i,k-1,1)cout<<"110";
           cout<<11;
      }
      else{
          lop(i,k-1,1)cout<<"10";
          cout<<1;
      }

  }
  else {
      cout<<-1<<endl;
  }
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