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

LL t,k,x;

int main()
{
  cin>>t;
  rep(tn,t)
  {
    scanf("%lld%lld",&k,&x);
    LL lb=1,ub=k+k-1,mid;
    while(lb<ub)
    {
      mid=(lb+ub+1)/2;--mid;
      LL num;
      if(mid<=k) num=(mid+1)*mid/2LL;
      else num=(k+1)*k/2LL+k*(k-1)/2LL-(k+k-1-mid+1)*(k+k-1-mid)/2LL;
      if(num<x) lb=mid+1;
      else ub=mid;
    }
    printf("%lld\n",lb);
  }
  return 0;
}