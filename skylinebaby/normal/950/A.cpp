#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	while(c>0)
	{
		if (a<b) 
		{
			c--;a++;
		}
		else if (a>b)
		{
			c--;b++;
		}
		else if (c>=2)
		{
			c-=2;
			a++;b++;
		}
		else break;
	}
	int x  = min(a,b);
	x*=2;
	printf("%d\n",x); 
	return 0;
}