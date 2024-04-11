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

LL t,n,up[200010],dn[200010],mx[200010],inv[200010],mm,ans;
vector <pair <LL,pii> > g[200010];
vector <LL> pri[200010];
bool ck=false;

void dv(LL val)
{
  rep(i,pri[val].size())
  {
    if(up[pri[val][i]]>0) --up[pri[val][i]];
    else
    {
      ++dn[pri[val][i]];
      if(ck) mx[pri[val][i]]=max(mx[pri[val][i]],dn[pri[val][i]]);
    }
  }
}

void mul(LL val)
{
  rep(i,pri[val].size())
  {
    if(dn[pri[val][i]]>0) --dn[pri[val][i]];
    else ++up[pri[val][i]];
  }
}

void dfs(LL pos,LL par)
{
  rep(i,g[pos].size()) if(g[pos][i].fi!=par)
  {
    mul(g[pos][i].se.se);ck=true;dv(g[pos][i].se.fi);ck=false;
    dfs(g[pos][i].fi,pos);
    mul(g[pos][i].se.fi);dv(g[pos][i].se.se);
  }
}

void dfs2(LL pos,LL par,LL cur)
{
  (ans+=cur)%=MOD;
  rep(i,g[pos].size()) if(g[pos][i].fi!=par) dfs2(g[pos][i].fi,pos,cur*inv[g[pos][i].se.fi]%MOD*g[pos][i].se.se%MOD);
}

int main()
{
  repn(i,200000)
  {
    int ii=i;
    for(int j=2;j*j<=ii;++j) if(ii%j==0)
    {
      while(ii%j==0)
      {
        pri[i].pb(j);
        ii/=j;
      }
    }
    if(ii>0) pri[i].pb(ii);
    inv[i]=qpow(i,MOD-2);
  }
  cin>>t;
  rep(tn,t)
  {
    scanf("%lld",&n);
    rep(i,n+3) g[i].clear();
    LL x,y,xx,yy;
    rep(i,n-1)
    {
      scanf("%lld%lld%lld%lld",&x,&y,&xx,&yy);
      g[x].pb(mpr(y,mpr(xx,yy)));g[y].pb(mpr(x,mpr(yy,xx)));
    }
    rep(i,n+3) mx[i]=0;
    dfs(1,0);
    mm=1;
    repn(i,n) (mm*=qpow(i,mx[i]))%=MOD;
    ans=0;
    dfs2(1,0,mm);
    printf("%lld\n",ans);
  }
  return 0;
}