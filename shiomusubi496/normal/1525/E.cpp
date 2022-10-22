#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod=998244353;
int fact[21];
int mod_pow(int a,int b){
  if(!b)return 1;
  if(b&1)return mod_pow(a,b-1)*a%mod;
  int c=mod_pow(a,b/2);
  return c*c%mod;
}
signed main(){
  fact[0]=1;
  for(int i=1;i<=20;i++) fact[i]=fact[i-1]*i%mod;
  int n,m; cin>>n>>m;
  vector<vector<int>>A(n,vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++) cin>>A[i][j];
  }
  int ans=0;
  for(int i=0;i<m;i++){
    vector<int> B(n);
    for(int j=0;j<n;j++) B[j]=A[j][i];
    sort(B.begin(),B.end());
    int prod=1;
    for(int j=0;j<n;j++) (prod*=max(B[j]-j-1,0ll))%=mod;
    prod=(fact[n]-prod+mod)%mod;
    (ans+=prod)%=mod;
  }
  cout<<ans*mod_pow(fact[n],mod-2)%mod<<endl;
}