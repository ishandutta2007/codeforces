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

int t,n,a[1010],val[1010][1010];

int main()
{
  cin>>t;
  rep(tn,t)
  {
    scanf("%d",&n);
    repn(i,n) scanf("%d",&a[i]);
    rep(i,n+3) rep(j,n+3) val[i][j]=0;
    repn(i,n)
    {
      val[i][i]=0;
      for(int j=i+1;j<=n;++j) val[i][j]=max(val[i][j-1],a[j-1]+a[j]);
    }
    int ans=val[1][n];
    repn(i,n) for(int j=i;j<=n;++j)
    {
      int res=max(max(val[1][i-1],val[j+1][n]),val[i][j]);
      res=max(res,max((i==1 ? 0:a[i-1]+a[j]),(j==n ? 0:a[j+1]+a[i])));
      ans=max(ans,res);
    }
    printf("%d\n",ans);
  }
  return 0;
}