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

LL t,n,k,s[100010];

int main()
{
  cin>>t;
  rep(tn,t)
  {
    scanf("%lld%lld",&n,&k);
    for(int i=n-k+1;i<=n;++i) scanf("%lld",&s[i]);
    LL lst=1e12,ok=1;
    for(int i=n-1;i>=n-k+1;--i)
    {
      LL cur=s[i+1]-s[i];
      if(cur>lst)
      {
        ok=0;
        break;
      }
      lst=cur;
    }
    LL can=(n-k+1)*lst;
    if(can<s[n-k+1]) ok=0;
    puts(ok==1 ? "YES":"NO");
  }
	return 0;
}