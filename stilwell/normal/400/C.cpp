#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,x,y,z,p,i,j,k,tmp;
int a[100005],b[100005];

int main()
{
	scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&z,&p);
	for(i=1;i<=p;++i)scanf("%d%d",&a[i],&b[i]);
	for(i=x%4;i;--i,swap(n,m))
	for(j=1;j<=p;++j)
	tmp=a[j],a[j]=b[j],b[j]=n-tmp+1;
	for(i=y%2;i;--i)
	for(j=1;j<=p;++j)
	b[j]=m-b[j]+1;
	for(i=z%4;i;--i,swap(n,m))
	for(j=1;j<=p;++j)
	tmp=a[j],a[j]=m-b[j]+1,b[j]=tmp;
	for(i=1;i<=p;++i)printf("%d %d\n",a[i],b[i]);
}