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

int n,m,q,dp[200010][560];
vector <int> v[200010];
bitset <560> can[200010];

void chmax(int &x,int y){if(x<y) x=y;}
void chmin(int &x,int y){if(x>y) x=y;}

int main()
{
  bool swp=false;
  cin>>n>>m>>q;
  if(n<m) swap(n,m),swp=true;
  int x,y;
  rep(qn,q)
  {
    scanf("%d%d",&x,&y);--x;--y;if(swp) swap(x,y);
    if(m<=550) can[x][y]=1;
    else v[x].pb(y);
  }
  if(m>550)
  {
    rep(i,n) sort(v[i].begin(),v[i].end());
    rep(i,n+3) rep(j,390) dp[i][j]=-1;
    dp[0][0]=0;
    rep(i,n)
    {
      int cur=0;
      rep(j,380) if(dp[i][j]>-1)
      {
        while(cur+1<v[i].size()&&v[i][cur+1]<=dp[i][j]) ++cur;
        int sum=i+1+dp[i][j]+1+(cur<v[i].size()&&v[i][cur]==dp[i][j] ? 1:0);
        //2
        chmax(dp[i][j+1],min(sum-1,m-1));
        //1
        chmax(dp[min(n-1,sum-1)][j+1],dp[i][j]);
      }
    }
    rep(j,378) if(dp[n-1][j]>=m-1)
    {
      cout<<j<<endl;
      return 0;
    }
  }
  //else
  {
    rep(i,n+3) rep(j,m+3) dp[i][j]=1e9;
    dp[0][0]=0;
    rep(i,n) rep(j,m) if(dp[i][j]<1e9)
    {
      int sum=i+1+j+1+can[i][j];
      chmin(dp[min(n-1,sum-1)][j],dp[i][j]+1);
      chmin(dp[i][min(m-1,sum-1)],dp[i][j]+1);
    }
    cout<<dp[n-1][m-1]<<endl;
  }
  return 0;
}