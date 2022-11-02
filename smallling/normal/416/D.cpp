#include<stdio.h>

using namespace std;

int n,ans;
long long a[1000100],cha;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(int i=1,j,k,l;i<=n;)
	{
		ans++;
		for(j=i;j<=n&&a[j]==-1;j++);
		for(k=j+1;k<=n&&a[k]==-1;k++);
		if(k>n)break;
		if((a[k]-a[j])%(k-j))
		{
			i=k;
			continue;
		}
		cha=(a[k]-a[j])/(k-j);
		if(a[k]-cha*(k-i)<=0)
		{
			i=k;
			continue;
		}
		for(i=k+1;i<=n&&a[k]+cha*(i-k)>0&&(a[i]==-1||a[i]==a[k]+cha*(i-k));i++);
	}
	printf("%d",ans);
}