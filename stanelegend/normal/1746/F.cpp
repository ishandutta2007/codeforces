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

mt19937 rnd(114514);
int n,q,a[300010],bad[300010],aa[300010];
LL H[600010];
vector <int> dsc;
vector <pair <pii,pii> > que;

namespace bit
{
  LL dat[300010];
  LL lowbit(LL k){return k&-k;}
  void upd(LL k,LL val)
  {
    while(k<=n)
    {
      dat[k]+=val;
      k+=lowbit(k);
    }
  }
  LL get(LL k)
  {
    LL ret=0;
    while(k>0)
    {
      ret+=dat[k];
      k-=lowbit(k);
    }
    return ret;
  }
}

int main()
{
  cin>>n>>q;
  rep(i,n) scanf("%d",&a[i]),dsc.pb(a[i]);
  int x,y,z;
  rep(i,q)
  {
    scanf("%d",&x);
    if(x==1)
    {
      scanf("%d%d",&x,&y);--x;dsc.pb(y);
      que.pb(mpr(mpr(1,0),mpr(x,y)));
    }
    else
    {
      scanf("%d%d%d",&x,&y,&z);--x;--y;
      que.pb(mpr(mpr(2,x),mpr(y,z)));
    }
  }
  sort(dsc.begin(),dsc.end());dsc.erase(unique(dsc.begin(),dsc.end()),dsc.end());
  rep(i,n) a[i]=lower_bound(dsc.begin(),dsc.end(),a[i])-dsc.begin();
  rep(i,q) if(que[i].fi.fi==1) que[i].se.se=lower_bound(dsc.begin(),dsc.end(),que[i].se.se)-dsc.begin();
  rep(ti,30)
  {
    rep(i,dsc.size()) H[i]=rnd();
    rep(i,n+3) bit::dat[i]=0;
    rep(i,n) aa[i]=a[i],bit::upd(i+1,H[a[i]]);
    rep(i,q)
    {
      if(que[i].fi.fi==1)
      {
        bit::upd(que[i].se.fi+1,-H[aa[que[i].se.fi]]);
        aa[que[i].se.fi]=que[i].se.se;
        bit::upd(que[i].se.fi+1,H[aa[que[i].se.fi]]);
      }
      else if(bad[i]==0)
      {
        LL val=bit::get(que[i].se.fi+1)-bit::get(que[i].fi.se);
        if(val%que[i].se.se!=0) bad[i]=1;
      }
    }
  }
  rep(i,q) if(que[i].fi.fi==2) puts(bad[i] ? "NO":"YES"); 
  return 0;
}