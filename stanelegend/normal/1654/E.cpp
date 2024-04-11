#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")

using namespace std;

int n,a[100010],t=58,ans,nn=0;
map <int,int> mx,dp[100010];

void solve()
{
  rep(k,t+1)
  {
    mx.clear();
    int mxv=1;
    rep(i,n)
    {
      if(mx.find(a[i]-i*k)==mx.end()) mx[a[i]-i*k]=1;
      else mxv=max(mxv,++mx[a[i]-i*k]);
    }
    ans=min(ans,n-mxv);
  }
  if(nn==1) return;
  int mxv=1;
  rep(i,n) dp[i].clear();
  rep(i,n)
  {
    for(int j=max(0,i-100000/t-1);j<i;++j) if((a[i]-a[j])%(i-j)==0)
    {
      int kk=(a[i]-a[j])/(i-j);
      if(abs(kk)<=t) continue;
      int vv;
      if(dp[j].find(kk)==dp[j].end()) vv=2;
      else vv=dp[j][kk]+1;
      dp[i][kk]=max(dp[i][kk],vv);
      mxv=max(mxv,vv);
    }
  }
  ans=min(ans,n-mxv);
}

int main()
{
  //freopen("in.txt","r",stdin);
  cin>>n;
  rep(i,n) scanf("%d",&a[i]);
  ans=n-1;
  solve();
  reverse(a,a+n);nn=1;
  solve();
  cout<<ans<<endl;
  //cout<<clock();
  return 0;
}