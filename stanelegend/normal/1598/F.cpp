#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;
const int bas=5e5;

int n,cnt[30][1000000],mnv[30],add[30],sum[1100000],dp[1100000],ans=0;
string s[30];

int main()
{
  cin>>n;
  rep(i,n)
  {
    cin>>s[i];
    int fim,mn=1e9,cur=0;
    rep(j,s[i].size())
    {
      cur+=(s[i][j]=='(' ? 1:-1);
      if(cur<mn) mn=cur,fim=j;
    }
    add[i]=cur;mnv[i]=mn;
    cur=0;mn=1e9;
    rep(j,s[i].size())
    {
      cur+=(s[i][j]=='(' ? 1:-1);
      if(mn>=cur) ++cnt[i][bas+cur];
      mn=min(mn,cur);
    }
  }
  repn(i,(1<<n)-1)
  {
    int nn=__builtin_ctz(i);
    sum[i]=add[nn]+sum[i^(1<<nn)];
  }
  rep(i,(1<<n)+5) dp[i]=-1;
  dp[0]=0;
  rep(i,1<<n) if(dp[i]>-1)
  {
    ans=max(ans,dp[i]);
    int cur=sum[i];
    rep(j,n) if((i&(1<<j))==0)
    {
      if(cur+mnv[j]<0)
      {
        ans=max(ans,dp[i]+cnt[j][-cur+bas]);
        continue;
      }
      dp[i|(1<<j)]=max(dp[i|(1<<j)],dp[i]+cnt[j][-cur+bas]);
    }
  }
  cout<<ans<<endl;
  return 0;
}