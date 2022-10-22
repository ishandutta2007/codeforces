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

int t,n,a[100010];
vector <pii> v;

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n;
    v.clear();
    repn(i,n) scanf("%d",&a[i]),v.pb(mpr(a[i],i));
    sort(v.begin(),v.end());reverse(v.begin(),v.end());
    rep(i,v.size()) printf("%d ",v[i].se);puts("");
  }
  return 0;
}