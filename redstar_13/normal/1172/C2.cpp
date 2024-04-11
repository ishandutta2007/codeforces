#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int NN=200020,MM=3030;
const int mod=998244353;
int power(int a, int b, int m=mod, int ans=1){for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m; return ans;}
unordered_map<int,int> mp;
int inv(int a){ 
  if(a<1) return 0;
  if(mp.count(a)) return mp[a];
  return mp[a]=power(a,mod-2);
}
inline void add(int &a,int b){a+=b;if(a>=mod) a-=mod;}

int a[NN];
int wei[NN];
int dp[MM][MM];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1; i<=n; i++) scanf("%d",a+i);
  for(int i=1; i<=n; i++) scanf("%d",wei+i);
  int good=0,bad=0;
  for(int i=1; i<=n; i++){
    if(a[i]) good+=wei[i];
    else bad+=wei[i];
  }
  
  dp[0][0]=1;
  
  for(int i=0; i<m; i++){
    for(int j=0; j<=i; j++){
      if(bad-(i-j)>=0){
        add(dp[i+1][j],(LL)dp[i][j]*(bad-(i-j))%mod*inv(good+j+bad-(i-j))%mod);
        add(dp[i+1][j+1],(LL)dp[i][j]*(good+j)%mod*inv(good+j+bad-(i-j))%mod);
      }
    }
  }
  
//  for(int i=0; i<=m; i++) for(int j=0; j<=i; j++) cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
//  return 0;
  
  int Bad=0,Good=0;
  for(int i=0; i<=m; i++){
    add(Good,(LL)(good+i)*dp[m][i]%mod);
    add(Bad,(LL)(bad-(m-i))*dp[m][i]%mod);
  }
  
  int igood=inv(good),ibad=inv(bad);
  
  for(int i=1; i<=n; i++){
    if(a[i]){
      printf("%d ",(LL)Good*wei[i]%mod*igood%mod);
    }else{
      printf("%d ",(LL)Bad*wei[i]%mod*ibad%mod);
    }
  }
  puts("");
  
  return 0;
}