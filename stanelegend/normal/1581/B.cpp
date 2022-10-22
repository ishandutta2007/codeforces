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

LL t,n,m,k;

int main()
{
  cin>>t;
  rep(tn,t)
  {
    scanf("%lld%lld%lld",&n,&m,&k);
    if(m<n-1||n*(n-1)/2LL<m)
    {
      puts("NO");
      continue;
    }
    if(n==1) puts(k>=2 ? "YES":"NO");
    else if(n*(n-1)/2LL==m) puts(k>=3 ? "YES":"NO");
    else puts(k>=4 ? "YES":"NO");
  }
  return 0;
}