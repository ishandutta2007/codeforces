#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main()
{
int h[100002],a[100002],n,i,maxi;
scanf("%d",&n);
memset(a,0,sizeof(a));
for(i=1;i<=n;i++)
{
scanf("%d",&h[i]);
a[i]=h[i];
}
for(i=1;i<=n;i++)
a[i]=min(h[i],min(a[i-1]+1,a[i+1]+1));
for(i=n;i>=1;i--)
a[i]=min(h[i],min(a[i-1]+1,a[i+1]+1));
maxi=0;
for(i=1;i<=n;i++)
maxi=max(maxi,a[i]);
printf("%d",maxi);
return 0;
}