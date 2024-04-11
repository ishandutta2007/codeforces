#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[6];
	for(int i = 0;i<6;i++)
	{
		scanf("%d",&a[i]);
	}
	if (a[3]==0)
	{
		printf("Hermione\n");
		return 0;
	} 
	if (a[2]==0)
	{
		printf("Ron\n");
		return 0;
	}
	if (a[1]==0)
	{
		printf("Hermione\n");
		return 0;
	} 
	if (a[0]==0)
	{
		printf("Ron\n");
		return 0;
	} 
	if (a[0]*a[2]*a[4]>=a[1]*a[3]*a[5])
	{
		printf("Hermione\n");
	}
	else printf("Ron\n");
	return 0; 
}