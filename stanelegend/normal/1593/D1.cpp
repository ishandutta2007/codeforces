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

int t,n,a[50];

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n;
    rep(i,n) cin>>a[i];
    sort(a,a+n);
    if(a[0]==a[n-1])
    {
      puts("-1");
      continue;
    }
    int ans=0;
    rep(i,n-1) ans=__gcd(ans,a[i+1]-a[i]);
    cout<<ans<<endl;
  }
	return 0;
}