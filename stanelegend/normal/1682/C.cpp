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

int t,n,a[200010];
map <int,int> mp;

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n;
    mp.clear();
    rep(i,n) cin>>a[i],++mp[-a[i]];
    int mo=0,one=0;
    for(auto it:mp) if(it.se==1) ++one;else ++mo;
    if(one==0) cout<<mo<<endl;
    else
    {
      --one;++mo;
      cout<<mo+one/2<<endl;
    }
  }
	return 0;
}