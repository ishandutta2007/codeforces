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

LL t,n,a[100010],pref[100010],suf[100010],fac[100010],inv[100010];
vector <pair <LL,pii> > v;
map <LL,pii> mp;

LL C(LL nn,LL mm){return fac[nn]*inv[mm]%MOD*inv[nn-mm]%MOD;}

int main()
{
  fac[0]=1;repn(i,100005) fac[i]=fac[i-1]*i%MOD;
  rep(i,100003) inv[i]=qpow(fac[i],MOD-2);
  cin>>t;
  rep(tn,t)
  {
    scanf("%lld",&n);
    repn(i,n)
    {
      scanf("%lld",&a[i]);
      pref[i]=pref[i-1]+a[i];
    }
    suf[n+1]=0;
    for(int i=n;i>0;--i) suf[i]=suf[i+1]+a[i];
    v.clear();
    repn(i,n)
    {
      int p=i;
      while(p+1<=n&&pref[p+1]==pref[i]) ++p;
      v.pb(mpr(pref[i],mpr(i,p)));
      i=p;
    }
    mp.clear();
    for(int i=n;i>0;--i)
    {
      int p=i;
      while(p-1>0&&suf[p-1]==suf[i]) --p;
      mp[suf[i]]=mpr(p,i);
      i=p;
    }
    LL pre=1;
    rep(i,v.size()) if(mp.find(v[i].fi)!=mp.end())
    {
      LL l1=v[i].se.fi,r1=v[i].se.se,l2=mp[v[i].fi].fi,r2=mp[v[i].fi].se;
      if(r1<l2)
      {
        LL tot=0;
        repn(cho,min(r1-l1+1,r2-l2+1)) (tot+=C(r1-l1+1,cho)*C(r2-l2+1,cho))%=MOD;
        (pre+=tot*pre)%=MOD;
      }
      else
      {
        LL tot=0;
        repn(cho,(r2-l1+1)/2) (tot+=C(r2-l1+1,cho+cho))%=MOD;
        (pre+=tot*pre)%=MOD;
        break;
      }
    }
    printf("%lld\n",pre);
  }
	return 0;
}