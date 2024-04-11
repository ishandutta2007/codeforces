#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <LL,LL>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair

using namespace std;

LL n,m,tag,ans=0;
map <LL,vector <pii> > v;
vector <pii> vv;

namespace st
{
  LL n2=1,num[400010],sump[400010],sums[400010];
  void upd(LL k,LL val,LL mul)
  {
    sump[k]+=(val-tag)*mul;sums[k]+=(-val-tag)*mul;
    num[k]+=mul;
    if(mul==-1) num[k]=sump[k]=sums[k]=0;
    while(k>0)
    {
      k=(k-1)/2;
      sump[k]+=(val-tag)*mul;sums[k]+=(-val-tag)*mul;
      num[k]+=mul;
      if(mul==-1) num[k]=sump[k]=sums[k]=0;
    }
  }
  pii qrys(LL k,LL lb,LL ub,LL tlb,LL tub)
  {
    if(ub<tlb||tub<lb) return mpr(0,0);
    if(tlb<=lb&&ub<=tub) return mpr(sums[k],num[k]);
    pii v1=qrys(k+k+1,lb,(lb+ub)/2,tlb,tub),v2=qrys(k+k+2,(lb+ub)/2+1,ub,tlb,tub);
    return mpr(v1.fi+v2.fi,v1.se+v2.se);
  }
  pii qryp(LL k,LL lb,LL ub,LL tlb,LL tub)
  {
    if(ub<tlb||tub<lb) return mpr(0,0);
    if(tlb<=lb&&ub<=tub) return mpr(sump[k],num[k]);
    pii v1=qryp(k+k+1,lb,(lb+ub)/2,tlb,tub),v2=qryp(k+k+2,(lb+ub)/2+1,ub,tlb,tub);
    return mpr(v1.fi+v2.fi,v1.se+v2.se);
  }
}

int main()
{
  cin>>n>>m;
  LL x;
  rep(i,n) rep(j,m)
  {
    scanf("%lld",&x);
    v[x].pb(mpr(i,j));
  }
  while(st::n2<m) st::n2*=2;
  for(auto it:v)
  {
    vv=it.se;
    tag=0;
    rep(i,vv.size())
    {
      if(i-1>=0) tag+=(vv[i].fi-vv[i-1].fi);
      int p=i;
      while(p+1<vv.size()&&vv[p+1].fi==vv[i].fi) ++p;
      for(int j=i;j<=p;++j)
      {
        pii val=st::qrys(0,0,st::n2-1,0,vv[j].se),val2=st::qryp(0,0,st::n2-1,vv[j].se+1,m-1);
        ans+=(val.fi+val.se*vv[j].se+tag*val.se)+(val2.fi-val2.se*vv[j].se+tag*val2.se);
        //if(it.fi==2&&j==1) cout<<ans<<' '<<(val.fi+val.se*vv[j].se+tag*val.se)<<' '<<(val2.fi-val2.se*vv[j].se+tag*val2.se)<<'p'<<endl;
        st::upd(vv[j].se+st::n2-1,vv[j].se,1);
      }
      i=p;
    }
    rep(i,vv.size()) st::upd(vv[i].se+st::n2-1,vv[i].se,-1);
  }
  cout<<ans<<endl;
	return 0;
}