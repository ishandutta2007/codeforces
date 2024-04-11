#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair

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

LL n,dp[210][210],sz[210],ans;
vector <LL> g[210],pth;
bool vis[210];

bool dfs(LL pos,LL to,LL par)
{
  pth.pb(pos);
  if(pos==to) return true;
  rep(i,g[pos].size()) if(g[pos][i]!=par) if(dfs(g[pos][i],to,pos)) return true;
  pth.pop_back();
  return false;
}

void dfs2(LL pos,LL par)
{
  sz[pos]=1;
  rep(i,g[pos].size()) if(g[pos][i]!=par&& !vis[g[pos][i]])
  {
    dfs2(g[pos][i],pos);
    sz[pos]+=sz[g[pos][i]];
  }
}

int main()
{
  cin>>n;
  LL x,y;
  rep(i,n-1)
  {
    scanf("%lld%lld",&x,&y);
    g[x].pb(y);g[y].pb(x);
  }
  repn(i,n+1) dp[0][i]=1;
  LL inv2=qpow(2,MOD-2),inv=qpow(n,MOD-2);
  repn(i,n) repn(j,n) dp[i][j]=(dp[i-1][j]+dp[i][j-1])*inv2%MOD;
  for(LL i=n;i>1;--i) for(int j=i-1;j>0;--j)
  {
    pth.clear();
    dfs(i,j,0);
    rep(k,n+3) vis[k]=false;
    rep(k,pth.size()) vis[pth[k]]=true;
    rep(k,pth.size()) dfs2(pth[k],0);
    (ans+=sz[pth[0]]*inv)%=MOD;
    repn(i,pth.size()-2) (ans+=sz[pth[i]]*inv%MOD*dp[i][pth.size()-i-1])%=MOD;
  }
  cout<<ans<<endl;
	return 0;
}