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

int n,m,x[200010],y[200010],t=340,ans[200010],r[400][400],rr[400][400],lst[200010];
vector <int> op[200010];
vector <pii> que;

void add(int st,int id,int ty)
{
  int cir=x[id]+y[id];
  int lb=(st+x[id])%cir,ub=(st+x[id]+y[id]-1)%cir;
  if(lb<=ub) r[cir][lb]+=ty,r[cir][ub+1]-=ty;
  else
  {
    r[cir][0]+=ty;r[cir][ub+1]-=ty;
    r[cir][lb]+=ty;r[cir][cir]-=ty;
  }
  rr[cir][0]=r[cir][0];
  repn(i,cir-1) rr[cir][i]=rr[cir][i-1]+r[cir][i];
}

int main()
{
  cin>>n>>m;
  rep(i,n) scanf("%d%d",&x[i],&y[i]);
  int xx,yy;
  rep(i,m)
  {
    scanf("%d%d",&xx,&yy);--yy;
    que.pb(mpr(xx,yy));
    if(xx==1) op[yy].pb(i);
    else op[yy].pb(i-1);
  }
  rep(i,n) if(op[i].size()>0)
  {
    if(op[i].size()%2==1) op[i].pb(m-1);
    if(x[i]+y[i]>=t)
    {
      for(int j=0;j<op[i].size();j+=2)
      {
        int lb=op[i][j],ub=op[i][j+1];
        for(int k=lb+x[i];k<=ub;k+=x[i]+y[i]) ++ans[k],--ans[min(k+y[i]-1,ub)+1];
      }
    }
  }
  int res=0;
  rep(i,m)
  {
    res+=ans[i];
    if(x[que[i].se]+y[que[i].se]<t)
    {
      if(que[i].fi==1) add(i,que[i].se,1),lst[que[i].se]=i;
      else add(lst[que[i].se],que[i].se,-1);
    }
    int prt=0;
    for(int j=2;j<t;++j) prt+=rr[j][i%j];
    printf("%d\n",res+prt);
  }
  return 0;
}