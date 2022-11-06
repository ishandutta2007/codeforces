#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
int lim = 1000000;
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<ll> nd(n+1,0);
  for(int i=1;i<=n;++i){
    for(int j=2*i;j<=n;j+=i){
      ++nd[j];
    }
  }
  vector<ll> res(n+1,0);
  ll sum = 1;
  res[0]=1;
  for(int i=1;i<=n;++i){
    res[i]=(sum+nd[i])%MOD;
    sum=(sum+res[i])%MOD;
  }
  
  cout<<res[n]<<flush;
}