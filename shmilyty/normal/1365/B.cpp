#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,last,one,zero,flag;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		last=one=zero=0;
		flag=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(a<last)
				flag=0;
			last=a;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&b);
			if(b)
				one=1;
			else
				zero=1;	
		} 
		if(one&&zero)
			puts("Yes");
		else
		{
			if(flag)
				puts("Yes");
			else
				puts("No");
		}
	}
	return 0;
}