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

int t,x,y;

int main()
{
  cin>>t;
  rep(tn,t)
  {
    scanf("%d%d",&x,&y);
    if((x+y)%2==1)
    {
      puts("-1 -1");
      continue;
    }
    bool ok=false;
    rep(i,51)
    {
      rep(j,51)
      {
        if(i+j==(x+y)/2&&abs(i-x)+abs(j-y)==(x+y)/2)
        {
          printf("%d %d\n",i,j);
          ok=true;
          break;
        }
      }
      if(ok) break;
    }
    if(!ok) puts("-1 -1");
  }
  return 0;
}