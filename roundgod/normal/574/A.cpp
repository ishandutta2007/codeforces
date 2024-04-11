#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
int n,i,a[105],t,j,sb,ct;
using namespace std;
int main()
{
scanf("%d",&n);
scanf("%d",&t);
j=0;
for(i=1;i<=n-1;i++)
  {
      scanf("%d",&sb);
      if(sb>=t)
      {
          a[j]=sb;
          j++;
      }
  }
sort(a,a+j);
ct=0;
while(a[j-1]>=t)
{
    t++;
    a[j-1]--;
    ct++;
    sort(a,a+j);
}
printf("%d",ct);
return 0;
}