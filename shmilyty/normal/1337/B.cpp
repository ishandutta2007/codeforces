#include<bits/stdc++.h>
using namespace std;
int t,n,a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&b,&a);
		if(n<20)
		{
			if(n<=a*10)
				puts("Yes");
			else
				puts("No");
			continue;
		}
		while(b--)
			n=(n/2)+10;
		if(n<=a*10)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}