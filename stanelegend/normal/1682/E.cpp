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

int n,m,p[200010],val[200010],curval;
vector <pii> g[200010];
vector <int> gg[200010],ord;
bool vis[200010];

bool cmp(pii x,pii y)
{
  int xx=val[x.fi],yy=val[y.fi];
  if(xx<curval&&yy>curval) return false;
  if(xx>curval&&yy<curval) return true;
  return xx<yy;
}

void dfs(int pos)
{
  vis[pos]=true;
  rep(i,gg[pos].size()) if(!vis[gg[pos][i]]) dfs(gg[pos][i]);
  ord.pb(pos);
}

int main()
{
  cin>>n>>m;
  repn(i,n) scanf("%d",&p[i]);
  int x,y;
  repn(i,m)
  {
    scanf("%d%d",&x,&y);
    g[x].pb(mpr(y,i));g[y].pb(mpr(x,i));
  }
  repn(i,n) if(!vis[i])
  {
    vector <int> v;v.pb(i);vis[i]=true;
    int cur=i;
    while(true)
    {
      cur=p[cur];
      if(vis[cur]) break;
      v.pb(cur);vis[cur]=true;
    }
    int st=-1;
    if(v.size()==1) continue;
    rep(j,v.size()) val[v[j]]=j;
    rep(j,v.size())
    {
      curval=j;
      sort(g[v[j]].begin(),g[v[j]].end(),cmp);
      rep(k,g[v[j]].size()-1) gg[g[v[j]][k].se].pb(g[v[j]][k+1].se);
    }
  }
  memset(vis,0,sizeof(vis));
  repn(i,m) if(!vis[i]) dfs(i);
  for(int i=ord.size()-1;i>=0;--i) cout<<ord[i]<<' ';
  cout<<endl;
	return 0;
}