#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

int t,n,m,a[1000010],b[1000010],s[1000010],res[4000010];
LL ans;
vector <int> dsc;

void chmin(int &x,int y){if(x>y) x=y;}

namespace st
{
  int n2,dat[8000010],add[8000010],addmn[8000010];
  void upda(int k)
  {
    ++dat[k];
    while(k>0)
    {
      k=(k-1)>>1;
      ++dat[k];
    }
  }
  LL qrya(int k,int lb,int ub,int tlb,int tub)
  {
    if(ub<tlb||tub<lb) return 0;
    if(tlb<=lb&&ub<=tub) return dat[k];
    return qrya(k+k+1,lb,(lb+ub)/2,tlb,tub)+qrya(k+k+2,(lb+ub)/2+1,ub,tlb,tub);
  }
  void pushDown(int k)
  {
    for(int i=k+k+1;i<=k+k+2;++i)
    {
      chmin(addmn[i],add[i]+addmn[k]);
      add[i]+=add[k];
    }
    add[k]=addmn[k]=0;
  }
  void upd(int k,int lb,int ub,int tlb,int tub,int val)
  {
    if(ub<tlb||tub<lb) return;
    if(tlb<=lb&&ub<=tub)
    {
      add[k]+=val;chmin(addmn[k],add[k]);
      return;
    }
    pushDown(k);
    upd(k+k+1,lb,(lb+ub)>>1,tlb,tub,val);upd(k+k+2,(lb+ub)/2+1,ub,tlb,tub,val);
  }
  void build(int k,int lb,int ub)
  {
    if(lb==ub)
    {
      res[lb]=addmn[k];
      return;
    }
    pushDown(k);
    build(k+k+1,lb,(lb+ub)>>1);build(k+k+2,(lb+ub)/2+1,ub);
  }
}

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n>>m;
    dsc.clear();
    rep(i,n) scanf("%d",&a[i]),dsc.pb(a[i]);
    rep(i,m) scanf("%d",&b[i]),dsc.pb(b[i]);
    sort(dsc.begin(),dsc.end());dsc.erase(unique(dsc.begin(),dsc.end()),dsc.end());
    rep(i,n) a[i]=lower_bound(dsc.begin(),dsc.end(),a[i])-dsc.begin();
    rep(i,m) b[i]=lower_bound(dsc.begin(),dsc.end(),b[i])-dsc.begin();
    st::n2=1;while(st::n2<dsc.size()) st::n2*=2;
    rep(i,st::n2+st::n2+5) st::dat[i]=st::add[i]=st::addmn[i]=0;
    ans=0;
    rep(i,n)
    {
      ans+=st::qrya(0,0,st::n2-1,a[i]+1,dsc.size()-1);
      st::upda(a[i]+st::n2-1);
    }
    rep(i,m) s[i]=st::qrya(0,0,st::n2-1,0,b[i]-1);
    rep(i,n) st::upd(0,0,st::n2-1,0,a[i]-1,1),st::upd(0,0,st::n2-1,a[i]+1,dsc.size()-1,-1);
    st::build(0,0,st::n2-1);
    rep(i,m) ans+=(LL)(s[i]+res[b[i]]);
    printf("%lld\n",ans);
  }
	return 0;
}