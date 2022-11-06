#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1001],n;
int sign,sum;
int main(){
scanf("%d",&n);
for(int i=1;i<2*n;++i)
{
scanf("%d",a+i);
if(a[i]<0) sign^=1,a[i]=-a[i];
sum+=a[i];
}
sort(a+1,a+2*n);
if((n&1)||(~sign&1)) printf("%d\n",sum);
else printf("%d\n",sum-2*a[1]);
return 0;
}