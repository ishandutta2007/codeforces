#include<bits/stdc++.h>
using namespace std;

int arr[50];
int gop[2000000][20];

int main()
{
	int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z; // 
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	for(i=1;i<=100000;i++)
	{
		k=i;
		z=0;
		while(k!=0)
		{
			z++;
			gop[i][z]=k%2;
			k/=2;
		}
	}
	
	for(i=1;i<=100000;i++)
	{
		int ans=360000000;
		for(j=1;j<=17;j++)
		{
			if(gop[i][j]==1) ans+=arr[j];
			else ans-=arr[j];
		}
		if(ans%360==0)
		{
			printf("YES");
			return 0;
		}
	}
	
	printf("NO");
	
	
}