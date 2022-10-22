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

int n,ask[110],val[110],mn=1e9;
vector <pii> g[110];

void Ask()
{
  cout<<"? ";
  rep(i,n) cout<<ask[i]<<' ';cout<<endl;
  cout.flush();
}

void dfs(int pos,int v)
{
  val[pos]=v;mn=min(mn,v);
  rep(i,g[pos].size()) if(val[g[pos][i].fi]==-1e9) dfs(g[pos][i].fi,v+g[pos][i].se);
}

int main()
{
  cin>>n;
  for(int i=n-1;i>0;--i)
  {
    rep(j,n) ask[j]=1;
    ask[i]=2;
    Ask();
    int x;cin>>x;
    if(x>0&&x<=i)
    {
      --x;
      g[x].pb(mpr(i,-1));
      g[i].pb(mpr(x,1));
    }
    rep(j,n) ask[j]=2;
    ask[i]=1;
    Ask();
    cin>>x;
    if(x>0&&x<=i)
    {
      --x;
      g[x].pb(mpr(i,1));
      g[i].pb(mpr(x,-1));
    }
  }
  rep(i,n) val[i]=-1e9;
  dfs(0,0);
  rep(i,n) val[i]-=(mn-1);
  cout<<"! ";
  rep(i,n) cout<<val[i]<<' ';cout<<endl;
  cout.flush();
	return 0;
}