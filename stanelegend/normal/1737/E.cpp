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

const LL MOD=1e9+7;

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

LL t,n,ans[1000010],win[1000010],add[1000010],mid[1000010],midadd[1000010],wsum[1000010],inv2=qpow(2,MOD-2);

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n;
    if(n==1)
    {
      puts("1");
      continue;
    }
    rep(i,n+3) win[i]=add[i]=mid[i]=midadd[i]=0;
    ++add[0];add[(n-1)/2+1]=MOD-1;
    LL totadd=0,totmadd=0;
    rep(i,n)
    {
      (totadd+=add[i])%=MOD;
      win[i]=totadd;
      //win->mid
      (midadd[i]+=win[i])%=MOD;

      (totmadd+=midadd[i])%=MOD;
      mid[i]=totmadd;
      
      //mid->win
      LL lim=(n-i-1)/2;
      if(lim>=2)
      {
        (add[i+2]+=mid[i])%=MOD;
        (add[i+lim+1]+=MOD-mid[i])%=MOD;
      }
    }
    rep(i,n+3) ans[i]=0;
    wsum[0]=win[0];
    repn(i,n) wsum[i]=(wsum[i-1]+win[i])%MOD;
    //
    ans[1]=wsum[n-2];
    //rep(i,4) cout<<win[i]<<'p';cout<<endl;
    //
    repn(i,n-1)
    {
      LL mng=max(1LL,(LL)i/2),mxg=i-1,val=1;
      if(mng<=mxg)
      {
        LL av=(qpow(2,i-mng)-qpow(2,i-mxg-1)+MOD)%MOD;
        (val+=av)%=MOD;
      }
      (ans[i]+=val*wsum[n-i-1])%=MOD;
    }
    //
    LL mng=(n-1)/2,mxg=n-2,val=1;
    if(mng<=mxg)
    {
      LL av=(qpow(2,n-1-mng)-qpow(2,n-1-mxg-1)+MOD)%MOD;
      (val+=av)%=MOD;
    }
    (ans[n-1]+=val)%=MOD;
    //rep(i,n) cout<<ans[i]<<' ';cout<<endl;

    LL tot=qpow(2,n);tot=qpow(tot,MOD-2);
    rep(i,n)
    {
      (ans[i]*=tot)%=MOD;
      printf("%lld\n",ans[i]);
    }
  }
	return 0;
}