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

LL t,n,a[100010];

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n;
    rep(i,n) scanf("%lld",&a[i]);
    sort(a,a+n);
    LL ans=a[n-1],sum=0;
    for(int i=n-1;i>=0;--i)
    {
      if(sum>0) ans-=(sum-(LL)(n-i-1)*a[i]);
      sum+=a[i];
    }
    printf("%lld\n",ans);
  }
	return 0;
}