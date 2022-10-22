#include<bits/stdc++.h>
#define int long long
using namespace std;
const int m=200001;
const int INF=1e15;
signed main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    vector<int>A(m);
    for(int i=0;i<n;i++){
      int a;cin>>a;
      A[a]++;
    }
    int ans=0;
    vector<int>dp(m,-INF);
    for(int i=1;i<m;i++){
      if(A[i]&&dp[i]==-INF)dp[i]=A[i];
      else if(dp[i]==-INF)continue;
      else dp[i]+=A[i];
      for(int j=2;i*j<m;j++)dp[i*j]=max(dp[i*j],dp[i]);
      ans=max(ans,dp[i]);
    }
    cout<<n-ans<<endl;
  }
}