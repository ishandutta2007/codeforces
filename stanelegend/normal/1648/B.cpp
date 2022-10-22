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

LL t,n,c,x,cnt[1000010],sum[1000010];

int main()
{
  cin>>t;
  rep(tn,t)
  {
    scanf("%lld%lld",&n,&c);
    rep(i,c+3) cnt[i]=0;
    rep(i,n)
    {
      scanf("%lld",&x);
      cnt[x]=1;
    }
    if(cnt[1]==0)
    {
      puts("No");
      continue;
    }
    sum[1]=cnt[1];for(int i=2;i<=c;++i) sum[i]=sum[i-1]+cnt[i];
    bool ok=true;
    for(LL i=2;i<=c;++i) if(cnt[i]>0)
    {
      for(LL j=2;j*i<=c;++j)
      {
        LL lb=j*i,ub=min(c,lb+i-1);
        if(sum[ub]-sum[lb-1]>0&&cnt[j]==0) ok=false;
      }
    }
    puts(ok ? "Yes":"No");
  }
	return 0;
}