#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <LL,LL>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back

using namespace std;

LL t,n,m,f[510][510];
vector <pair <pii,LL> > e;

int main()
{
  cin>>t;
  rep(tn,t)
  {
    scanf("%lld%lld",&n,&m);
    rep(i,n+3) rep(j,n+3) f[i][j]=1e9;
    repn(i,n) f[i][i]=0;
    e.clear();
    LL x,y,z;
    rep(i,m)
    {
      scanf("%lld%lld%lld",&x,&y,&z);
      e.pb(mpr(mpr(x,y),z));
      f[x][y]=f[y][x]=1;
    }
    repn(k,n) repn(i,n) repn(j,n) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    LL ans=1e18;
    rep(i,m)
    {
      ans=min(ans,e[i].se*min(f[e[i].fi.fi][1]+f[e[i].fi.se][n]+1,f[e[i].fi.se][1]+f[e[i].fi.fi][n]+1));
      LL u=e[i].fi.fi,v=e[i].fi.se;
      repn(j,n)
      {
        LL val=f[u][j]+1;
        val+=f[j][1]+f[j][n]+1;
        ans=min(ans,e[i].se*val);

        val=f[v][j]+1;
        val+=f[j][1]+f[j][n]+1;
        ans=min(ans,e[i].se*val);
      }
    }
    printf("%lld\n",ans);
  }
	return 0;
}