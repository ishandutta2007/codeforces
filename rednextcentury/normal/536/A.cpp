# include <iostream>
# include <vector>
# include <cstring>
#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
long long a,b;
long long l,t,m;
long long getsum(long long s,long long e)
{
    return (s-1)*b*(e-s+1)+(e-s)*(e-s+1)*b/2+(e-s+1)*a;
}
long long binsearch(long long s,long long e)
{
    long long ret=-1;
    while(s<=e)
    {
        long long mid=(s+e)/2;
        long long h=getsum(l,mid);
        long long j;
        long long k=min(m,mid-l+1);
        if (h%k==0)
            j=h/k;
        else
            j=h/k + 1;
        j=max(j,a+b*(mid-1));
        if (j<=t)
        {
            ret=mid;
            s=mid+1;
        }
        else
            e=mid-1;
    }
    return ret;
}
int main()
{
   int n;
   cin>>a>>b>>n;
   int mx=1;
   while(getsum(mx,mx)<=1000000)
        mx++;
   for (int i=0;i<n;i++)
   {
       cin>>l>>t>>m;
       cout<<binsearch(l,mx)<<endl;
   }
}