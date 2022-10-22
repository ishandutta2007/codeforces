#include<bits/stdc++.h>
#define int long long
using namespace std;
void chmax(int&a,int b){if(a<b)a=b;}
signed main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    vector<int>a(n),b(n),c(n);
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++)if(a[i]>b[i])swap(a[i],b[i]);
    int ans=0;
    vector<int>dp(n);dp[1]=b[1]-a[1]+2;
    for(int i=1;i<n-1;i++){
      chmax(ans,dp[i]+c[i]-1);
      chmax(dp[i+1],b[i+1]-a[i+1]+2);
      if(a[i+1]!=b[i+1])chmax(dp[i+1],dp[i]+(a[i+1]-1)+(c[i]-b[i+1])+2);
    }
    cout<<max(ans,dp[n-1]+c[n-1]-1)<<endl;
  }
}