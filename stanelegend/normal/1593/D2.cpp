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

int t,n,a[50],cnt[2000010],b[50];

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n;
    int mn=1e9;
    rep(i,n) scanf("%d",&a[i]),mn=min(mn,a[i]);
    rep(i,n) a[i]-=mn;
    int mx=-1e9;
    rep(i,n) mx=max(mx,a[i]);
    int need=n/2;
    for(int i=mx+1;i>0;--i)
    {
      bool ok=false;
      rep(j,n)
      {
        b[j]=a[j]%i;
        ++cnt[b[j]];
        if(cnt[b[j]]>=need) ok=true;
      }
      rep(j,n) --cnt[b[j]];
      if(ok)
      {
        if(i==mx+1) puts("-1");
        else printf("%d\n",i);
        break;
      }
    }
  }
	return 0;
}