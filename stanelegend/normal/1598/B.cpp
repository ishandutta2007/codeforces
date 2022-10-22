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

int t,n,a[1010][10];

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n;
    rep(i,n) rep(j,5) scanf("%d",&a[i][j]);
    bool ok=false;
    rep(i,5) for(int j=i+1;j<5;++j)
    {
      bool b=true;
      int c=0,d=0;
      rep(k,n)
      {
        if(a[k][i]==0&&a[k][j]==0)
        {
          b=false;
          break;
        }
        if(a[k][i]==0) ++d;
        else if(a[k][j]==0) ++c;
      }
      if(c>n/2||d>n/2) b=false;
      if(b) ok=true;
    }
    puts(ok ? "YES":"NO");
  }
  return 0;
}