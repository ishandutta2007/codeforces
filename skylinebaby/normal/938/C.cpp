#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int i = 0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		if (n==0) 
		{
			printf("1 1\n");continue;
		}
		if (n%4==2||n==1||n==4) 
		{
			printf("-1\n");continue;
		}
		if (n%4==0)
		{
			n=n/4;
			int fk = 0;
			for(int i = 1;i*i<n;i++)
			{
				if (n%i!=0) continue;
				int m = n/i;
				if (m-i==(m+i)/((i+m)/(m-i)))
				{
					printf("%d %d\n",m+i,(m+i)/(m-i));
					fk=1;break;
				} 
			}
			if (fk==0) printf("-1\n");
			continue;
		}
			int fk = 0;
			for(int i = 1;i*i<n;i++)
			{
				if (n%i!=0) continue;
				int m = n/i;
				int x = (m+i)/2;
				int y = (m-i)/2;
				if (y==x/(x/y))
				{
					printf("%d %d\n",x,x/y);
					fk=1;break;
				} 
			}
			if (fk==0) printf("-1\n");
			continue;
		
	}
}