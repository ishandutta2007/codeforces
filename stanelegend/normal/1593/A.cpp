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

int t,a,b,c;

int solve(int aa,int bb,int cc)
{
  int ret=max(0,max(bb,cc)+1-aa);
  return ret;
}

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>a>>b>>c;
    cout<<solve(a,b,c)<<' '<<solve(b,a,c)<<' '<<solve(c,a,b)<<endl;
  }
	return 0;
}