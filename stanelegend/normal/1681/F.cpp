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

LL n,dep[500010],sz[500010],d[500010],u[500010],fa[500010],ans=0;
vector <pii> g[500010];
vector <LL> gg[1000010];
map <LL,vector <LL> > mp[500010];

void dfs(LL pos,LL par,LL pare)
{
  vector <LL> son;sz[pos]=1;fa[pos]=par;
  pii mx=mpr(-1,0);
  rep(i,g[pos].size()) if(g[pos][i].fi!=par)
  {
    dep[g[pos][i].fi]=dep[pos]+1;
    dfs(g[pos][i].fi,pos,g[pos][i].se);
    son.pb(g[pos][i].fi);sz[pos]+=sz[g[pos][i].fi];
    mx=max(mx,mpr((LL)mp[g[pos][i].fi].size(),g[pos][i].fi));
  }
  if(mx.fi>-1)
  {
    swap(mp[pos],mp[mx.se]);
    rep(i,son.size()) if(son[i]!=mx.se)
    {
      for(auto it:mp[son[i]])
      {
        if(mp[pos].find(it.fi)==mp[pos].end()) mp[pos][it.fi]=it.se;
        else rep(j,it.se.size()) mp[pos][it.fi].pb(it.se[j]);
      }
    }
  }
  if(pare>-1)
  {
    if(mp[pos].find(pare)!=mp[pos].end())
    {
      rep(i,mp[pos][pare].size())
      {
        d[pos]+=sz[mp[pos][pare][i]];
        gg[pos].pb(mp[pos][pare][i]);
      }
    }
    mp[pos][pare]=vector <LL>{pos};
  }
}

void dfs2(LL pos)
{
  LL add=(pos>n ? 0LL:n-sz[pos]);
  rep(i,gg[pos].size())
  {
    dfs2(gg[pos][i]);
    add+=sz[gg[pos][i]];
  }
  rep(i,gg[pos].size()) u[gg[pos][i]]=add-sz[gg[pos][i]];
}

void dfs3(LL pos,LL par)
{
  if(pos>1)
  {
    LL uu=n-sz[pos]-u[pos],dd=sz[pos]-d[pos];
    ans+=uu*dd;
  }
  rep(i,g[pos].size()) if(g[pos][i].fi!=par) dfs3(g[pos][i].fi,pos);
}

int main()
{
  cin>>n;
  LL x,y,z;
  rep(i,n-1)
  {
    scanf("%lld%lld%lld",&x,&y,&z);
    g[x].pb(mpr(y,z));g[y].pb(mpr(x,z));
  }
  dfs(1,0,-1);
  LL len=n;
  for(auto it:mp[1])
  {
    ++len;
    rep(i,it.se.size()) gg[len].pb(it.se[i]);
    dfs2(len);
  }
  dfs3(1,0);
  cout<<ans<<endl;
	return 0;
}