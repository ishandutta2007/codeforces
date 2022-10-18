#include<bits/stdc++.h>
using namespace std;
int a[500];
int main()
{
	int n;
	int sum = 0;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	int need = sum/2;
	need ++;
	int ww = a[1];
	int k = 1;
	for(int i = 2;i<=n;i++)
	{
		if(a[i]*2<=a[1]) 
		{
			ww += a[i];
			k ++;
		}
	}  
	if(ww<need) 
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n1",k);
		for(int i = 2;i<=n;i++) if(a[i]*2<=a[1]) printf(" %d",i);
		printf("\n");
	}
	return 0;
}