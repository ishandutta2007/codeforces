#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair

using namespace std;

LL t,n,c[510][510];

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n;
    rep(i,n+n) rep(j,n+n) scanf("%lld",&c[i][j]);
    LL ans=0;
    for(int i=n;i<n+n;++i) for(int j=n;j<n+n;++j) ans+=c[i][j];
    LL res=min(min(c[n][0],c[n][n-1]),min(c[n+n-1][0],c[n+n-1][n-1]));
    res=min(res,min(min(c[0][n],c[0][n+n-1]),min(c[n-1][n],c[n-1][n+n-1])));
    printf("%lld\n",ans+res);
  }
  return 0;
}