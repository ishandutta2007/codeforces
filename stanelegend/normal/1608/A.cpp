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

int t,n;

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n;
    for(int i=2;i<=n+1;++i) printf("%d ",i);puts("");
  }
	return 0;
}