#include<cstdio>

using namespace std;

int i,j,a[1001],b[1001],o,p,n,bb,bo[10];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	bo[1]=1;
	bo[2]=2;
	for(i=1;i<=n;i++)
	{
		if(a[i]==0)b[++o]=a[i],bo[1]=1,bo[2]=1;
		if(a[i]==100)b[++o]=a[i],bo[1]=1,bo[2]=1;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]%10==0&&a[i]>9&&a[i]<100&&bo[2])b[++o]=a[i],bo[1]=1,bo[2]=0;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]>=1&&a[i]<=9&&bo[1])b[++o]=a[i],bo[1]=0;
		if(a[i]%10==0&&a[i]>=10&&a[i]<100&&bo[2])b[++o]=a[i],bo[2]=0;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]%10!=0&&(a[i]/10)%10!=0&&bo[1]&&bo[2])b[++o]=a[i],bo[1]=0,bo[2]=0;
	}
	if(o==0)o=1,b[1]=a[1];
	printf("%d\n",o);
	for(i=1;i<=o;i++)
	printf("%d ",b[i]);
}