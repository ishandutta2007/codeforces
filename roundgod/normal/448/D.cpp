#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
long long k,ans,sum,m,n,i,lhy;
int main()
{
  scanf("%I64d%I64d%I64d",&m,&n,&k);
  long long bisearch( long long left,long long right, long long mid);
  long long solve(long long x);
  ans=bisearch(1,m*n,(1+m*n)/2);
  if(ans>=17) if(solve(ans-17)<k&&solve(ans-16)>=k) ans=ans-16;
  if(ans>=14) if(solve(ans-14)<k&&solve(ans-13)>=k) ans=ans-13;
  if(ans>=6) if(solve(ans-6)<k&&solve(ans-5)>=k) ans=ans-5;
  if(ans>=4) if(solve(ans-4)<k&&solve(ans-3)>=k) ans--;
  if(ans>=3) if(solve(ans-3)<k&&solve(ans-2)>=k) ans--;
  if(ans>=2) if(solve(ans-2)<k&&solve(ans-1)>=k) ans--;
   if(solve(ans)<k&&solve(ans+1)>=k) ans++;
  printf("%I64d\n",ans);
  return 0;
}
long long solve(long long x)
{
      sum=0;
      for(i=1;i<=m;i++)
      if(x/i>=n) sum=sum+n; else sum=sum+(x/i);
      return sum;
}
 long long bisearch( long long left,long long right, long long mid)
 {
     sum=0;
     if(left>=right) return mid;
     lhy=solve(mid);
    if (lhy==k) return mid;
    if (lhy<k) return bisearch(mid+1,right,(mid+right+1)/2);
    if (lhy>k) return bisearch(left,mid-1,(mid+left-1)/2);
 }