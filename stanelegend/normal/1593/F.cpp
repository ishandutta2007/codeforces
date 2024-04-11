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

int t,n,a,b,dp[50][100][50][50];
pair <pii,int> lst[50][100][50][50];
string s,ans;

void upd(int i,int j,int k,int p,int val,int li,int lj,int lk)
{
  dp[i][j][k][p]=val;
  lst[i][j][k][p]=mpr(mpr(li,lj),lk);
}

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n>>a>>b>>s;
    rep(i,n+3) rep(j,n+n+3) rep(k,a+3) rep(p,b+3) dp[i][j][k][p]=0;
    dp[0][n][0][0]=1;
    rep(i,n) rep(j,n+i+1) rep(k,a) rep(p,b) if(dp[i][j][k][p]!=0)
    {
      upd(i+1,j+1,(k*10+s[i]-'0')%a,p,1,j,k,p);
      upd(i+1,j-1,k,(p*10+s[i]-'0')%b,-1,j,k,p);
    }
    int ii=-1,jj=1e9,kk,pp;
    repn(j,n+n-1) if(dp[n][j][0][0]!=0)
    {
      if(abs(j-n)<abs(jj-n))
      {
        ii=n;
        jj=j;
        kk=pp=0;
      }
    }
    if(ii==-1)
    {
      puts("-1");
      continue;
    }
    ans="";
    while(ii>0)
    {
      ans.pb(dp[ii][jj][kk][pp]==1 ? 'R':'B');
      pair <pii,int> tmp=lst[ii][jj][kk][pp];
      --ii;jj=tmp.fi.fi;kk=tmp.fi.se;pp=tmp.se;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
  }
	return 0;
}