#include<bits/stdc++.h>
using namespace std;
int a[12345];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		for(int i = 0;i<x;i++)
		{
			int y;
			scanf("%d",&y);
			a[y]++;
		}
	}
	for(int i = 1;i<=100;i++)
	{
		if(a[i]==n)
		{
			printf("%d ",i);
		}
	}
	printf("\n");
	return 0;
}