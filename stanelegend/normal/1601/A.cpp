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

int t,n,a[200010],cnt[40];

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n;
    rep(i,35) cnt[i]=0;
    int mx=0;
    rep(i,n)
    {
      scanf("%d",&a[i]);
      mx=max(mx,a[i]);
      rep(j,31) if((a[i]&(1<<j))>0) ++cnt[j];
    }
    if(mx==0)
    {
      repn(i,n) printf("%d ",i);
      puts("");
      continue;
    }
    int res=0;
    rep(i,31) res=__gcd(res,cnt[i]);
    repn(i,res) if(res%i==0) printf("%d ",i);
    puts("");
  }
	return 0;
}