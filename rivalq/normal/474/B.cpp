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
int n;
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int b_se(ll dp[],ll q){
    int l=0,u=n-1;
    int ans=1;
    while(l<=u){
      int mid=(l+u)/2;
      if(dp[mid]==q)return mid+1;
      else if(dp[mid]>q){
          u=mid-1;
          ans=mid+1;
      }
      else{
          l=mid+1;
      }
    }
    return ans;
}
int solve(){
  cin>>n;
  int arr[n];inarr(arr,n);
  ll dp[n];dp[0]=arr[0];
  rep(i,n,1)dp[i]=dp[i-1]+arr[i];
  int m;cin>>m;
  for(int i=0;i<m;i++){
      ll q;cin>>q;
      cout<<b_se(dp,q)<<endl;
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