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

int t,dp[30][30][30],m25[30];
string s;

void chmin(int &x,int y){if(x>y) x=y;}

int main()
{
  m25[0]=1;
  repn(i,27) m25[i]=m25[i-1]*10%25;
  cin>>t;
  rep(tn,t)
  {
    cin>>s;reverse(s.begin(),s.end());
    rep(i,s.size()+2) rep(j,s.size()+2) rep(k,26) dp[i][j][k]=1e9;
    dp[0][0][0]=0;
    rep(i,s.size()) rep(j,i+1) rep(k,25) if(dp[i][j][k]<1e9)
    {
      chmin(dp[i+1][j][k],dp[i][j][k]+1);
      chmin(dp[i+1][j+1][(k+(s[i]-'0')*m25[j])%25],dp[i][j][k]);
    }
    int need=0,ans=1e9;
    for(int i=s.size();i>0;--i)
    {
      if(i<s.size()) need+=(s[i]=='0' ? 0:1);
      rep(j,i+1) chmin(ans,dp[i][j][0]+need);
    }
    cout<<ans<<endl;
  }
	return 0;
}