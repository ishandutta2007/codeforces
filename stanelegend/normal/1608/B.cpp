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

int t,n,a,b;

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n>>a>>b;
    if(abs(a-b)>1||a+b>n-2) puts("-1");
    else
    {
      if(a==b)
      {
        int lb=1,ub=(a+1)*2;
        rep(i,a+1) printf("%d %d ",lb++,ub--);
        for(int i=(a+1)*2+1;i<=n;++i) printf("%d ",i);
      }
      else
      {
        int rev=0;
        if(b==a+1) rev=1,++a;
        int lb=n-a-a+1,ub=n;
        rep(i,a) printf("%d %d ",(rev==0 ? lb++:n-(lb++)+1),(rev==0 ? ub--:n-(ub--)+1));
        for(int i=n-a-a;i>0;--i) printf("%d ",(rev==0 ? i:n-i+1));
      }
      puts("");
    }
  }
	return 0;
}