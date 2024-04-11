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

LL t,n,k,a[400010];

int main()
{
  cin>>t;
  rep(tn,t)
  {
    scanf("%lld%lld",&n,&k);
    rep(i,k) scanf("%lld",&a[i]);
    sort(a,a+k);
    LL cnt=0,lft=n;
    for(int i=k-1;i>=0;--i)
    {
      if(lft-(n-a[i])<=0) break;
      ++cnt;
      lft-=(n-a[i]);
    }
    printf("%lld\n",cnt);
  }
	return 0;
}