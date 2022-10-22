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

int t,n,a[110],dp[110][20010],lst[110][20010];
bool isp[20010];

bool isP(int x)
{
  for(int i=2;i*i<=x;++i) if(x%i==0) return false;
  return true;
}

void upd(int i,int j,int val,int l)
{
  if(val>dp[i][j])
  {
    dp[i][j]=val;
    lst[i][j]=l;
  }
}

int main()
{
  for(int i=2;i<=20000;++i) if(isP(i)) isp[i]=true;
  isp[1]=true;
  cin>>t;
  rep(tn,t)
  {
    cin>>n;
    rep(i,n) scanf("%d",&a[i]);
    rep(i,n+5) rep(j,200*n+5) dp[i][j]=lst[i][j]=-1;
    dp[0][0]=0;
    rep(i,n) rep(j,200*n+2) if(dp[i][j]>-1)
    {
      upd(i+1,j,dp[i][j],j);
      upd(i+1,j+a[i],dp[i][j]+1,j);
    }
    pii val=mpr(-1e9,0);
    repn(i,200*n+3) if(!isp[i]) val=max(val,mpr(dp[n][i],i));
    cout<<val.fi<<endl;
    int ii=n,jj=val.se;
    while(ii>0)
    {
      if(lst[ii][jj]!=jj) printf("%d ",ii);
      jj=lst[ii][jj];--ii;
    }
    puts("");
  }
	return 0;
}