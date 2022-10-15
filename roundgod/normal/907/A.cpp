#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=a;i<=200;i++)
		for(int j=b;j<i;j++)
			for(int k=c;k<j;k++)
			{
				if(2*a>=i&&2*b>=j&&2*c>=k&&d<=i&&d<=j&&d<=k&&2*d>=k&&2*d<i&&2*d<j)
				{
					printf("%d\n%d\n%d\n",i,j,k);
					return 0;
				}
			}
	puts("-1");
	return 0;
}