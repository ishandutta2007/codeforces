#include<bits/stdc++.h>

using namespace std;

int a[6666],ans[6666];

int n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		if(i==1)
			printf("? %d %d\n",2,3);
		else
			printf("? %d %d\n",1,i);
		fflush(stdout);
		scanf("%d",&a[i]);
	}
	ans[1]=(a[1]+a[2]+a[3])/2-a[1];
	for(int i=2;i<=n;i++)
	{
		ans[i]=a[i]-ans[1];
	}
	printf("! ");
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}