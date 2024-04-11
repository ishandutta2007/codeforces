#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF=1e18;
signed main(){
  int n; cin>>n;
  vector<int>A(n);
  vector<int>B,C;
  for(int i=0;i<n;i++){
    cin>>A[i];
    if(A[i])B.push_back(i);
    else C.push_back(i);
  }
  int m=B.size(),k=C.size();
  vector<vector<int>>dp(k+1,vector<int>(m+1,INF)); dp[0][0]=0;
  for(int i=0;i<k;i++){
    for(int j=0;j<=m;j++)dp[i+1][j]=dp[i][j];
    for(int j=0;j<m;j++) dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+abs(B[j]-C[i]));
  }
  cout<<dp[k][m]<<endl;
}