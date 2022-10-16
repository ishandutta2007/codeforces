#include<bits/stdc++.h>//1
using namespace std;
int t,n,m;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		if(n==1||m==1)
		{
			puts("Yes");
			continue;
		}
		if(n==2&&m==2)
		{
			puts("Yes");
			continue;
		}
		puts("No");
	}
	return 0;
}