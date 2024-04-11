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

const LL MOD=1e9+7;

LL n,a[500010],fac[500010],cnt[1000010],ans=0,cntans=1;
map <LL,LL> mp;

int main()
{
  fac[0]=1;repn(i,500005) fac[i]=fac[i-1]*(LL)i%MOD;
  cin>>n;
  rep(i,n) scanf("%lld",&a[i]),++cnt[a[i]];
  LL sum=0;
  for(int i=999999;i>0;i-=2)
  {
    sum+=cnt[i];
    (cntans*=fac[sum]*(i==1 ? 1LL:fac[sum])%MOD)%=MOD;
    //if(i>1) cout<<fac[sum]<<endl;
    mp[-(i-1)]+=sum;if(i-1>0) mp[i-1]+=sum;
  }
  sum=0;
  for(int i=1000000;i>0;i-=2)
  {
    sum+=cnt[i];
    (cntans*=fac[sum]*fac[sum]%MOD)%=MOD;
    mp[-(i-1)]+=sum;mp[i-1]+=sum;
  }
  LL bas=0;
  for(auto it:mp)
  {
    LL val=it.se%MOD;
    //bas+1...bas+val
    (ans+=(bas+1+bas+val)*val/2LL%MOD*it.fi)%=MOD;
    bas+=val;
  }
  cout<<ans<<' '<<cntans<<endl;
  return 0;
}