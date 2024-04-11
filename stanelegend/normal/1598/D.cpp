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

LL t,n,a[200010],b[200010],cnt[200010];
vector <int> v[200010];

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n;
    rep(i,n+5) v[i].clear(),cnt[i]=0;
    rep(i,n)
    {
      scanf("%lld%lld",&a[i],&b[i]);
      v[a[i]].pb(b[i]);++cnt[b[i]];
    }
    LL ans=0;
    repn(i,n) if(v[i].size()>=2) rep(j,v[i].size()) ans+=(cnt[v[i][j]]-1)*(LL)(v[i].size()-1);
    printf("%lld\n",n*(n-1)*(n-2)/6LL-ans);
  }
  return 0;
}