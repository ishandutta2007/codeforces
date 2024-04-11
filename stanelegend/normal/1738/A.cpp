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

LL t,n,tt[100010],vv[100010];
vector <LL> a,b;

int main()
{
  cin>>t;
  rep(tn,t)
  {
    scanf("%lld",&n);
    a.clear();b.clear();
    rep(i,n) scanf("%lld",&tt[i]);
    rep(i,n) scanf("%lld",&vv[i]);
    LL ans=0;
    LL mn=1e18;
    rep(i,n)
    {
      if(tt[i]==0) a.pb(vv[i]);else b.pb(vv[i]);
      ans+=vv[i];
      mn=min(mn,vv[i]);
    }
    sort(a.begin(),a.end());reverse(a.begin(),a.end());
    sort(b.begin(),b.end());reverse(b.begin(),b.end());
    if(a.size()==b.size())
    {
      printf("%lld\n",ans*2-mn);
      continue;
    }
    LL sz=min(a.size(),b.size()),v1=0,v2=0;
    rep(i,sz) v1+=a[i];rep(i,sz) v1+=b[i];
    ans+=v1;
    printf("%lld\n",ans);
  }
	return 0;
}