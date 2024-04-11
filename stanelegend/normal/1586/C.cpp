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

int n,m,q,mn[200010],ans[200010];
string s[1000010];
vector <pair <pii,int> > que;
vector <int> up[1000010],lft[1000010];

void upd(int i,int j,int u,int l)
{
  up[i][j]=min(up[i][j],u);
  lft[i][j]=min(lft[i][j],l);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  cin>>n>>m;
  rep(i,n) cin>>s[i];
  cin>>q;
  int x,y;
  rep(i,q)
  {
    cin>>x>>y;--x;--y;
    que.pb(mpr(mpr(x,y),i));
  }
  sort(que.begin(),que.end());
  rep(i,n) rep(j,m)
  {
    up[i].pb((s[i][j]=='X' ? 1e9:i));
    lft[i].pb((s[i][j]=='X' ? 1e9:j));
  }
  rep(i,n) rep(j,m) if(s[i][j]=='.')
  {
    if(j+1<m&&s[i][j+1]=='.') upd(i,j+1,up[i][j],lft[i][j]);
    if(i+1<n&&s[i+1][j]=='.') upd(i+1,j,up[i][j],lft[i][j]);
  }
  rep(i,q+5) mn[i]=1e9;
  repn(i,n-1) repn(j,m-1)
  {
    if(up[i][j]==0||up[i-1][j]==0||up[i][j-1]==0) continue;
    int f=min(min(lft[i][j],lft[i][j-1]),min(lft[i-1][j],j))-1;
    if(f<0) continue;
    int pos=lower_bound(que.begin(),que.end(),mpr(mpr(f+1,0),0))-que.begin()-1;
    if(pos>=0) mn[pos]=min(mn[pos],j);
  }
  int cur=1e9;
  for(int i=q-1;i>=0;--i)
  {
    cur=min(cur,mn[i]);
    if(que[i].fi.se>=cur) ans[que[i].se]=1;
  }
  rep(i,q) cout<<(ans[i]==1 ? "NO":"YES")<<endl;
	return 0;
}