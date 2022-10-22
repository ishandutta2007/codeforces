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

LL t,n,a[200010];
multiset <LL> cur,lft;

int main()
{
  cin>>t;
  rep(tn,t)
  {
    scanf("%lld",&n);
    LL sum=0;
    rep(i,n) scanf("%lld",&a[i]),sum+=a[i];
    cur.clear();lft.clear();
    rep(i,n) lft.insert(a[i]);
    cur.insert(sum);
    bool ok=true;
    while(true)
    {
      if(cur.size()>lft.size())
      {
        ok=false;
        break;
      }
      vector <LL> tmp;
      for(auto it:cur)
      {
        if(lft.find(it)!=lft.end())
        {
          tmp.pb(it);
          lft.erase(lft.lower_bound(it));
        }
      }
      rep(i,tmp.size()) cur.erase(cur.lower_bound(tmp[i]));
      if(cur.empty()) break;
      multiset <LL> ncur;
      for(auto it:cur) ncur.insert(it/2),ncur.insert((it+1)/2);
      cur=ncur;
    }
    puts(ok ? "YES":"NO");
  }
  return 0;
}