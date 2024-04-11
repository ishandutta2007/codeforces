#include<stdio.h>
#include<bits/stdc++.h>

struct poi{
	int sero;
	int garo;
};

poi arr[111111];

int main()
{
	unsigned long long int n,q,i,j,k,sum,x,y;
	scanf("%lld %lld",&n,&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d %d",&arr[i].sero,&arr[i].garo);
	}
	
	for(i=1;i<=q;i++)
	{
		sum=0;
		x=arr[i].sero>arr[i].garo?arr[i].sero:arr[i].garo;
		y=arr[i].sero<arr[i].garo?arr[i].sero:arr[i].garo;
	
		if((x-y)%2)
		{
			sum+=((n*n+1)/2);
			sum+=((arr[i].sero-1)/2)*n;
	
		}
		else
		{
			
			sum+=((arr[i].sero-1)/2)*n;

		}
		
		if(n%2)
		{
			if(arr[i].sero%2)
			{
				sum+=((arr[i].garo+1)/2);
	
			}
			else
			{
				sum+=((n+1)/2);
				sum+=((arr[i].garo)/2);
		
			}
		}
		else
		{
			if(arr[i].sero%2)
			{
				sum+=((arr[i].garo+1)/2);
			}
			else
			{
				sum+=(n/2);
				
				sum+=(((arr[i].garo)+1)/2);
				
			}
		}
		printf("%lld\n",sum);
		
	}
	
}