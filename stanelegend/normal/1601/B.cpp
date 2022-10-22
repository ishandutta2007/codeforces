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

int n,n2=1,a[300010],b[300010],to,out[300010],dist[2000010],lst[2000010];
vector <pii> g[2000010];
deque <pii> q;
vector <int> ans;

void build(int k,int lb,int ub)
{
  if(lb==ub) return;
  g[k].pb(mpr(k+k+1,0));g[k].pb(mpr(k+k+2,0));
  build(k+k+1,lb,(lb+ub)/2);build(k+k+2,(lb+ub)/2+1,ub);
}

void upd(int k,int lb,int ub,int tlb,int tub,int fr)
{
  if(ub<tlb||tub<lb) return;
  if(tlb<=lb&&ub<=tub)
  {
    g[fr].pb(mpr(k,1));
    return;
  }
  upd(k+k+1,lb,(lb+ub)/2,tlb,tub,fr);upd(k+k+2,(lb+ub)/2+1,ub,tlb,tub,fr);
}

void dijk()
{
  rep(i,2000005) dist[i]=1e9;
  dist[out[n]]=0;q.pb(mpr(0,out[n]));
  while(!q.empty())
  {
    pii f=q.front();q.pop_front();
    if(f.fi>dist[f.se]) continue;
    rep(i,g[f.se].size()) if(dist[g[f.se][i].fi]>f.fi+g[f.se][i].se)
    {
      dist[g[f.se][i].fi]=f.fi+g[f.se][i].se;lst[g[f.se][i].fi]=f.se;
      if(g[f.se][i].se==1) q.pb(mpr(dist[g[f.se][i].fi],g[f.se][i].fi));
      else q.push_front(mpr(dist[g[f.se][i].fi],g[f.se][i].fi));
    }
  }
}

int main()
{
  cin>>n;
  while(n2<n) n2*=2;to=n2+n2-1;repn(i,n) out[i]=n2+n2-1+i;
  repn(i,n) scanf("%d",&a[i]);
  repn(i,n)
  {
    scanf("%d",&b[i]);
    g[i-1+n2-1].pb(mpr(out[i+b[i]],0));
  }
  build(0,0,n2-1);
  
  repn(i,n)
  {
    if(a[i]==i)
    {
      --a[i];
      g[out[i]].pb(mpr(to,1));
    }
    upd(0,0,n2-1,i-a[i]-1,i-1,out[i]);
  }
  dijk();

  if(dist[to]==1e9) puts("-1");
  else
  {
    ans.pb(0);
    while(to!=out[n])
    {
      if(0+n2-1<=to&&to<=n2-1+n2-1) ans.pb(to-(n2-1)+1);
      //cout<<to<<' ';
      to=lst[to];
    }
    //cout<<out[n]<<endl;
    cout<<ans.size()<<endl;
    for(int i=ans.size()-1;i>=0;--i) printf("%d ",ans[i]);puts("");
  }

	return 0;
}