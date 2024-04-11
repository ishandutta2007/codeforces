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

int t,n,b[100010],k,ans[100010];
vector <int> v[100010];

int main()
{
  cin>>t;
  rep(tn,t)
  {
    scanf("%d",&n);
    rep(i,n+3) v[i].clear();
    repn(i,n)
    {
      scanf("%d",&b[i]);
      v[b[i]].pb(i);
    }
    int curnode,startpos=1,stat;
    if(v[0].size()>0) curnode=0,stat=1;
    else curnode=n+1,stat=0;
    k=0;
    while(startpos<=n)
    {
      int nxt=-1;vector <int> tmp;
      rep(i,v[curnode].size())
      {
        int u=v[curnode][i];
        if(v[u].size()>0) nxt=u;
        else tmp.pb(u);
      }
      rep(i,tmp.size()) ans[startpos+i]=tmp[i];
      ans[startpos+tmp.size()]=nxt;
      if(stat==0) k+=v[curnode].size();
      startpos+=v[curnode].size();
      curnode=nxt;
      stat^=1;
    }
    printf("%d\n",k);
    repn(i,n) printf("%d ",ans[i]);
    puts("");
  }
	return 0;
}