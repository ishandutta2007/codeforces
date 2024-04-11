#include<stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	int n,i,k[53],sum1=0,sum2=0,j=0;
	scanf("%d",&n);
	for(i=0;i<n/2;i++)
	{
		scanf("%d",&k[i]);
	}
	sort(k,k+n/2);
	for(i=1;i<n;i++)
	{
		if(i<k[j])
		{
			sum1=sum1+k[j]-i;
		}
		else
		{
			sum1=sum1+i-k[j];
		}
		i++;
		if(i<k[j])
		{
			sum2=sum2+k[j]-i;
		}
		else
		{
			sum2=sum2+i-k[j];
		}
		j++;
	} 	
	
	printf("%d",sum1<sum2?sum1:sum2);
}