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

LL t,n,l[100010],r[100010],c[100010];

int main()
{
  cin>>t;
  rep(tn,t)
  {
    scanf("%lld",&n);
    rep(i,n) scanf("%lld%lld%lld",&l[i],&r[i],&c[i]);
    LL mx=-1,mxv=-1,ml=1e18,mlv=-1,mr=-1e18,mrv=-1;
    rep(i,n)
    {
      if(r[i]-l[i]+1>mx)
      {
        mx=r[i]-l[i]+1;
        mxv=c[i];
      }
      else if(r[i]-l[i]+1==mx) mxv=min(mxv,c[i]);
      if(l[i]<ml)
      {
        ml=l[i];
        mlv=c[i];
      }
      else if(l[i]==ml) mlv=min(mlv,c[i]);
      if(r[i]>mr)
      {
        mr=r[i];
        mrv=c[i];
      }
      else if(r[i]==mr) mrv=min(mrv,c[i]);
      LL ans=1e18;
      if(mx==mr-ml+1) ans=min(ans,mxv);
      ans=min(ans,mlv+mrv);
      printf("%lld\n",ans);
    }
  }
  return 0;
}