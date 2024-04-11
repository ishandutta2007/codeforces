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
 
const LL MOD=1e9+7;

int n,m,tag[300010],q,dep[300010],fa[300010],res=0;
bool vis[300010];
vector <int> g[300010],tg[300010],ans[300010];

void dfs(int pos,int par,int d)
{
  vis[pos]=true;dep[pos]=d;fa[pos]=par;
  rep(i,g[pos].size()) if(g[pos][i]!=par&& !vis[g[pos][i]])
  {
    dfs(g[pos][i],pos,d+1);
    tg[pos].pb(g[pos][i]);
  }
}

void dfs2(int pos,int par)
{
  int cnt=0;
  rep(i,tg[pos].size())
  {
    dfs2(tg[pos][i],pos);
    cnt+=tag[tg[pos][i]];
  }
  res+=cnt/2;
  if(cnt%2==1&&tag[pos]==0) ++res;
}

int main()
{
  cin>>n>>m;
  int x,y;
  rep(i,m)
  {
    scanf("%d%d",&x,&y);
    g[x].pb(y);g[y].pb(x);
  }
  dfs(1,0,0);
  cin>>q;
  rep(qn,q)
  {
    scanf("%d%d",&x,&y);
    vector <int> tmp;tmp.clear();
    while(dep[x]>dep[y])
    {
      ans[qn].pb(x);
      tag[x]^=1;
      x=fa[x];
    }
    while(dep[y]>dep[x])
    {
      tmp.pb(y);
      tag[y]^=1;
      y=fa[y];
    }
    while(x!=y)
    {
      ans[qn].pb(x);tmp.pb(y);
      tag[x]^=1;tag[y]^=1;
      x=fa[x];y=fa[y];
    }
    ans[qn].pb(x);
    for(int i=(int)(tmp.size())-1;i>=0;--i) ans[qn].pb(tmp[i]);
  }
  bool ok=true;
  repn(i,n) if(tag[i]==1) ok=false;
  if(ok)
  {
    puts("YES");
    rep(i,q)
    {
      cout<<ans[i].size()<<endl;
      rep(j,ans[i].size()) printf("%d ",ans[i][j]);
      puts("");
    }
    return 0;
  }
  puts("NO");
  dfs2(1,0);
  cout<<res<<endl;
	return 0;
}