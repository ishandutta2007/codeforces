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

LL t,n,k,c[200010],bas[200010],dp[200010][2];
vector <LL> g[200010];

bool cmp(pii aa,pii bb){return aa.se-aa.fi>bb.se-bb.fi;}

void dfsPre(LL pos,LL cc)
{
  bas[pos]=cc;
  if(g[pos].size()==0) return;
  cc/=g[pos].size();
  if(cc==0) return;
  rep(i,g[pos].size()) dfsPre(g[pos][i],cc);
}

LL dfs(LL pos,LL cc)
{
  if(cc==0) return 0;
  LL w=(cc==bas[pos] ? 0:1);
  if(dp[pos][w]>-1) return dp[pos][w];//cout<<pos<<' '<<cc<<' '<<bas[pos]<<endl;
  LL ret=cc*c[pos];
  if(g[pos].size()==0) return dp[pos][w]=ret;
  LL soncnt=g[pos].size(),bass=cc/soncnt,mo=bass+1,mocnt=cc%soncnt;
  vector <pii> vs;
  rep(i,g[pos].size())
  {
    LL v1=dfs(g[pos][i],bass),v2=dfs(g[pos][i],mo);
    vs.pb(mpr(v1,v2));
  }
  sort(vs.begin(),vs.end(),cmp);
  rep(i,vs.size()) if(i<mocnt) ret+=vs[i].se;else ret+=vs[i].fi;
  //if(pos==3&&cc==2) cout<<ret<<endl;
  return dp[pos][w]=ret;
}

int main()
{
  cin>>t;
  rep(tn,t)
  {
    scanf("%lld%lld",&n,&k);
    rep(i,n+3) g[i].clear();
    LL x;
    for(int i=2;i<=n;++i)
    {
      scanf("%lld",&x);
      g[x].pb(i);
    }
    repn(i,n) scanf("%lld",&c[i]);
    rep(i,n+3) rep(j,2) dp[i][j]=-1;
    dfsPre(1,k);
    LL ans=dfs(1,k);
    printf("%lld\n",ans);
  }
  return 0;
}