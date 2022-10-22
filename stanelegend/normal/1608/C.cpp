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

int t,n,a[100010],b[100010];
vector <pair <pii,int> > l,r;
string ans;

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n;
    rep(i,n) scanf("%d",&a[i]);
    rep(i,n) scanf("%d",&b[i]);
    l.clear();r.clear();
    rep(i,n)
    {
      l.pb(mpr(mpr(a[i],b[i]),i));
      r.pb(mpr(mpr(b[i],a[i]),i));
    }
    sort(l.begin(),l.end());reverse(l.begin(),l.end());
    sort(r.begin(),r.end());reverse(r.begin(),r.end());
    int lc=0,rc=0,rmn=l[0].fi.se,lmn=r[0].fi.se;
    while(true)
    {
      bool ok=false;
      while(rc+1<r.size()&&r[rc+1].fi.fi>rmn)
      {
        ok=true;
        ++rc;
        lmn=min(lmn,r[rc].fi.se);
      }
      while(lc+1<l.size()&&l[lc+1].fi.fi>lmn)
      {
        ok=true;
        ++lc;
        rmn=min(rmn,l[lc].fi.se);
      }
      if(!ok) break;
    }
    ans="";rep(i,n) ans.pb('0');
    rep(i,lc+1) ans[l[i].se]='1';
    rep(i,rc+1) ans[r[i].se]='1';
    printf("%s\n",ans.c_str());
  }
	return 0;
}