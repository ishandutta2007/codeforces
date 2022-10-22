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

int t,n,m;
bool vis[100010];

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n>>m;
    rep(i,n+5) vis[i]=false;
    int x,y,z;
    rep(i,m)
    {
      scanf("%d%d%d",&x,&y,&z);
      vis[y]=true;
    }
    repn(i,n) if(!vis[i])
    {
      x=i;
      break;
    }
    repn(i,n) if(i!=x) printf("%d %d\n",x,i);
  }
	return 0;
}