#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x;
		scanf("%d",&x);
		int t = (int)log2(x+0.5);
		int s = 1<<t;
		int flag = 0;
		if(x==2*s-1)
		{
			for(int i = 3;i*i<=x;i+=2)
			{
				if(flag) break;
				if(x%i) continue;
				else {
					printf("%d\n",x/i);
					flag = 1;
				}
			}
			if(flag) continue;
		}
		else 
		{
			printf("%d\n",2*s-1);
			continue;
		}
		printf("1\n");
	}
	return 0;
}