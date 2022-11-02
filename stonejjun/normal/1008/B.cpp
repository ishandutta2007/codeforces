#include<stdio.h>
#include<bits/stdc++.h>
int main()
{
	int a,b,c,d,i,j,k,x,y,arr[133333][2]={0,0},max=1e+9;
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		scanf("%d %d",&arr[i][1],&arr[i][2]);	
	}
	for(i=1;i<=a;i++)
	{
		if(max>=arr[i][1]&&max>=arr[i][2])
		{
			max=arr[i][1]>arr[i][2]?arr[i][1]:arr[i][2];
		}
		if(max>=arr[i][1]&&arr[i][2]>max)
		{
			max=arr[i][1];
		}
		if(max>=arr[i][2]&&arr[i][1]>max)
		{
			max=arr[i][2];
		}
		if(max<arr[i][1]&&max<arr[i][2])
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}