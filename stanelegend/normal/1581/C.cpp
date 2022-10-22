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

int n,m,r[410][410],c[410][410],ans;
string s[410];

int main()
{
  ios::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--)
  {
    ans=16;
    cin>>n>>m;
    rep(i,n)
    {
      cin>>s[i];
      rep(j,m)
      {
        r[i][j+1]=r[i][j]+s[i][j]-'0';
        c[i+1][j]=c[i][j]+s[i][j]-'0';
      }
    }
    for(int lb=1;lb<n-1;++lb) for(int ub=lb+2;ub<n-1;++ub)
    {
      for(int st=0;st+3<m;++st)
      {
        int res=(ub-lb+1)-(c[ub+1][st]-c[lb][st]);
        if(res>=ans) continue;
        for(int i=st+1;i<=st+2;++i)
        {
          res+=c[ub+1][i]-c[lb][i];
          res+=(s[lb-1][i]=='0')+(s[ub+1][i]=='0');
        }
        if(res>=ans) continue;
        for(int ed=st+3;ed<m;++ed)
        {
          if(res>=ans) break;
          ans=min(ans,res+(ub-lb+1)-(c[ub+1][ed]-c[lb][ed]));
          res+=c[ub+1][ed]-c[lb][ed];
          res+=(s[lb-1][ed]=='0')+(s[ub+1][ed]=='0');
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}