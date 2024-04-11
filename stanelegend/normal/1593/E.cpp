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

int t,n,k,dist[400010],r,ans;
vector <int> g[400010];

void dfs(int pos,int par)
{
  dist[pos]=1;
  rep(i,g[pos].size()) if(g[pos][i]!=par)
  {
    dfs(g[pos][i],pos);
    dist[pos]=max(dist[pos],dist[g[pos][i]]+1);
  }
}

void dfs2(int pos,int par,int d)
{
  if(g[pos].size()<=1) ++ans;
  else
  {
    vector <int> v;v.clear();
    if(pos!=r) v.pb(d);
    rep(i,g[pos].size()) if(g[pos][i]!=par) v.pb(dist[g[pos][i]]);
    sort(v.begin(),v.end());
    int ti=v[v.size()-2]+1;
    if(ti<=k) ++ans;
  }
  multiset <int> st;st.clear();
  st.insert(d);
  rep(i,g[pos].size()) if(g[pos][i]!=par) st.insert(dist[g[pos][i]]);
  rep(i,g[pos].size()) if(g[pos][i]!=par)
  {
    st.erase(st.lower_bound(dist[g[pos][i]]));
    dfs2(g[pos][i],pos,*st.rbegin()+1);
    st.insert(dist[g[pos][i]]);
  }
}

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n>>k;
    rep(i,n+3) g[i].clear();
    int x,y;
    rep(i,n-1)
    {
      scanf("%d%d",&x,&y);
      g[x].pb(y);g[y].pb(x);
    }
    r=-1;
    repn(i,n) if(g[i].size()>1)
    {
      r=i;
      break;
    }
    if(r==-1)
    {
      puts("0");
      continue;
    }
    dfs(r,0);
    ans=0;
    dfs2(r,0,0);
    printf("%d\n",n-ans);
  }
	return 0;
}