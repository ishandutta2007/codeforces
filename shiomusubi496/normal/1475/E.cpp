#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
int com[1100][1100];
signed main(){
  com[0][0]=1;
  for(int i=1;i<=1000;i++){
    com[i][0]=com[i][i]=1;
    for(int j=1;j<i;j++)com[i][j]=(com[i-1][j-1]+com[i-1][j])%mod;
  }
  int t;cin>>t;
  while(t--){
    int n,k;cin>>n>>k;
    vector<int>A(n),B(n),C(n);
    for(int i=0;i<n;i++){
      cin>>A[i];
      B[--A[i]]++;
    }
    sort(A.rbegin(),A.rend());
    for(int i=0;i<k;i++)C[A[i]]++;
    int ans=1;
    for(int i=0;i<n;i++)ans=ans*com[B[i]][C[i]]%mod;
    cout<<ans<<endl;
  }
}