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

int t,n,hv,ans[10010];
bool vis[10010];
vector <int> pos,val;

int qry(int i)
{
  printf("? %d\n",i);
  fflush(stdout);
  int ret;
  scanf("%d",&ret);
  return ret;
}

int main()
{
  scanf("%d",&t);
  rep(tn,t)
  {
    hv=0;
    scanf("%d",&n);
    rep(i,n+3) vis[i]=false;
    repn(i,n) if(!vis[i])
    {
      pos.clear();val.clear();
      LL lval=qry(i);
      pos.pb(lval);
      while(true)
      {
        LL v=qry(i);
        val.pb(v);
        if(v==lval) break;
        pos.pb(v);
      }
      rep(j,val.size())
      {
        vis[pos[j]]=true;
        ans[pos[j]]=val[j];
      }
    }
    printf("! ");
    repn(i,n) printf("%d ",ans[i]);puts("");
    fflush(stdout);
  }
  return 0;
}