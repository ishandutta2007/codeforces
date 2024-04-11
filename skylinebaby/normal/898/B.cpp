#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	for(int i = 0;i*b<=n;i++)
	{
		if ((n-i*b)%a==0) 
		{
			printf("YES\n%d %d\n",(n-i*b)/a,i);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}