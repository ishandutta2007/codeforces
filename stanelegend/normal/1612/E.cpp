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

int n,m[200010],k[200010],cnt[200010],dp[200010][30],lst[200010][30];
vector <pii> v;
vector <int> vals[200010],ans;
vector <int> res[30];
vector <double> opts;

void chmax(int i,int j,int val,int lj)
{
  if(dp[i][j]<val)
  {
    dp[i][j]=val;
    lst[i][j]=lj;
  }
}

int main()
{
  cin>>n;
  rep(i,n)
  {
    scanf("%d%d",&m[i],&k[i]);--m[i];
    cnt[m[i]]+=k[i];vals[m[i]].pb(k[i]);
  }
  rep(i,200000) v.pb(mpr(cnt[i],i));
  sort(v.begin(),v.end());reverse(v.begin(),v.end());
  int sz=0;
  double sum=0,opt=0;
  rep(i,v.size())
  {
    sum+=v[i].fi;
    if(i+1>=20&&sum/(double)(i+1)>opt) opt=sum/(double)(i+1),sz=i+1;
  }
  repn(tot,19)
  {
    rep(i,200005) rep(j,tot+3) dp[i][j]=-1e9;
    dp[0][0]=0;
    rep(i,200000) rep(j,tot+1) if(dp[i][j]>-1e9)
    {
      int add=0;
      rep(p,vals[i].size()) add+=min(tot,vals[i][p]);
      chmax(i+1,j,dp[i][j],j);chmax(i+1,j+1,dp[i][j]+add,j);
    }
    int ii=200000,jj=tot;opts.pb((double)dp[ii][jj]/(double)tot);
    while(ii>0)
    {
      if(lst[ii][jj]<jj) res[tot-1].pb(ii-1);
      //if(tot==1&&lst[ii][jj]!=jj) cout<<ii<<' '<<jj<<' '<<lst[ii][jj]<<"fjaklsdjlkfalsdfjasldkj\n";
      jj=lst[ii][jj];--ii;
    }
    //if(tot==1) cout<<res[tot].size()<<"fjaklsd\n";
  }
  if(sz>19)
  {
    opts.pb(opt);
    rep(i,sz) res[opts.size()-1].pb(v[i].se);
  }
  double mx=-1;
  rep(i,opts.size()) if(opts[i]>mx)
  {
   // cout<<i<<' '<<opts[i]<<' '<<mx<<endl;
    mx=opts[i];
    ans=res[i];
  }
  cout<<ans.size()<<endl;
  rep(i,ans.size()) printf("%d ",ans[i]+1);puts("");
  return 0;
}