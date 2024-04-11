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

const LL MOD=998244353;

LL qpow(LL x,LL a)
{
	LL res=x,ret=1;
	while(a>0)
	{
		if((a&1)==1) ret=ret*res%MOD;
		a>>=1;
		res=res*res%MOD;
	}
	return ret;
}

LL n,m,a[200010],b[200010],cnt[200010],fac[200010],inv[200010],tot,cntb[200010];

namespace st
{
  LL n2=1,dat[800100];
  void upd(LL k,LL val)
  {
    dat[k]+=val;
    while(k>0)
    {
      k=(k-1)/2;
      dat[k]+=val;
    }
  }
  LL qry(LL k,LL lb,LL ub,LL tlb,LL tub)
  {
    if(ub<tlb||tub<lb) return 0;
    if(tlb<=lb&&ub<=tub) return dat[k];
    return qry(k+k+1,lb,(lb+ub)/2,tlb,tub)+qry(k+k+2,(lb+ub)/2+1,ub,tlb,tub);
  }
}

int main()
{
  fac[0]=1;repn(i,200005) fac[i]=fac[i-1]*(LL)i%MOD;
  rep(i,200003) inv[i]=qpow(fac[i],MOD-2);
  cin>>n>>m;
  rep(i,n)
  {
    scanf("%lld",&a[i]);
    ++cnt[a[i]];++cntb[a[i]];
  }
  rep(i,m) scanf("%lld",&b[i]);
  sort(a,a+n);
  while(st::n2<200001) st::n2*=2;
  rep(i,n) st::upd(a[i]+st::n2-1,1);
  tot=1;
  repn(i,200000) (tot*=inv[cnt[i]])%=MOD;
  LL ans=0;
  if(n<m)
  {
    bool ok=true;
    rep(i,n)
    {
      --cntb[b[i]];
      if(cntb[b[i]]<0) ok=false;
    }
    if(ok) ++ans;
  }
  rep(i,m)
  {
    LL val=st::qry(0,0,st::n2-1,0,b[i]-1);
    (ans+=fac[n-i]*tot%MOD*qpow(n-i,MOD-2)%MOD*val)%=MOD;
    if(cnt[b[i]]==0) break;
    (tot*=fac[cnt[b[i]]])%=MOD;
    --cnt[b[i]];
    (tot*=inv[cnt[b[i]]])%=MOD;
    st::upd(b[i]+st::n2-1,-1);
  }
  cout<<ans<<endl;
	return 0;
}