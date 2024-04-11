//https://codeforces.com/contest/1187/problem/C
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define IOS            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret            return 0
#define pi             3.1415926536
#define hell           1000000007
#define narak          998244353
#define elasped_time 1.0 * clock() / CLOCKS_PER_SEC
const int inf1=1e9;
const ll inf2=1e18;
const int N=100000;
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int solve(){
  int n,m;cin>>n>>m;          
  int a[n+2]={0};
  int p[n+1]={0};
  vector<pair<int,pii>>v;
  int q[m][3];
  rep3(m){
      int t,l,r;cin>>t>>l>>r;  
      if(t==1){
          a[l]++;
          a[r]--;
      }
      q[i][0]=t;
      q[i][1]=l;
      q[i][2]=r;
  }          
  for(int i=1;i<=n;i++){
      a[i]=a[i-1]+a[i];
      if(a[i]>0)p[i]=0;
      else p[i]=-1;
  }
  int ans[n+1]={0};
  ans[1]=1000000;
  for(int i=2;i<=n;i++){
      ans[i]=ans[i-1]+p[i-1];
  }
  for(int i=0;i<m;i++){
      int l=q[i][1];
      int r=q[i][2];
      if(q[i][0]){
          for(int i=l;i<r;i++){
              if(ans[i]>ans[i+1]){
                  cout<<"NO"<<endl;ret;
              }
          }
      }
      else{
          bool f=false;
          for(int i=l;i<r;i++){
              if(ans[i]>ans[i+1])f=true;
          }
          if(!f){
              cout<<"NO"<<endl;ret;
          }
      }
  }
  cout<<"YES"<<endl;
  rep(i,1,n+1)cout<<ans[i]<<" ";
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}