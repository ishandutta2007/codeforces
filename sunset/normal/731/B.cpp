#include<bits/stdc++.h>

using namespace std;

int n;

int x;

int flag;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x&1)
			flag^=1;
		else
		{
			if((!x)&&(flag))
			{
				printf("NO");
				return 0;
			}
		}		
	}
	if(flag)
		printf("NO");
	else
		printf("YES");
	return 0;
}