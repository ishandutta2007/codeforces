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

LL t,n,a[200010];
map <LL,LL> cnt,tmp;

LL gcd(LL x,LL y)
{
  if(y==0) return x;
  return gcd(y,x%y);
}

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n;
    cnt.clear();
    rep(i,n) scanf("%lld",&a[i]),++cnt[a[i]];
    tmp=cnt;
    LL sum=0;
    rep(i,n) sum+=a[i];
    LL g=gcd(sum,n);
    if(n/g!=1&&n/g!=2)
    {
      puts("0");
      continue;
    }
    LL need=sum*2/n,ans=0;
    for(auto it:cnt)
    {
      if(need-it.fi<it.fi) break;
      if(need-it.fi>it.fi) ans+=(it.se)*tmp[need-it.fi];
      else ans+=(it.se)*(it.se-1)/2;
    }
    printf("%lld\n",ans);
  }
  return 0;
}