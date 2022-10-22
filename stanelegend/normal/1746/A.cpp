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

int t,n,k,a[60];

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n>>k;
    bool ok=false;
    rep(i,n)
    {
      cin>>a[i];
      ok|=(a[i]==1);
    }
    puts(ok ? "YES":"NO");
  }
  return 0;
}