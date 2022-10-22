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

LL t,a,b,x;
bool ok;

void gcd(LL aa,LL bb)
{
  if(aa==x||bb==x)
  {
    ok=true;
    return;
  }
  if(bb==0) return;
  LL rem=aa%bb;
  if(x%bb==rem&&rem<=x&&x<=aa)
  {
    ok=true;
    return;
  }
  gcd(bb,rem);
}

int main()
{
  cin>>t;
  rep(tn,t)
  {
    scanf("%lld%lld%lld",&a,&b,&x);
    ok=false;
    gcd(max(a,b),min(a,b));
    puts(ok ? "YES":"NO");
  }
  return 0;
}