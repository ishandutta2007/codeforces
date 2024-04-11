#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back

using namespace std;

int t,n,a[110],dp[2][2][110][110];

int dfs(int p,int v,int o,int e)
{
  int &ret=dp[p][v][o][e];
  if(ret!=-1) return ret;
  if(o==0&&e==0)
  {
    if(p==0) return ret=(v==0 ? 1:0);
    return ret=(v==1 ? 1:0);
  }
  ret=0;
  if(p==0)
  {
    if(o>0) ret|=(dfs(1,v^1,o-1,e)==0);
    if(e>0) ret|=(dfs(1,v,o,e-1)==0);
  }
  else
  {
    if(o>0) ret|=(dfs(0,v,o-1,e)==0);
    if(e>0) ret|=(dfs(0,v,o,e-1)==0);
  }
  return ret;
}

int main()
{
  rep(i,2) rep(ii,2) rep(j,105) rep(k,105) dp[i][ii][j][k]=-1;
  rep(i,2) rep(ii,2) rep(j,103) rep(k,103) if(dp[i][ii][j][k]==-1) dfs(i,ii,j,k);
  cin>>t;
  rep(tn,t)
  {
    cin>>n;
    int o=0,e=0;
    rep(i,n)
    {
      scanf("%d",&a[i]);
      if(abs(a[i])%2!=0) ++o;
      else ++e;
    }
    puts(dp[0][0][o][e]==1 ? "Alice":"Bob");
  }
	return 0;
}