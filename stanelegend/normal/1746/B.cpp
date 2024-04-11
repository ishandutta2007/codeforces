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

int t,n,a[100010],bk0[100010],nxt[100010];

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n;
    rep(i,n) scanf("%d",&a[i]);
    int lst=-1,cc=0;
    for(int i=n-1;i>=0;--i)
    {
      if(a[i]==0) ++cc;
      else
      {
        nxt[i]=lst;lst=i;
        bk0[i]=cc;
      }
    }
    if(lst==-1)
    {
      puts("0");
      continue;
    }
    int ans=bk0[lst],c1=0;
    rep(i,n) if(a[i]==1)
    {
      ++c1;
      int c0;
      if(nxt[i]==-1) ans=min(ans,c1);
      else
      {
        ans=min(ans,c1+max(0,bk0[nxt[i]]-c1));
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}